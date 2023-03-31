#include<iostream>
#include<stdexcept>

#include"queue.h"
#include"linked_queue.h"
#include"array_queue.h""

const int TEST_VAL{5};                                                                                                                                          
const int TEST_VALS[]{1,2,3,4,5,6,7,8,9,10,11,12};                                                         
const size_t TEST_VALS_SZ{13};                                                                          

void test_endequeue(Queue<int>* queue);                                                                 
void test_clempty(Queue<int>* queue);

int main(int argc, char const *argv[])
{
    try                                                                                                 
    {
        test_endequeue(new LinkedQueue<int>);     

        test_clempty(new LinkedQueue<int>);  
        
        // test_endequeue(new ArrayQueue<int>);     

        // test_clempty(new ArrayQueue<int>);                                                                                                            
    }
    
    catch(const std::exception& e)                                                                      
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void test_endequeue(Queue<int>* queue)
{
    for (size_t i{0}; i < TEST_VALS_SZ; ++i)                                                                // !!iterate through queue amount of times indicated by TEST_VALS_SZ (11)
    {
        queue->enqueue(TEST_VALS[i]);                                                                       // !!add each item from TEST_VALS into queue!!
    }

    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
 
    
    // if(queue->front() != TEST_VALS[0])                                                                      // !!if queue doesn't contain first item added (TEST_VALS)...!!
    //     throw std::runtime_error("FAIL: Dequeue not returning correct value.");                             // !!throw exception message!!

    // if(queue->dequeue() != TEST_VALS[0])                                                                    // !!if queue doesn't contain first item added (TEST_VALS)...!!
    //     throw std::runtime_error("FAIL: Dequeue not returning correct value.");                             // !!throw exception message!!

    // if(queue->dequeue() != TEST_VALS[1])                                                                    // !!if queue doesn't contain last item added...!!
    //     throw std::runtime_error("FAIL: Second Dequeue not returning correct value.");                      // !!throw exception message!!

    // std::cout << "PASSED: Front, Enqueue and Dequeue Passed.\n";
}

void test_clempty(Queue<int>* queue)
{
    // for (size_t i{0}; i < TEST_VALS_SZ; ++i)                                                                // !!iterate through queue amount of times indicated by TEST_VALS_SZ (11)
    // {
    //     queue->enqueue(TEST_VALS[i]);                                                                       // !!add each item from TEST_VALS into queue!!
    // }

    // queue->clear();                                                                                         // clear queue

    // if (!queue->empty())                                                                                    // if queue isn't empty
    //     throw std::runtime_error("FAIL: Clear not working.");                                               // failed

    // std::cout << "PASSED: Clear and empty Passed.\n";    
}
