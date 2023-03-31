
#include "common.h"
#include "building.h"
#include "person.h"



#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:

   void update()
   {
      srand(time(NULL));

      // add person to building lobby queue 3.5% of the time
      if(isProbable(ENTER_PROB))          
      {
         p = new Person(nextID++, randRange(1, 50));             
         b.addPerson(p);                        
      }

      // update building object
      b.update();
   }




private:
   size_t nextID{0};                         // ID starts 0 to 1
   Person* p;                                // pointer the memloc for future person's
   Building b;                               // building object

}



#endif








