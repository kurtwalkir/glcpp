#ifndef SORTING_H
#define SORTING_H

template <typename T>
class BubbleSort
{
    T *array;
    long long len;
    bool isFinished;
    long long i,j;

public:
    BubbleSort();
    BubbleSort(T *array, long long len);
    ~BubbleSort();
    void step(void);
    void sort(void);
    void init(int *array, long long len);
    bool sorted(void);

};

#include<sorting.cpp>

#endif // SORTING_H
