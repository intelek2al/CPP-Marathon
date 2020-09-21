#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>

namespace CBL
{

    template <class T>
    class Vector
    {
    public:
        using iterator = T *;

        Vector() = default;
        explicit Vector(size_t size);

        Vector(size_t size, const T &value);
        Vector(iterator first, iterator last);
        Vector(const std::initializer_list<T> &lst);
        Vector(const Vector<T> &other);
        ~Vector();

        Vector<T> &operator=(const Vector<T> &other);
        bool operator==(const Vector<T> &other) const;
        bool operator!=(const Vector<T> &other) const;
        bool operator<(const Vector<T> &other) const;
        bool operator>(const Vector<T> &other) const;
        bool operator<=(const Vector<T> &other) const;
        bool operator>=(const Vector<T> &other) const;

        // iterators

        iterator begin() const;
        iterator end() const;

        // capacity
        size_t size() const;
        size_t capacity() const;
        bool isEmpty() const;
        void resize(size_t size, const T &value = T());
        void reserve(size_t size);

        // element access

        T &operator[](size_t index) const;
        T &at(size_t index) const;
        T *data() const;

        // modifiers

        void push_back(const T &value);
        void pop_back();
        iterator insert(iterator pos, const T &value);
        iterator erase(iterator pos);
        iterator erase(iterator first, iterator last);
        void clear();

    private:
        size_t m_size{0};
        size_t m_capacity{0};
        T *m_buffer{nullptr};
    };

    /******************************************************************************************************/
    /******************************************************************************************************/
    /******************************************************************************************************/
    /******************************************************************************************************/
    /******************************************************************************************************/
    /******************************************************************************************************/

    template <typename T>
    Vector<T>::Vector(size_t size) : m_buffer(new T[size]), m_size(size), m_capacity(size) {}

    template <typename T>
    Vector<T>::Vector(size_t size, const T &value) : Vector(size)
    {
        for (auto &el : *this)
            el = value;
    }

    template <typename T>
    Vector<T>::Vector(iterator first, iterator last) : Vector(last - first)
    {
        std::copy(first, last, begin());
    }

    template <typename T>
    Vector<T>::Vector(const std::initializer_list<T> &lst) : Vector<T>(lst.size())
    {
        std::copy(lst.begin(), lst.end(), begin());
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T> &other) : m_buffer(new T[other.size()]), m_size(other.size()), m_capacity(other.size())
    {
        std::copy(other.begin(), other.end(), begin());
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] m_buffer;
    }

    template <typename T>
    T &Vector<T>::operator[](size_t index) const
    {
        return m_buffer[index];
    }

    template <typename T>
    T &Vector<T>::at(size_t index) const
    {
        if (index >= m_size)
            throw std::out_of_range("Out of range");
        return m_buffer[index];
    }

    template <typename T>
    size_t Vector<T>::size() const
    {
        return m_size;
    }

    template <typename T>
    size_t Vector<T>::capacity() const
    {
        return m_capacity;
    }

    template <typename T>
    bool Vector<T>::isEmpty() const
    {
        return m_size == 0;
    }

    template <typename T>
    void Vector<T>::push_back(const T &value)
    {
        if (m_size >= m_capacity)
        {
            auto new_cap = m_capacity == 0 ? 1 : 2 * m_capacity;
            auto new_data = new T[new_cap];
            std::copy(begin(), end(), new_data);
            delete[] m_buffer;
            m_buffer = new_data;
            m_capacity = new_cap;
        }
        m_buffer[m_size++] = value;
    }

    template <typename T>
    void Vector<T>::pop_back()
    {
        if (m_size > 0)
            m_size--;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::begin() const
    {
        return m_buffer;
    }

    template <typename T>
    T *Vector<T>::data() const
    {
        return m_buffer;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::end() const
    {
        return m_buffer + m_size;
    }

    /*********************************************************/
    /********************* Operators *************************/
    /*********************************************************/
    template <typename T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &other)
    {
        if (other.size() <= m_capacity)
        {
            std::copy(other.begin(), other.end(), begin());
            m_size = other.size();
        }
        else
        {
            Vector<T> tmp(other);
            std::swap(tmp.m_buffer, m_buffer);
            std::swap(tmp.m_size, m_size);
            std::swap(tmp.m_capacity, m_capacity);
        }
        return *this;
    }

    template <typename T>
    bool Vector<T>::operator==(const Vector<T> &other) const
    {
        if (size() != other.size())
            return false;
        return std::equal(begin(), end(), other.begin(), other.end());
    }
    template <typename T>
    bool Vector<T>::operator!=(const Vector<T> &other) const
    {
        return !(*this == other);
    }
    template <typename T>
    bool Vector<T>::operator<(const Vector<T> &other) const
    {
        return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
    }
    template <typename T>
    bool Vector<T>::operator>(const Vector<T> &other) const
    {
        return !(*this < other) && (*this != other);
    }
    template <typename T>
    bool Vector<T>::operator<=(const Vector<T> &other) const
    {
        return (*this < other) || (*this == other);
    }
    template <typename T>
    bool Vector<T>::operator>=(const Vector<T> &other) const
    {
        return !(*this < other);
    }

    template <typename T>
    void Vector<T>::resize(size_t size, const T &value)
    {
        if (size > m_capacity)
        {
            T *tmp = new T[size];
            std::copy(begin(), end(), tmp);
            delete[] m_buffer;
            m_buffer = tmp;
            m_capacity = size;
        }
        if (size > m_size)
        {
            size -= m_size;
            for (; size != 0; --size)
            {
                push_back(value);
            }
        }
        else
        {
            m_size -= size;
        }
    }

    template <typename T>
    void Vector<T>::reserve(size_t size)
    {
        if (size > m_capacity)
        {
            T *tmp = new T[size];
            std::copy(begin(), end(), tmp);
            delete[] m_buffer;
            m_buffer = tmp;
            m_capacity = size;
        }
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::insert(iterator pos, const T &value)
    {
        if (pos == end())
        {
            push_back(value);
            return end() - 1;
        }
        size_t distance = pos - begin();
        Vector<T> tmp(begin(), pos);
        tmp.push_back(value);
        auto it = pos;
        while (it != end())
        {
            tmp.push_back(*it);
            it++;
        }
        delete[] m_buffer;
        m_capacity *= m_size == m_capacity ? 2 : 1;
        m_buffer = new T[m_capacity];
        std::move(tmp.begin(), tmp.end(), m_buffer);
        m_size++;
        return begin() + distance;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::erase(iterator pos)
    {
        if (pos == end() - 1)
        {
            --m_size;
            return end();
        }
        for (auto it = pos; it + 1 != end(); it++)
            it[0] = it[1];
        --m_size;
        return pos;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last)
    {
        auto b = first;
        auto e = last;
        for (; e != end(); b++, e++)
        {
            *b = *e;
        }
        m_size -= (last - first);
        if (m_size == 0)
            return nullptr;
        return last;
    }

    template <typename T>
    void Vector<T>::clear()
    {
        m_size = 0;
    }

} // end namespace CBL
