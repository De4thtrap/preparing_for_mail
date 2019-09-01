#include <stdio.h>

int BinarySearch(int *arr, int count, int element)
{
    int first = 0;
    int last = count - 1;
    while (first < last)
    {
        int mid = (first + last) / 2;
        if (element <= arr[mid])
            last = mid;
        else
            first = mid + 1;
    }
    return (arr[first] == element)? first : -1;
}

int* BinarySearch2(const int *start, const int *end, const int element)
{
    const int *mid = nullptr;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (element < *mid)
            end = mid;
        else if (element > *mid)
            start = mid + 1;
        else
            return (int*)mid;
    }
    return (*start == element)? (int*)start : nullptr;
}

int main(int argc, char const *argv[])
{
    int arr[10] = {-6, -1, 2, 3, 4, 5, 7, 8, 9, 15};
    printf("%d\n", BinarySearch(arr, 10, -6));
    printf("%d\n", BinarySearch(arr, 10, 4));
    printf("%d\n", BinarySearch(arr, 10, 10));
    printf("%d\n", *BinarySearch2(arr, arr + 10, -6));
    printf("%d\n", *BinarySearch2(arr, arr + 10, 4));
    printf("%d\n", *BinarySearch2(arr, arr + 10, 10));
    return 0;
}