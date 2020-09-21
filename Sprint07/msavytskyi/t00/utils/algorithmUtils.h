#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

namespace Utils
{
    // [from, to]
    template <typename T>
    bool IsInRange(const T &val, const T &from, const T &to)
    {
        return (from <= val) && (val <= to);
    }

    template <typename T>
    bool IsInRange(const T &val, const std::pair<const T &, const T &> &minmax)
    {
        return (minmax.first <= val) && (val <= minmax.second);
    }

    // (from, to)
    template <typename T>
    bool IsInsideRange(const T &val, const T &from, const T &to)
    {
        return (from < val) && (val < to);
    }

    template <typename T>
    bool IsInsideRange(const T &val, const std::pair<const T &, const T &> &minmax)
    {
        return (minmax.first < val) && (val < minmax.second);
    }

    // change the object if necessary
    // and return the corresponding value of the operation success
    template <class T, class U = T>
    bool Modify(T &obj, U &&new_value)
    {
        if (obj == new_value)
        {
            return false;
        }
        obj = new_value;
        return true;
    }

    template <class Collection, class T>
    void RemoveAll(Collection &c, const T &value)
    {
        auto it = std::remove(c.begin(), c.end(), value);
        Collection new_front(std::distance(c.begin(), it));
        Collection new_back(std::distance(it, c.end()));
        std::move(c.begin(), it, new_front.begin());
        std::move(it, c.end(), new_back.begin());
        c = /*std::move(*/ new_front /*)*/;
    }

    template <class Collection, class Pred>
    void RemoveAllIf(Collection &c, Pred &&predicate)
    {
        auto it = std::remove_if(c.begin(), c.end(), predicate);
        Collection new_front(std::distance(c.begin(), it));
        Collection new_back(std::distance(it, c.end()));
        std::move(c.begin(), it, new_front.begin());
        std::move(it, c.end(), new_back.begin());
        c = /*std::move(*/ new_front /*)*/;
    }

    template <class Collection, class T>
    auto Find(Collection &c, const T &value)
    {
        return std::find(c.begin(), c.end(), value);
    }

    template <class Collection, class Pred>
    auto FindIf(Collection &c, Pred &&predicate)
    {
        return std::find_if(c.begin(), c.end(), predicate);
    }

    template <class Collection, class T>
    bool Contains(const Collection &c, const T &value)
    {
        return (std::count(c.begin(), c.end(), value) != 0);
    }

    template <class Collection, class Pred>
    bool ContainsIf(const Collection &c, Pred &&predicate)
    {
        return (std::count_if(c.begin(), c.end(), predicate) != 0);
    }

    template <class Collection, class Pred>
    int CountIf(const Collection &c, Pred &&predicate)
    {
        return std::count_if(c.begin(), c.end(), predicate);
    }

    template <class T, class... Args>
    const auto &Min(const T &arg, const Args &... args)
    {
        std::vector<T> v{arg, args...};
        return *std::min_element(v.begin(), v.end());
    }

    template <class T, class... Args>
    const auto &Max(const T &arg, const Args &... args)
    {
        std::vector<T> v{arg, args...};
        return *std::max_element(v.begin(), v.end());
    }

    template <class Collection>
    auto MaxElement(const Collection &c)
    {
        return std::max_element(c.begin(), c.end());
    }

    template <class Collection>
    auto MinElement(const Collection &c)
    {
        return std::min_element(c.begin(), c.end());
    }

    template <class Collection, class Comp>
    auto MaxElement(const Collection &c, Comp &&comparator)
    {
        return std::max_element(c.begin(), c.end(), comparator);
    }

    template <class Collection, class Comp>
    auto MinElement(const Collection &c, Comp &&comparator)
    {
        return std::min_element(c.begin(), c.end(), comparator);
    }

    template <class Collection>
    void Sort(Collection &c)
    {
        std::sort(c.begin(), c.end());
    }

    template <class Collection, class Comp>
    void Sort(Collection &c, Comp &&comparator)
    {
        std::sort(c.begin(), c.end(), comparator);
    }

    // remove all not unique elements in collection
    template <class Collection>
    void Unique(Collection &c)
    {
        auto it = std::unique(c.begin(), c.end());
        Collection new_front(std::distance(c.begin(), it));
        Collection new_back(std::distance(it, c.end()));
        std::move(c.begin(), it, new_front.begin());
        std::move(it, c.end(), new_back.begin());
        c = /*std::move(*/ new_front /*)*/;
    }

    template <class Collection, class Pred>
    void Unique(Collection &c, Pred &&predicate)
    {
        auto it = std::unique(c.begin(), c.end(), predicate);
        Collection new_front(std::distance(c.begin(), it));
        Collection new_back(std::distance(it, c.end()));
        std::move(c.begin(), it, new_front.begin());
        std::move(it, c.end(), new_back.begin());
        c = /*std::move(*/ new_front /*)*/;
    }

    template <class Collection, class Pred>
    void ForEach(Collection &c, Pred &&predicate)
    {
        std::for_each(c.begin(), c.end(), predicate);
    }

    template <class Collection, class T>
    int IndexOf(const Collection &c, const T &value)
    {
        return std::distance(c.begin(), std::find(c.begin(), c.end(), value));
    }

    template <class Collection, class Pred>
    int IndexOfIf(const Collection &c, Pred &&predicate)
    {
        return std::distance(c.begin(), std::find_if(c.begin(), c.end(), predicate));
    }
} // namespace Utils
