#include <iostream>
#include <cstddef>

int binSearch(int[], int, int, int);

int main(int argc, char const *argv[])
{
	int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << binSearch(array, 0, 8, 7) << std::endl;

    std::cout << binSearch(array, 0, 8, 4) << std::endl;

    std::cout << binSearch(array, 0, 8, 100) << std::endl;

    std::cout << binSearch(array, 0, 8, -4) << std::endl;
	
	return 0;
}



int binSearch(int a[], int start, int end, int term)                                                    // function binary search takes in int array, start index, end index, then term index
{
    int mid{(start + end) >> 1};                                                                        // define mid index as, start + end divded by 2

    if(start > end) return -1;                                                                          // if start index is greater than the front index, break out of function

    if (term == a[mid]) return mid;                                                                     // if the term is equal to the previously defined mid value, return the mid value

    if (term < a[mid]) return binSearch(a, start, mid - 1, term);                                       // if the term is less than the mid value, recursively call binsearch(array, start index, lower half index as end, term)

    return binSearch(a, mid + 1, end, term);                                                            // else, recursively call binsearch(array, upper half as start index, end index, term in)
}