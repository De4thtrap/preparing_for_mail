#include <iostream>
#include <assert.h>
#include <set>

void treesort(int* l, int* r) {
    std::multiset<int> m;
    for (int *i = l; i < r; i++)
        m.insert(*i);
    for (int q : m)
        *l = q, l++;
}



int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int arr[count] = {};

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    treesort(arr, arr + count);
    // for (int i = 0; i < count; ++i)
    //     printf("%d ", arr[i]);
    // printf("\n");

    fclose(file);
    return 0;
}