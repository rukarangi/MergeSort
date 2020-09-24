#include <stdio.h>
#include <stdlib.h>

void TopDownMerge(size_t N, double A[N], size_t begin, size_t middle, size_t end, double B[N])
{   
    size_t b = begin, m = middle;

    for (size_t i = b; i < end; ++i)
    {
        if(b < middle && (m >= end || A[b] <= A[m]))
        {
            B[i] = A[b];
            ++b;
        } else
        {
            B[i] = A[m];
            ++m;
        }
    }

    return;
}

void TopDownSplitMerge(size_t N, double B[N], size_t begin, size_t end, double A[N])
{
    if(end < begin || end - begin < 2)
        return;

    size_t middle = begin + (end - begin) / 2;

    TopDownSplitMerge(N, A, begin, middle, B);
    TopDownSplitMerge(N, A, middle, end, B);

    TopDownMerge(N, B, begin, middle, end, A);
}

void CopyArray(size_t N, double A[N], size_t begin, size_t end, double B[N])
{
    for(size_t i = begin; i < end; ++i)
    {
        B[i] = A[i];
    }
}

void TopDownMergeSort(size_t N, double A[N], double B[N])
{
    CopyArray(N, A, 0, N, B);
    TopDownSplitMerge(N, B, 0, N, A);
}

static size_t const ARR_SIZE = 20;

int main(void) 
{
    double B[ARR_SIZE];
    double A[ARR_SIZE] = {
        [0] = 1.1,
        [1] = 2.2,
        [2] = 3.3,
        [3] = 4.4,
        [4] = 5.5,
        [5] = 1.2,
        [6] = 2.3,
        [7] = 3.4,
        [8] = 4.5,
        [9] = 5.6,
        [10] = 1.7,
        [11] = 2.8,
        [12] = 3.9,
        [13] = 4.10,
        [14] = 5.11,
        [15] = 1.12,
        [16] = 2.14,
        [17] = 3.15,
        [18] = 4.16,
        [19] = 5.18,
    };

    TopDownMergeSort(ARR_SIZE, A, B);

    for (size_t i = 0; i < ARR_SIZE; ++i)
    {
        printf("at place: %zu, %f\n", i, A[i]);
    }
    
    return 0;
}