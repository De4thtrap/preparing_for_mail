#include <iostream>
#include <assert.h>
#include <string.h>

template <typename T>
T *BinarySearch(T *l, T *r, T element)
{
    T *mid = nullptr;
    while (l + 1 < r)
    {
        mid = l + (r - l) / 2;
        if (element < *mid)
            r = mid;
        else
            l = mid;
    }
    if (*l < element)
        return r;
    return l;
}

template <typename T>
void insertionsort(T *l, T *r)
{
    T *place = nullptr;
    T tmp;
    for (T *i = l + 1; i < r; ++i)
    {
        place = BinarySearch(l, i, *i);
        tmp = *i;
        memmove(place + 1, place, sizeof(T) * (i - place));
        *place = tmp;
    }
}

template <typename T>
void qsort(T *first, T *last)
{
    if (last - first < 30)
    {
        insertionsort(first, last);
        return;
    }
    T *l = first;
    T *r = last - 1;
    T mid = *(l + (r - l) / 2);

    while (l <= r)
    {
        while (*l < mid)
            l++;
        while (*r > mid)
            r--;
        if (l <= r)
        {
            std::swap(*l, *r);
            l++;
            r--;
        }
    }
    // printf("%p %p\n", first, r + 1);
    // for (T *i = first; i < r + 1; ++i)
    //     printf("%d\n", *i);
    qsort(first, r + 1);
    // printf("%p %p\n", l, last);
    qsort(l, last);
    // printf("2\n");
}






int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int *arr = (int*)malloc(sizeof(int) * count);

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    qsort(arr, arr + count);
    // for (int i = 0; i < count; ++i)
    //     printf("%d ", arr[i]);
    // printf("\n");
    free(arr);

    fclose(file);
    return 0;
}