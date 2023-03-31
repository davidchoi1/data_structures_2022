#include <iostream>

void printArray(const int *array, size_t size)                                      // use const int const *array to make array pointer memory location
{
    for (size_t i{0}; i < size; i++)
        std::cout << *(array++) << " ";
    
    std::cout << std::endl;
    
}

void printArray2(const int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << *(array + i) << " ";

    std::cout << std::endl;
}

int main(int arc, const char *argv[])
{

    int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray(a, sizeof(a) / sizeof(int));
    printArray2(a, sizeof(a) / sizeof(int));

    return 0;
}