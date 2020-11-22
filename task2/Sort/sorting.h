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

template <typename T>
class InsertionSort
{
    T *array;
    long long len;
    bool isFinished;
    long long i,j;

public:
    InsertionSort();
    InsertionSort(T * _array, long long _len);
    ~InsertionSort();
    void step(void);
    void sort(void);
    void init(int *array, long long len);
    bool sorted(void);

};

template <typename T>
class SelectionSort
{
    T *array;
    long long len;
    bool isFinished;
    long long i,j,min;

public:
    SelectionSort();
    SelectionSort(T * _array, long long _len);
    ~SelectionSort();
    void step(void);
    void sort(void);
    void init(int *array, long long len);
    bool sorted(void);

};
#include<sorting.cpp>

#endif // SORTING_H
