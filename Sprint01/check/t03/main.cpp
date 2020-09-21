#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <algorithm>
#include <chrono>
#include <thread>

#define cout std::cout
#define endl std::endl
#define cerr std::cerr
#define string std::string

enum class Gender
{
    Male,
    Female
};

struct Rabbit
{
    Gender gender;
    bool isVampire;
    int age;

    Rabbit(Gender gender_, bool isVampire_, int age_) : gender(gender_), isVampire(isVampire_), age(age_) {}
    bool TimeToDie()
    {
        return (!isVampire && age == 4) || (isVampire && age == 8);
    }
};

class Ferma
{
    std::list<Rabbit> ferma;
    size_t ferma_size = 0;

    bool RandVampire()
    {
        auto i = rand() % 100 + 1;
        return i == 63;
    }
    Gender RandGender()
    {
        auto i = rand() % 100 + 1;
        return i % 2 == 0 ? Gender::Female : Gender::Male;
    }

    size_t GetCountMales()
    {
        return std::count_if(ferma.begin(), ferma.end(), [](const Rabbit &rb) { return rb.gender == Gender::Male; });
    }

    std::pair<size_t, size_t> GetCountRabbitsIsNotVampire()
    {
        size_t male = 0;
        size_t female = 0;
        for (const auto &rabbit : ferma)
        {
            if (!rabbit.isVampire)
            {
                if (rabbit.gender == Gender::Male)
                    male++;
                else
                    female++;
            }
        }
        return {male, female};
    }

    size_t GetCountVampire()
    {
        return std::count_if(ferma.begin(), ferma.end(), [](const Rabbit &rb) { return rb.isVampire; });
    }

    void CreateRabbits(size_t size = 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            ferma.push_back(Rabbit(RandGender(), RandVampire(), -1));
            ferma_size++;
        }
    }

public:
    Ferma()
    {
        CreateRabbits(10);
    }
    size_t Size()
    {
        return ferma_size;
    }
    void Birth()
    {
        std::pair<size_t, size_t> gender_size = GetCountRabbitsIsNotVampire();
        size_t children = std::min(gender_size.first, gender_size.second);
        CreateRabbits(children);
    }
    void Bite()
    {
        size_t vampire = GetCountVampire();
        auto it = ferma.begin();
        for (size_t i = 0; i < vampire; i++)
        {
            // size_t index = rand() % ferma_size;
            // auto it = ferma.begin(;
            while (it->isVampire && it != ferma.end())
            {
                it++;
            }
            it->isVampire = true;
        }
    }
    void UpAge()
    {
        auto death = ferma.end();
        for (auto it = ferma.begin(); it != ferma.end(); it++)
        {
            if (death != ferma.end())
            {
                ferma.erase(death);
                ferma_size--;
                death = ferma.end();
            }
            it->age++;
            if (it->TimeToDie())
                death = it;
        }
        if (death != ferma.end())
        {
            ferma.erase(death);
            ferma_size--;
            death = ferma.end();
        }
    }
    void PrintStatistics()
    {
        size_t males = GetCountMales();
        size_t females = ferma_size - males;
        size_t vampire = GetCountVampire();

        cout << "Males: " << males << '\n'
             << "Females: " << females << '\n'
             << "Vampires: " << vampire << endl;
    }
};

void Update(Ferma &fr)
{
    fr.Birth();
    fr.Bite();
    fr.UpAge();
}

int main()
{
    srand(time(0));
    Ferma fr;
    fr.UpAge();
    fr.PrintStatistics();
    cout << endl;
    while (fr.Size() > 0 && fr.Size() < 1000)
    {
        Update(fr);
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
        fr.PrintStatistics();
        cout << endl;
    }
}
