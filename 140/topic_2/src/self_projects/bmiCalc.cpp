#include <iostream>


void printPrompt(std::string);
int getInput();
double bmIndex(int, int);
void tellEm(double);

int main(int argc, char const *argv[])
{
    int pounds;
    int inches;

    printPrompt("Enter weight in pounds: ");
    pounds = getInput();

    printPrompt("Enter height in inches: ");
    inches = getInput();

    printPrompt("Your BMI is ");
    std:: cout << bmIndex(pounds, inches) << std::endl;

    tellEm(bmIndex(pounds, inches));
    
    return 0;
}

void printPrompt(std::string prompt)
{
    std::cout << prompt;
}

int getInput()
{
    int val;
    std::cin >> val;
    return val;
}

double bmIndex(int weight, int height)
{
    double bmi;

    bmi = (weight * 703)/(height * height);

    return bmi;
}

void tellEm(double bmi)
{
    if (bmi < 18.5) {
        printPrompt("You are too skinny.");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printPrompt("You are too normal.");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printPrompt("You are too fat.");
    } else if (bmi >= 30) {
        printPrompt("You are too waaayyy too fat.");
    }
}
