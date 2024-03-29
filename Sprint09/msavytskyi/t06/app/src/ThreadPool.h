#pragma once

#include <thread>
#include <queue>
#include <vector>
#include <mutex>
#include <future>
#include <iostream>

// class ThreadPool final
// {
// public:
//     explicit ThreadPool(size_t threads);
//     ~ThreadPool();
//     ThreadPool(const ThreadPool &) = delete;
//     ThreadPool(const ThreadPool &&) = delete;
//     ThreadPool &operator=(const ThreadPool &) = delete;
//     template <typename Function, class... Args>
//     auto enqueueTask(Function &&func, Args &&... args);

// private:
//     std::vector<std::thread> m_workerThreads;
//     std::queue<std::packaged_task<void()>> m_taskQueue;
//     std::condition_variable m_condVar;
//     std::mutex m_queueMutex;
//     bool m_isRunning{true};
// };
// /* main.cpp */
// int compute_ackermann(int m, int n)
// {
//     if (m == 0)
//     {
//         return n + 1;
//     }
//     else if (m > 0 && n == 0)
//     {
//         return compute_ackermann(m - 1, 1);
//     }
//     else if (m > 0 && n > 0)
//     {
//         return compute_ackermann(m - 1, compute_ackermann(m, n - 1));
//     }
//     return -1;
// }

class ThreadPool final
{
public:
    explicit ThreadPool(size_t threads)
    {
        for (int i = 0; i < threads; ++i)
        {
            m_workerThreads.emplace_back(std::thread(&ThreadPool::run, this));
        }
    }
    ~ThreadPool()
    {
        m_isRunning = false;
        m_condVar.notify_all();
        for (auto &thr : m_workerThreads)
        {
            if (thr.joinable())
                thr.join();
        }
    }

    ThreadPool(const ThreadPool &) = delete;
    ThreadPool(const ThreadPool &&) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;

    template <typename Function, class... Args>
    auto enqueueTask(Function &&func, Args &&... args)
    {
        // std::lock_guard<std::mutex> lock(m_queueMutex);
        auto f = std::bind(std::forward<Function>(func), std::forward<Args>(args)...);
        auto task = std::make_shared<std::packaged_task<typename std::result_of<Function(Args...)>::type()>>(f);
        auto ft = task->get_future();
        m_queueMutex.lock();
        m_taskQueue.emplace([task]() { (*task)(); });
        m_queueMutex.unlock();
        m_condVar.notify_one();
        return ft;
    }

private:
    void run()
    {
        std::packaged_task<void()> task;
        while (true)
        {
            {
                std::unique_lock<std::mutex> lock(m_queueMutex);
                m_condVar.wait(lock, [this]() { return !this->m_isRunning || !m_taskQueue.empty(); });
                if (!m_isRunning && m_taskQueue.empty())
                    return;
                task = std::move(m_taskQueue.front());
                m_taskQueue.pop();
            }
            task();
        }
    }
    std::vector<std::thread> m_workerThreads;
    std::queue<std::packaged_task<void()>> m_taskQueue;
    std::condition_variable m_condVar;
    std::mutex m_queueMutex;
    bool m_isRunning{true};
};

/*struct tasks
{
    // the mutex, condition variable and deque form a single
    // thread-safe triggered queue of tasks:
    std::mutex m;
    std::condition_variable v;
    // note that a packaged_task<void> can store a packaged_task<R>:
    std::deque<std::packaged_task<void()>> work;

    // this holds futures representing the worker threads being done:
    std::vector<std::future<void>> finished;

    // queue( lambda ) will enqueue the lambda into the tasks for the threads
    // to use.  A future of the type the lambda returns is given to let you get
    // the result out.
    template <class F, class R = std::result_of_t<F &()>>
    std::future<R> queue(F &&f)
    {
        // wrap the function object into a packaged task, splitting
        // execution from the return value:
        std::packaged_task<R()> p(std::forward<F>(f));

        auto r = p.get_future(); // get the return value before we hand off the task
        {
            std::unique_lock<std::mutex> l(m);
            work.emplace_back(std::move(p)); // store the task<R()> as a task<void()>
        }
        v.notify_one(); // wake a thread to work on the task

        return r; // return the future result of the task
    }

    // start N threads in the thread pool.
    void start(std::size_t N = 1)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            // each thread is a std::async running this->thread_task():
            finished.push_back(
                std::async(
                    std::launch::async,
                    [this] { thread_task(); }));
        }
    }
    // abort() cancels all non-started tasks, and tells every working thread
    // stop running, and waits for them to finish up.
    void abort()
    {
        cancel_pending();
        finish();
    }
    // cancel_pending() merely cancels all non-started tasks:
    void cancel_pending()
    {
        std::unique_lock<std::mutex> l(m);
        work.clear();
    }
    // finish enques a "stop the thread" message for every thread, then waits for them:
    void finish()
    {
        {
            std::unique_lock<std::mutex> l(m);
            for (auto &&unused : finished)
            {
                work.push_back({});
            }
        }
        v.notify_all();
        finished.clear();
    }
    ~tasks()
    {
        finish();
    }

private:
    // the work that a worker thread does:
    void thread_task()
    {
        while (true)
        {
            // pop a task off the queue:
            std::packaged_task<void()> f;
            {
                // usual thread-safe queue code:
                std::unique_lock<std::mutex> l(m);
                if (work.empty())
                {
                    v.wait(l, [&] { return !work.empty(); });
                }
                f = std::move(work.front());
                work.pop_front();
            }
            // if the task is invalid, it means we are asked to abort:
            if (!f.valid())
                return;
            // otherwise, run the task:
            f();
        }
    }
};*/
