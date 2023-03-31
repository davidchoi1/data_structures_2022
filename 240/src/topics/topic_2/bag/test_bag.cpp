#include<iostream>
#include<stdexcept>

#include"bag.h"
#include"array_bag.h"
#include"linked_bag.h"

const int TEST_VAL{5};                                                                                  // !!constant int value for testing!!                                                           
const int TEST_VALS[]{1,2,3,4,5,6,7,8,9,10,11};                                                         // !!constant int array for testing!!
const size_t TEST_VALS_SZ{11};                                                                          // !!constant size_t for default test value size(TEST_VALS)!!

void testAdd_Size(Bag<int>* bag);                                                                       // !!prototype of add size (parameter: pointer to pointer to int bag object called bag)!!
void testContains(Bag<int>* bag);                                                                       // !!prototype of test contains(parameter: pointer to pointer to int bag object called back)!!
void testContainsUsingArray(Bag<int>* bag);                                                             // !!prototype of...(parameter: pointer to pointer to int bag object called back)!!
                                                                                                        // ??why do prototype need to go up top like this??
int main(int argc, char const *argv[])
{
    try                                                                                                 // ??what is the try catch block and how does it work??
    {
        testAdd_Size(new LinkedBag<int>);                                                               // 

        testContains(new LinkedBag<int>);
        
        testContainsUsingArray(new LinkedBag<int>);
    }
    
    catch(const std::exception& e)                                                                      // ??what is going on here and the lines after??
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

void testAdd_Size(Bag<int>* bag)
{
    bag->add(TEST_VAL);                                                                                 // !!add 1 value (TEST_VAL) to the bag!! 

    if(bag->size() != 1)                                                                                // !!{test size()} if bag's size doesn't equal 1..!!
        throw std::runtime_error("Tested Add function. Size did not return correct value.");            // !!throw an exception message!!

    delete bag;                                                                                         

    std::cout << "PASSED: Add Passed.\n";                                                               // !!Otherwise, say it passed!!
}

void testContains(Bag<int>* bag)                                                                        
{

    bag->add(TEST_VAL);                                                                                 // !!add the value (TEST_VAL) to bag!!

    if(!bag -> contains(TEST_VAL))                                                                      // !!{test contains()} if bag does NOT contain TEST_VAL!!
        throw std::runtime_error("Tested Contains function. Did not report membership.");               // !!throw exception message

    delete bag;

    std::cout << "PASSED: Contain Passed.\n";                                                           // !!otherwise, say it passed!!
}

void testContainsUsingArray(Bag<int>* bag)
{

    for (size_t i{0}; i < TEST_VALS_SZ; ++i)                                                            // !!iterate through bag amount of times indicated by TEST_VALS_SZ (11)
    {
        bag->add(TEST_VALS[i]);                                                                         // !!add each item from TEST_VALS into bag!!
    }

    if(!bag -> contains(TEST_VALS[0]))                                                                                  // !!if bag doesn't contain first item added (TEST_VALS)...!!
        throw std::runtime_error("FAIL: Tested Contains function on first item added. Did not report membership.");     // !!throw exception message!!

    if(!bag -> contains(TEST_VALS[TEST_VALS_SZ - 1]))                                                                   // !!if bag doesn't contain last item added...!!
        throw std::runtime_error("FAIL: Tested Contains function on last item added. Did not report membership.");      // !!throw exception message!!

    if(!bag -> contains(TEST_VALS[TEST_VALS_SZ >> 1]))                                                                  // !!if bag doesn't contain middle item added...!!
        throw std::runtime_error("FAIL: Tested Contains function on middle item added. Did not report membership.");    // !!throw exception message!!

    if(bag->contains(0))                                                                                                // !!if bag contains a value which wasn't added (0)...!
        throw std::runtime_error("FAIL: Tested Contains function on value not added. Reported membership.");            // !!throw exception message

    delete bag;

    std::cout << "PASSED: Contains on multiple values Passed.\n";                                                       // !!otherwise, say everything passed!!
}