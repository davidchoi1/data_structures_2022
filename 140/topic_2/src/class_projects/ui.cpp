#include<iostream>
#include<iomanip>

void printPrompt(std::string);                                              // why does the compiler need these prototypes here
int getInput();
void processGrades();

int main(int argc, char const *argv[])
{
    processGrades();
    
    return 0;
}

void printPrompt(std::string prompt)
{
    std::cout << prompt;                                                                                                // print the prompt sent
}   

int getInput()
{
    int grade;                                                                                                          // variable to hold input
    // std::cin >> grade;                                                                                                  // place input into variable
    
    // if(grade < -1 || grade > 100)                                                                                       // recursive input validation: if grade is less than -1 or greater than 100...
    // {
    //     printPrompt("Invalid value. Input value between -1 and 100: ");                                                 // print invalid prompt
    //     return getInput();                                                                                              // recursive call
    // }

    while(true)                                                                                                             // iterative input validation
    {
        std::cin >> grade;
        if(grade >= -1 && grade <= 100) return grade;

        std::cout << "Invalid grade. Enter a value between -1: ";
    }

    // return grade;                                                                                                       // return grade
}

void processGrades()
{
    size_t sum{0};                                                                                                      // variable to hold the sum of all grades inputted
    int input{};                                                                                                        // variable to hold the input
    size_t counter{0};                                                                                                  // variable to hold how many times user inputted (to be used in average expression)

    while(true)
    {
        printPrompt("Enter a grade between 0 - 100 (-1 to stop): ");                                                    // prompt input
        input =  getInput();                                                                                            // set input equal to the input of the user
        if(input == -1) break;                                                                                          // if user inputs -1, break

        sum += input;                                                                                                   // keep total amount in sum
        ++counter;                                                                                                      // increase count by one
    }

    std::cout << std::setprecision(2) << std::fixed << "The average grade is: "                                         // setprecision to 2 floating point values, fixed 
        << static_cast<double>(sum) / counter << std::endl;                                                             // automatically cast the expression (sum/counter) to floating point double
}

