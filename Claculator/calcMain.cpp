#include <iostream>
#include "io.h"


int main()
{
    using namespace std;
    
    int num1 = enterNum();
    
    int num2 = enterNum();
    
    int num3 = add(num1,num2);
    
    cout<<"Adding..."<<endl;
    
    cout<<num1<<" + "<<num2<<" = "<<num3<<endl; 
    
    return 0;
}