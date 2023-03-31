#include "common.h"
#include "person.h"
#include "controller.h"


int main(int argc, char const *argv[])
{
    Controller c;                               // controller object

    while(true)                                 // ticks
    {
       c.update();                              // call controller update every tick
    }

    return 0;
}
