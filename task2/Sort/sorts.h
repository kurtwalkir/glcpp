#ifndef SORTS_H
#define SORTS_H
#include <iostream>

template <class T>
void bubble_sort(T array[], long long size)
{
    for (long long i = 0; i < size; i++)
    {
        for (long long j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
            }
        }
    }
}

template <class T>
void shuffle_array(T array[], long long len)
{
    srand(time(0));
    for (long long i = 0; i < len; i++)
    {
        long long rand_index_1 = static_cast<long long >(rand()) % len;
        long long rand_index_2 = static_cast<long long >(rand()) % len;
        std::swap(array[rand_index_1], array[rand_index_2]);
    }
}

#endif // SORTS_H
