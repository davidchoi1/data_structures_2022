#include <iostream>
#include "student_class.h"


int main(int argc, char const *argv[])
{
    Student suzy{{"Suzy", "Twinkle", "Fart"}, 85562};

    Student kylo{{"Kylo", "Lor", "Ren"}, 84532};

    Student john{{"John", "Jacob", "Jingleheimerschmidt"}, 89324};

    Student carl{{"Carl", "S", "Jr"}, 85562};

    Student francisco{{"Francisco", "Lor", "Rod"}, 85332};

    Student ivan{{"Ivan", "Jacob", "Moc"}, 89024};


    {
        Student civan{{"CIvan", "Jacob", "Moc"}, 89024};
        std::cout << Student::getInstanceCount() << std::endl;
    }
   
        std::cout << Student::getInstanceCount() << std::endl;

    return 0;
}
