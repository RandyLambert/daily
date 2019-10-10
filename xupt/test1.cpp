#include <iostream>
int f( int x)
         {

              return (x>0)?x*f(x-1):2;

          }
          int main()

          {

             int i  ;
             i=f(f(1));

             printf("%d",i);

          }

