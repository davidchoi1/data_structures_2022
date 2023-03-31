#include<iostream>
#include<iomanip>

void printPrompt(std::string);    
int getHourst();                                          // why does the compiler need these prototypes here
double getInput();
void processPay();

int main(int argc, char const *argv[])
{
    processPay();
    
    return 0;
}

void printPrompt(std::string prompt)
{
    std::cout << prompt;                                                                                           
}   

int getHours()
{
    int val;                                                                                                       
    
    std::cin >> val;
    
    return val;                                                                               
}

double getInput()
{
    double val;
    
    std::cin >> val;
    return val;
}

void processPay()
{
    int hours;
    double hr_rate;
    double salary;
    double extra;


    while(true)
    {
        printPrompt("Enter hours worked (-1 to end): ");                                                   
        hours =  getHours();                                                                                           
        if(hours == -1) break;              
        
        printPrompt("Enter hourly rate of worker ($00.00): ");
        hr_rate = getInput();

        if(hours > 40)
        {
            extra = hours - 40;
            salary = (40 * hr_rate) + (extra * (hr_rate * 1.5));
        }
        else
        {
        salary = hours * hr_rate;
        }

        std::cout << std::setprecision(2) << std::fixed << "Salary is: " << salary <<  std::endl;                                                                                                                                                                   // increase count by one
    }                                                           
}

