#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iterator>

namespace CBL
{
    template <class T>
    class BasicString
    {
    public:
        using iterator = T *;

        static const size_t npos = -1ul;

        BasicString() : m_buffer((T *)malloc(sizeof(T)))
        {
            m_buffer[0] = '\0';
        }

        BasicString(const BasicString<T> &str) : m_buffer((T *)malloc(sizeof(T) * (str.m_size + 1))), m_size(str.m_size)
        {
            std::copy(str.begin(), str.end(), begin());
            m_buffer[str.m_size] = '\0';
        }

        BasicString(const BasicString<T> &str, size_t pos, size_t len = npos) : m_size(len != npos ? std::min(str.m_size - pos, len) : str.m_size - pos)
        {
            m_buffer = (T *)malloc(sizeof(T) * (m_size + 1));
            std::copy(str.m_buffer + pos, str.m_buffer + pos + m_size, m_buffer);
            m_buffer[m_size] = '\0';
        }

        explicit BasicString(const T *str) : m_size(std::char_traits<T>::length(str))
        {
            m_buffer = (T *)malloc(sizeof(T) * (m_size + 1));
            m_buffer[m_size] = '\0';
            std::copy(str, str + m_size, m_buffer);
        }

        BasicString(const T *str, size_t n) : m_size(std::min(std::char_traits<T>::length(str), n))
        {
            m_buffer = (T *)malloc(sizeof(T) * (m_size + 1));
            m_buffer[m_size] = '\0';
            std::char_traits<T>::copy(m_buffer, str, n);
        }

        BasicString(size_t n, T c)
        {
            m_buffer = (T *)malloc(sizeof(T) * (n + 1));
            m_buffer[n] = '\0';
            m_size = n;
            std::fill(m_buffer, (m_buffer + n), c);
        }

        BasicString(iterator first, iterator last) : m_buffer((T *)malloc(sizeof(T) * (last - first + 1)))
        {
            m_size = last - first;
            for (int i = 0; first != last; ++first, ++i)
            {
                m_buffer[i] = *first;
            }
        }

        virtual ~BasicString()
        {
            free(m_buffer);
            m_size = 0;
        }

        // iterators

        iterator begin() const
        {
            return m_buffer;
        }

        iterator end() const
        {
            return m_buffer + m_size;
        }

        // capacity

        size_t length() const
        {
            return m_size;
        }

        // element access

        T &operator[](size_t index) const
        {
            return m_buffer[index];
        }

        T &at(size_t index) const
        {
            if (index >= m_size)
                throw std::out_of_range("Out of range");
            return m_buffer[index];
        }

        T &back() const
        {
            return operator[](m_size - 1);
        }

        T &front() const
        {
            return operator[](0);
        }

        // modifiers

        BasicString<T> &operator=(const BasicString<T> &str)
        {
            free(m_buffer);
            m_size = str.m_size;
            m_buffer = (T *)malloc(sizeof(T) * (m_size + 1));
            std::copy(str.begin(), str.end(), m_buffer);
            m_buffer[m_size] = '\0';

            return *this;
        }

        BasicString<T> &operator=(const T *str)
        {
            return operator=(BasicString<T>{str});
        }

        BasicString<T> &operator=(const T c)
        {
            return operator=(BasicString<T>{1, c});
        }

        BasicString<T> &operator+=(const BasicString<T> &str)
        {

            append(str);
            return *this;
        }

        BasicString<T> &operator+=(const T *str)
        {
            append(str);
            return *this;
        }

        BasicString<T> &operator+=(const T c)
        {
            append(1, c);
            return *this;
        }

        void append(const BasicString<T> &str)
        {
            T *new_str = (T *)malloc(sizeof(T) * (m_size + str.length() + 1));
            std::copy(begin(), end(), new_str);
            std::copy(str.begin(), str.end(), new_str + m_size);
            new_str[m_size + str.length()] = '\0';
            free(m_buffer);
            m_buffer = new_str;
            m_size += str.length();
        }

        void append(const T *str)
        {
            append(BasicString<T>{str});
        }

        void append(const T *str, size_t n)
        {
            append(BasicString<T>{strndup(str, n)});
        }

        void append(size_t n, T c)
        {
            append(BasicString<T>{n, c});
        }

        void append(iterator first, iterator last)
        {
            append(BasicString<T>{first, last});
        }

        void swap(BasicString<T> &str)
        {
            std::swap(str.m_buffer, m_buffer);
            std::swap(str.m_size, m_size);
        }

        // string operations

        const T *c_str() const
        {
            return m_buffer;
        }

