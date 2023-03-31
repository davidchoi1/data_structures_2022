#ifndef MATH_H
#define MATH_H

template<typename T>
class Math
{

public:

    Math(T length, T width) : length{length}, width{width} { }      // math constructor - instantiate length and width with parameter length and width
    
    T area()                                            // calculate area
    {
        return length * width;
    }                 
    

    static T min(T a,T b)                               // minimum function
    {
        return (a > b) ? b : a;                         // if a is greater than be, we will return b, otherwise we return a
    }

    static T max(T a, T b)                              // max function
    {
        return (a > b) ? a : b;                         // if a is greater than b, we will return a, otherwise we return b
    }

    static T abs(T a) 
    {
        return (a >= 0 ? a : (-a));                     // if a >= 0, return a, or else return negation of a
    }

private:
    T length;
    T width;
};


#endif