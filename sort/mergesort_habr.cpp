#include <iostream>
#include <assert.h>
using namespace std;



void insertionsort(int* l, int* r) {
    for (int *i = l + 1; i < r; i++) {
        int* j = i;
        while (j > l && *(j - 1) > *j) {
            swap(*(j - 1), *j);
            j--;
        }
    }
}

void merge(int* l, int* m, int* r, int* temp) {
    int *cl = l, *cr = m, cur = 0;
    while (cl < m && cr < r) {
        if (*cl < *cr) temp[cur++] = *cl, cl++;
        else temp[cur++] = *cr, cr++;
    }
    while (cl < m) temp[cur++] = *cl, cl++;
    while (cr < r) temp[cur++] = *cr, cr++;
    cur = 0;
    for (int* i = l; i < r; i++)
         *i = temp[cur++];
}
void _mergesort(int* l, int* r, int* temp) {
    if (r - l <= 1) return;
    int *m = l + (r - l) / 2;
    _mergesort(l, m, temp);
    _mergesort(m, r, temp);
    merge(l, m, r, temp);
}
void mergesort(int* l, int* r) {
    int* temp = new int[r - l];
    _mergesort(l, r, temp);
    delete temp;
}
void _mergeinssort(int* l, int* r, int* temp) {
    if (r - l <= 32) {
        insertionsort(l, r);
        return;
    }
    int *m = l + (r - l) / 2;
    _mergeinssort(l, m, temp);
    _mergeinssort(m, r, temp);
    merge(l, m, r, temp);
}
void mergeinssort(int* l, int* r) {
    int* temp = new int[r - l];
    _mergeinssort(l, r, temp);
    delete temp;
}



int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int arr[count] = {};

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    mergeinssort(arr, arr + count);
    // for (int i = 0; i < count; ++i)
    //     printf("%d ", arr[i]);
    // printf("\n");

    fclose(file);
    return 0;
}