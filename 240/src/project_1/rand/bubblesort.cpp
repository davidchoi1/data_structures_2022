#include<iostream>
int main ()
{
   int i, j,temp,pass=0;
   int a[10] = {10,2,0,14,43,25,18,1,5,45};
   std::cout <<"Input list ...\n";
   for(i = 0; i<10; i++) {
      std::cout << a[i] <<"\t";
   }
std::cout << std::endl;
for(i = 0; i<10; i++) {
   for(j = i+1; j<10; j++)
   {
      if(a[j] < a[i]) {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }
pass++;
}
std::cout <<"Sorted Element List ...\n";
for(i = 0; i<10; i++) {
   std::cout <<a[i]<<"\t";
}
std::cout<<"\nNumber of passes taken to sort the list:"<<pass<<std::endl;
return 0;
}