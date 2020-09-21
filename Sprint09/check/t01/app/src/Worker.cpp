#include "Worker.h"

// Worker::~Worker()
// {
//     if (m_thread != nullptr)
//         try
//         {
//             delete m_thread;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
// }

// template <typename Function, class... Args>
// void Worker::startWorker(Function &&func, Args &&... args)
// {
//     m_thread = new std::thread(func, args...);
// }

// void Worker::joinThread()
// {
//     m_thread->join();
//     delete m_thread;
//     m_thread = nullptr;
// }
