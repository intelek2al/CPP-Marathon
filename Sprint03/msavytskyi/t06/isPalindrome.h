#pragma once
#include <iostream>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end)
{
    size_t counter = std::distance(begin, end) / 2;
    for (auto front = begin, back = end - 1; front != back && counter > 0; back--, front++, counter--)
    {
        if (*front != *back)
            return false;
    }
    return true;
}
