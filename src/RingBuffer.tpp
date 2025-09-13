#pragma once

#include "RingBuffer.hpp"

template <typename T, size_t N>
size_t Ring_Buffer<T, N>::first_index() const
{
    return (_computed_elements == N) ? _index : 0;
}

template <typename T, size_t N>
Ring_Buffer<T, N>::Ring_Buffer() : _index(0), _computed_elements(0) {}

template <typename T, size_t N>
void Ring_Buffer<T, N>::push_back(const T &value)
{
    _buffer[_index] = value;
    _index = (_index + 1) % N;
    if (_computed_elements < N)
        _computed_elements++;
}

template <typename T, size_t N>
bool Ring_Buffer<T, N>::empty() const { return _computed_elements == 0; }

template <typename T, size_t N>
bool Ring_Buffer<T, N>::is_loaded() const { return _computed_elements == N; }

template <typename T, size_t N>
size_t Ring_Buffer<T, N>::size() const { return _computed_elements; }

template <typename T, size_t N>
constexpr size_t Ring_Buffer<T, N>::capacity() const { return N; }

template <typename T, size_t N>
T Ring_Buffer<T, N>::at(size_t i) const
{
    if (i >= _computed_elements)
        return {};
    return _buffer[(first_index() + i) % N];
}

template <typename T, size_t N>
T Ring_Buffer<T, N>::newest_element() const
{
    if (_computed_elements == 0)
        return {};
    return _buffer[(_index + N - 1) % N];
}

template <typename T, size_t N>
T Ring_Buffer<T, N>::oldest_element() const
{
    if (_computed_elements == 0)
        return {};
    return _buffer[first_index()];
}

// ---------- Iteratori ----------
template <typename T, size_t N>
Ring_Buffer<T, N>::iterator::iterator(T *_data, size_t _start, size_t _count, size_t _pos)
    : _data(_data), _start(_start), _count(_count), _pos(_pos) {}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::iterator &Ring_Buffer<T, N>::iterator::operator++()
{
    ++_pos;
    return *this;
}

template <typename T, size_t N>
bool Ring_Buffer<T, N>::iterator::operator!=(const iterator &other) const
{
    return _pos != other._pos;
}

template <typename T, size_t N>
T &Ring_Buffer<T, N>::iterator::operator*() const
{
    return _data[(_start + _pos) % N];
}

template <typename T, size_t N>
Ring_Buffer<T, N>::const_iterator::const_iterator(const T *_data, size_t _start, size_t _count, size_t _pos)
    : _data(_data), _start(_start), _count(_count), _pos(_pos) {}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::const_iterator &Ring_Buffer<T, N>::const_iterator::operator++()
{
    ++_pos;
    return *this;
}

template <typename T, size_t N>
bool Ring_Buffer<T, N>::const_iterator::operator!=(const const_iterator &other) const
{
    return _pos != other._pos;
}

template <typename T, size_t N>
const T &Ring_Buffer<T, N>::const_iterator::operator*() const
{
    return _data[(_start + _pos) % N];
}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::iterator Ring_Buffer<T, N>::begin()
{
    return iterator(_buffer, first_index(), _computed_elements, 0);
}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::iterator Ring_Buffer<T, N>::end()
{
    return iterator(_buffer, first_index(), _computed_elements, _computed_elements);
}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::const_iterator Ring_Buffer<T, N>::begin() const
{
    return const_iterator(_buffer, first_index(), _computed_elements, 0);
}

template <typename T, size_t N>
typename Ring_Buffer<T, N>::const_iterator Ring_Buffer<T, N>::end() const
{
    return const_iterator(_buffer, first_index(), _computed_elements, _computed_elements);
}
