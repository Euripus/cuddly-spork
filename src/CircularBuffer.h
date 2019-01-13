#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <algorithm>
#include <iterator>
#include <vector>
#include <cstddef>
#include <cassert>

// Абстракция кольцевого буфера
template <typename T, int bufSize>
class CircularBuffer
{
public:
    //typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    //typedef const T* const_pointer;

    CircularBuffer();
    CircularBuffer(const CircularBuffer<T, bufSize> &rhs); 
    CircularBuffer<T, bufSize>& operator=(CircularBuffer<T, bufSize> rhs);

    int size() const { return (_full ? bufSize : (_tail - _buffer)); }
    bool is_full() const { return _full; }

    const_reference operator[](int index) const;

    void add(const_reference item);
    
    void reset(const_reference val)
    {
        std::fill(_buffer, _buffer + bufSize, val);
        _tail = _buffer;
        _full = false;
    }
    
    friend void swap(CircularBuffer<T, bufSize> &a, CircularBuffer<T, bufSize> &b)
    {
        std::swap(a._buffer, b._buffer);
        std::swap(a._tail, b._tail);
        std::swap(a._full, b._full);
    }

private:
    T _buffer[bufSize];
    pointer _tail;
    bool    _full;
};

template<typename T, int bufSize>
CircularBuffer<T, bufSize>::CircularBuffer()
    : _tail(_buffer)
    , _full(false)
{
    std::fill(_buffer, _buffer + bufSize, 0);
}

template<typename T, int bufSize>
CircularBuffer<T, bufSize>::CircularBuffer(const CircularBuffer<T, bufSize> &rhs)
    : _tail(rhs._tail)
    , _full(rhs._full)
{
    std::copy(rhs._buffer, rhs._buffer + bufSize, _buffer);
}

template<typename T, int bufSize>
CircularBuffer<T, bufSize>& 
CircularBuffer<T, bufSize>::operator=(CircularBuffer<T, bufSize> rhs)
{
    swap(*this, rhs);
    return *this;
}

// Доступ к данным
// индексы отрицательны
//  | ... |-3|-2|-1| 0| x| x| x|
template<typename T, int bufSize>
typename CircularBuffer<T, bufSize>::const_reference
CircularBuffer<T, bufSize>::operator[](int index) const
{
    assert( index <= 0 && size() + index > 0 );

    int idx = index - 1;
    if(_tail + idx < _buffer)
    {
        return _buffer[bufSize + (idx + (_tail - _buffer))];
    }
    else
        return _tail[idx];
}

template<typename T, int bufSize>
void 
CircularBuffer<T, bufSize>::add(const_reference item)
{
    // В случае окончания буфера начнем сначала
    if(_tail + 1 > _buffer + bufSize)
    {
        _full = true;
        _tail[0] = item;
        _tail = _buffer;
    }
    else
    {
        _tail[0] = item;
        _tail++;
    }
}

#endif // CIRCULAR_BUFFER_H