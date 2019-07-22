#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    FILE *file = fopen("rand.txt", "w");
    int a = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        a = rand() % 1000000000;
        fprintf(file, "%d ", a);
        if (!(i % 10000))
            printf("%d ", i / 10000);
    }
    printf("\n");
    fclose(file);
    return 0;
}