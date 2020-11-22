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
BubbleSort<T>::~BubbleSort()
{

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

template<typename T>
bool BubbleSort<T>::sorted()
{
    return isFinished;
}

/*-----------Insert sort-----------*/
template<typename T>
InsertionSort<T>::InsertionSort()
{

}

template<typename T>
InsertionSort<T>::InsertionSort(T *_array, long long _len)
{
    array = _array;
    len = _len;
    isFinished = false;
    i = 0;
    j = 0;
}

template<typename T>
InsertionSort<T>::~InsertionSort()
{

}

template<typename T>
void InsertionSort<T>::step()
{
    if (isFinished)
        return;
    if (i < len)
    {
        if (j > 0 && array[j-1] > array[j])
        {
            std::swap(array[j], array[j-1]);
            j--;
        }
        else
        {
            i++;
            j = i;
        }
    }
    else
        isFinished = true;
}

template<typename T>
void InsertionSort<T>::sort()
{
    for (long long i = 1; i < this->len; i++)
        for (long long j = i; j > 0 && this->array[j-1] > this->array[j]; j--)
            std::swap(this->array[j-1], this->array[j]);
}

/*-----------Selection sort-----------*/
template<typename T>
SelectionSort<T>::SelectionSort()
{

}

template<typename T>
SelectionSort<T>::SelectionSort(T *_array, long long _len)
{
    array = _array;
    len = _len;
    isFinished = false;
    i = 0;
    j = 0;
}

template<typename T>
SelectionSort<T>::~SelectionSort()
{

}

template<typename T>
void SelectionSort<T>::step()
{
    if (isFinished)
        return;
    if (array[j] < array[min])
        min = j;
    j++;
    if (j >= len)
    {
        std::swap(array[i], array[min]);
        i++;
        min = i;
        j = i;
    }
    if (i >= len - 1)
        isFinished = true;
}

template<typename T>
void SelectionSort<T>::sort()
{
    for (long long i = 0; i < this->len - 1; i++)
    {
        long long min = i;
        for (long long j = i+1; j < this->len; j++)
        {
            if (this->array[j] < this->array[min])
                min = j;
        }
        std::swap(this->array[i], this->array[min]);
    }
}
