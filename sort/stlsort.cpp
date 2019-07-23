#include <iostream>
#include <assert.h>
#include <algorithm>

int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int *arr = (int*)malloc(sizeof(int) * count);

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    std::sort(arr, arr + count);
    // for (int i = 0; i < count; ++i)
    //     printf("%d ", arr[i]);
    // printf("\n");
    free(arr);

    fclose(file);
    return 0;
}