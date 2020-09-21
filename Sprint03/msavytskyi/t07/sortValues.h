#pragma once
#include <algorithm>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end)
{
    auto bg = begin;
    int range_length = end - begin;
    if (range_length < 2)
    {
        return bg;
    }
    std::vector<typename RandomAccessIterator::value_type> elements(begin, end);
    auto mid = elements.begin() + range_length / 2;
    sortValues(elements.begin(), mid);
    sortValues(mid, elements.end());
    std::merge(elements.begin(), mid, mid, elements.end(), begin);
    return bg;
}
