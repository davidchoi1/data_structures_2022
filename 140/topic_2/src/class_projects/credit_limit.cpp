#include<iostream>
#include<iomanip>

void printPrompt(std::string);    
int getAccount();                                         
double getInput();
void processAccount();

int main(int argc, char const *argv[])
{
    processAccount();
    
    return 0;
}

void printPrompt(std::string prompt)
{
    std::cout << prompt;                                                                                               
}   

int getAccount()
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

void processAccount()
{
    int account;
    double balance;
    double totChrg;
    double totCred;
    double maxCred;

    while(true)
    {
        printPrompt("Enter account number (-1 to end): ");                                                   
        account =  getAccount();                                                                                           
        if(account == -1) break;              
        
        printPrompt("Enter beginning balance: ");
        balance = getInput();
        
        printPrompt("Enter total charges: ");
        totChrg = getInput();  
        
        printPrompt("Enter total credits: ");
        totCred = getInput();         
        
        printPrompt("Enter credit limit: ");
        maxCred = getInput();       
        
        balance = balance + totChrg - totCred;   
        if(balance > maxCred)
        {
            std::cout << "Account: " << account << std::endl;   
            std::cout << std::setprecision(2) << "Credit Limit: " << maxCred << std::endl;
            std::cout << std::setprecision(2) << "Balance: " << balance << std::endl;
            std::cout << "Credit limit exceeded" << std::endl;
        }
        std::cout << std::setprecision(2) << std::fixed << "New Balance is " << balance <<  std::endl;                                                                                                                                                                   // increase count by one
    }                                                           
}