        virtual int compare(const BasicString<T> &str) const
        {
            size_t lhs_sz = m_size;
            size_t rhs_sz = str.m_size;
            int result = std::char_traits<T>::compare(m_buffer, str.m_buffer, std::min(lhs_sz, rhs_sz));
            if (result != 0)
                return result;
            if (lhs_sz < rhs_sz)
                return -1;
            if (lhs_sz > rhs_sz)
                return 1;
            return 0;
        }

        virtual int compare(const T *str) const
        {
            return compare(BasicString<T>{str});
        }

    protected:
        size_t m_size{0};
        T *m_buffer{nullptr};
    };
} // end namespace CBL

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    CBL::BasicString<T> new_str(lhs);
    new_str += rhs;
    return new_str;
}

template <class T>
CBL::BasicString<T> operator+(const T *lhs, const CBL::BasicString<T> &rhs)
{
    return operator+(CBL::BasicString<T>{lhs}, rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T> &lhs, const T *rhs)
{
    return operator+(lhs, CBL::BasicString<T>{rhs});
}

template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T> &rhs)
{
    return operator+(CBL::BasicString<T>(1, lhs), rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T> &lhs, const T rhs)
{
    return operator+(lhs, CBL::BasicString<T>(1, rhs));
}

template <class T>
bool operator==(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    if (lhs.length() != rhs.length())
        return false;
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator==(const T *lhs, const CBL::BasicString<T> &rhs)
{
    CBL::BasicString<T> _lhs{lhs};
    return operator==(_lhs, rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T> &lhs, const T *rhs)
{
    CBL::BasicString<T> _rhs{rhs};
    return operator==(lhs, _rhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const T *lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T> &lhs, const T *rhs)
{
    return !(lhs == rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator<(const T *lhs, const CBL::BasicString<T> &rhs)
{
    CBL::BasicString<T> _lhs{lhs};
    return _lhs < rhs;
}

template <class T>
bool operator<(const CBL::BasicString<T> &lhs, const T *rhs)
{
    CBL::BasicString<T> _rhs{rhs};
    return lhs < _rhs;
}

template <class T>
bool operator<=(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator<=(const T *lhs, const CBL::BasicString<T> &rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator<=(const CBL::BasicString<T> &lhs, const T *rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs < rhs) && (lhs != rhs);
}

template <class T>
bool operator>(const T *lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs < rhs) && (lhs != rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T> &lhs, const T *rhs)
{
    return !(lhs < rhs) && (lhs != rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T> &lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const T *lhs, const CBL::BasicString<T> &rhs)
{
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T> &lhs, const T *rhs)
{
    return !(lhs < rhs);
}

namespace CBL
{
    class String : public CBL::BasicString<char>
    {

    public:
        using BasicString<char>::operator=;
        using BasicString<char>::operator+=;
        // using BasicString<char>::operator+;

        String() /*: CBL::BasicString<char>()*/
        {
            m_buffer = (char *)malloc(1);
            m_buffer[0] = '\0';
        }
        String(const CBL::BasicString<char> &str) : CBL::BasicString<char>(str) {}
        String(const CBL::BasicString<char> &str, size_t pos, size_t len = npos) : CBL::BasicString<char>(str, pos, len) {}
        explicit String(const char *str) : CBL::BasicString<char>(str) {}
        String(const char *str, size_t n) : CBL::BasicString<char>(str, n) {}
        String(size_t n, char c) : CBL::BasicString<char>(n, c) {}
        String(CBL::BasicString<char>::iterator first, CBL::BasicString<char>::iterator last) : CBL::BasicString<char>(first, last) {}

        size_t find(const String &str, size_t pos = 0) const
        {
            if (pos >= m_size || pos + str.m_size > m_size)
                return CBL::BasicString<char>::npos;
            bool flag = false;
            for (size_t i = pos; i <= m_size - str.m_size; i++)
            {
                for (size_t x = i, y = 0; y < str.m_size; ++x, ++y)
                {
                    flag = true;
                    if ((*this)[x] != str[y])
                    {
                        break;
                        flag = false;
                    }
                }
                if (flag)
                    return i;
            }
            return CBL::BasicString<char>::npos;
        }

        size_t find(const char *str, size_t pos = 0) const
        {
            String tmp(str);
            return find(tmp, pos);
        }

        size_t find(char c, size_t pos = 0) const
        {
            for (size_t i = pos; i < m_size; i++)
            {
                if (m_buffer[i] == c)
                    return i;
            }
            return CBL::BasicString<char>::npos;
        }

        size_t rfind(const String &str, size_t pos = 0) const
        {
            if (pos - str.m_size < 0)
                return CBL::BasicString<char>::npos;
            bool flag = false;
            size_t last = CBL::BasicString<char>::npos;
            for (size_t i = pos; i >= pos - str.m_size; --i)
            {
                if (pos == 0)
                    pos = m_size - 1;
                for (size_t x = i, y = str.m_size - 1; y >= 0; --x, --y)
                {
                    flag = true;
                    if ((*this)[x] != str[y])
                    {
                        break;
                        flag = false;
                    }
                }
                if (flag)
                    return i - str.m_size;
            }
            return CBL::BasicString<char>::npos;
        }

        size_t rfind(const char *str, size_t pos = 0) const
        {
            if (pos == 0)
                pos = m_size - 1;
            String tmp(str);
            return rfind(tmp, pos);
        }

        size_t rfind(char c, size_t pos = 0) const
        {
            for (size_t i = pos; i >= 0; --i)
            {
                if (m_buffer[i] == c)
                    return i;
            }
            return CBL::BasicString<char>::npos;
        }
    };

    class WString : public CBL::BasicString<wchar_t>
    {
    public:
        using BasicString<wchar_t>::operator=;
        using BasicString<wchar_t>::operator+=;

        WString() : CBL::BasicString<wchar_t>() {}
        WString(const CBL::BasicString<wchar_t> &str) : CBL::BasicString<wchar_t>(str) {}
        WString(const CBL::BasicString<wchar_t> &str, size_t pos, size_t len = npos) : CBL::BasicString<wchar_t>(str, pos, len) {}
        explicit WString(const wchar_t *str) : CBL::BasicString<wchar_t>(str) {}
        WString(const wchar_t *str, size_t n) : CBL::BasicString<wchar_t>(str, n) {}
        WString(size_t n, wchar_t c) : CBL::BasicString<wchar_t>(n, c) {}
        WString(CBL::BasicString<wchar_t>::iterator first, CBL::BasicString<wchar_t>::iterator last) : CBL::BasicString<wchar_t>(first, last) {}

        size_t find(const WString &str, size_t pos = 0) const
        {
            if (pos >= m_size || pos + str.m_size > m_size)
                return CBL::BasicString<wchar_t>::npos;
            bool flag = false;
            for (size_t i = pos; i <= m_size - str.m_size; i++)
            {
                for (size_t x = i, y = 0; y < str.m_size; ++x, ++y)
                {
                    flag = true;
                    if ((*this)[x] != str[y])
                    {
                        break;
                        flag = false;
                    }
                }
                if (flag)
                    return i;
            }
            return CBL::BasicString<wchar_t>::npos;
        }

        size_t find(const wchar_t *str, size_t pos = 0) const
        {
            WString tmp(str);
            return find(tmp, pos);
        }

        size_t find(wchar_t c, size_t pos = 0) const
        {
            for (size_t i = pos; i < m_size; i++)
            {
                if (m_buffer[i] == c)
                    return i;
            }
            return CBL::BasicString<wchar_t>::npos;
        }

        size_t rfind(const WString &str, size_t pos = 0) const
        {
            if (pos - str.m_size < 0)
                return CBL::BasicString<wchar_t>::npos;
            if (pos == 0)
                pos = m_size - 1;
            bool flag = false;
            size_t last = CBL::BasicString<wchar_t>::npos;
            for (size_t i = pos; i >= pos - str.m_size; --i)
            {
                for (size_t x = i, y = str.m_size - 1; y >= 0; --x, --y)
                {
                    flag = true;
                    if ((*this)[x] != str[y])
                    {
                        break;
                        flag = false;
                    }
                }
                if (flag)
                    return i - str.m_size;
            }
            return CBL::BasicString<wchar_t>::npos;
        }

        size_t rfind(const wchar_t *str, size_t pos = 0) const
        {
            WString tmp(str);
            return rfind(tmp, pos);
        }

        size_t rfind(wchar_t c, size_t pos = 0) const
        {
            if (pos == 0)
                pos = m_size - 1;
            for (size_t i = pos; i >= 0; --i)
            {
                if (m_buffer[i] == c)
                    return i;
            }
            return CBL::BasicString<wchar_t>::npos;
        }
    };
} // namespace CBL
/* Derived class additional member functions */
// size_t find(const<string class> &str, size_t pos = 0) const;

// size_t find(const<char type> *str, size_t pos = 0) const;

// size_t find(<char type> c, size_t pos = 0) const;

// size_t rfind(const<string class> &str, size_t pos = 0) const;

// size_t rfind(const<char type> *str, size_t pos = 0) const;

// size_t rfind(<char type> c, size_t pos = 0) const;
