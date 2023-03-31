#include <iostream>
#include <array>
#ifndef NAME_H
#define NAME_H



struct Name
{
    
    friend std::ostream& operator<<(std::ostream& out, const Name& name)
    {
        out << name.last << ", " << name.first  << " " << name.middle;
        return out;
    }



    std::string first;
    std::string middle;
    std::string last;



    bool operator==(const Name& other) 
    { 
        return first == other.first && middle == other.middle && last == other.last;
    }

    bool operator!=(const Name& other) { return !(*this == other); }

};

#endif