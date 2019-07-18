#include <stdio.h>

int BinarySearch(double *arr, int count, double element)
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

int main(int argc, char const *argv[])
{
    double arr[10] = {-6, -1, 2, 3, 4, 5, 7, 8, 9, 15};
    printf("%d\n", BinarySearch(arr, 2, -6));
    return 0;
}