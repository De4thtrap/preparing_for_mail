#include <iostream>
#include <assert.h>

template <typename T>
void merge(T *arr1, int len1, T *arr2, int len2, T *tmp)
{
    int i1 = 0;
    int i2 = 0;
    int j = 0;

    while (i1 < len1 && i2 < len2)
    {
        if (arr1[i1] < arr2[i2])
        {
            tmp[j] = arr1[i1];
            i1++;
        }
        else
        {
            tmp[j] = arr2[i2];
            i2++;
        }
        j++;
    }

    for (; i1 < len1; ++i1)
    {
        tmp[j] = arr1[i1];
        j++;
    }

    for (; i2 < len2; ++i2)
    {
        tmp[j] = arr2[i2];
        j++;
    }

    for (int i = 0; i < len1; ++i)
        arr1[i] = tmp[i];
    for (int i = 0; i < len2; ++i)
        arr2[i] = tmp[i + len1];
}

template <typename T>
void mergesort(T *arr, int count, T *tmp)
{
    if (count == 1)
        return;

    mergesort(arr, count / 2, tmp);
    mergesort(arr + count / 2, count - count / 2, tmp);

    merge(arr, count / 2, arr + count / 2, count - count / 2, tmp);
}

template <typename T>
void sort(T *arr, int count)
{
    T *tmp = (int*)malloc(sizeof(T) * count);
    mergesort(arr, count, tmp);
    free(tmp);
}


int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int *arr = (int*)malloc(sizeof(int) * count);

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    sort(arr, count);
    // for (int i = 0; i < count; ++i)
    //     printf("%d ", arr[i]);
    // printf("\n");
    free(arr);

    fclose(file);
    return 0;
}