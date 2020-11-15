#include "sorting.h"
#include <iostream>

template<typename T>
BubbleSort<T>::BubbleSort(){}

template<typename T>
BubbleSort<T>::BubbleSort(T *_array, long long _len)
{
    array = _array;
    len = _len;
    isFinished = false;
    i = 0;
    j = 0;
}

template<typename T>
void BubbleSort<T>::step()
{
    if (!isFinished)
    {
        if (array[j] > array[j+1])
        {
            std::swap(array[j], array[j+1]);
        }
        j++;
        if (j >= len-1-i)
        {
            j = 0;
            i++;
        }
        if (i >= len)
        {
            isFinished = true;
        }
    }
}

template<typename T>
void BubbleSort<T>::sort()
{
    for (long long i = 0; i < this->len ; i++)
    {
        for (long long j = 0; j < this->len - 1 - i; j++)
        {
            if (this->array[j] > this->array[j+1])
            {
                std::swap(this->array[j], this->array[j+1]);
            }
        }
    }
}




