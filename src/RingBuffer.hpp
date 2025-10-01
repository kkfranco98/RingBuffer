#pragma once

#include <Arduino.h>

template <typename T, size_t N>
class Ring_Buffer
{
private:
    T _buffer[N];
    size_t _index;
    size_t _computed_elements;

    size_t first_index() const;

public:
    Ring_Buffer();

    void push_back(const T &value);

    bool empty() const;
    bool is_loaded() const;
    size_t size() const;
    constexpr size_t capacity() const;

    T &at(size_t i);
    const T &at(size_t i) const;

    T &newest_element();
    const T &newest_element() const;

    T &oldest_element();
    const T &oldest_element() const;

    class iterator
    {
    public:
        iterator(T *_data, size_t _start, size_t _count, size_t _pos);
        iterator &operator++();
        bool operator!=(const iterator &other) const;
        T &operator*() const;

    private:
        T *_data;
        size_t _start;
        size_t _count;
        size_t _pos;
    };

    class const_iterator
    {
    public:
        const_iterator(const T *_data, size_t _start, size_t _count, size_t _pos);
        const_iterator &operator++();
        bool operator!=(const const_iterator &other) const;
        const T &operator*() const;

    private:
        const T *_data;
        size_t _start;
        size_t _count;
        size_t _pos;
    };

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "RingBuffer.tpp"