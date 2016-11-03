#include <iostream>
using namespace std;

float add(float num1,float num2)
{
    
    float num3 = num1 + num2;
    
    cout<<num1<<" + "<<num2<<" = "<<num3<<endl;
    
    return num3;
    
}


float divide(float num1,float num2)
{
    
    float num3 = num1 / num2;
    
    cout<<num1<<" / "<<num2<<" = "<<num3<<endl;
    
    return num3;
    
}

float multiply(float num1,float num2)
{
    
    float num3 = num1 * num2;
    
    cout<<num1<<" * "<<num2<<" = "<<num3<<endl;
    
    return num3;
    
}


float subtract(float num1,float num2)
{
    
    float num3 = num1 - num2;
    
    cout<<num1<<" - "<<num2<<" = "<<num3<<endl;
    
    return num3;
    
}


float enterNum()
{
    
    cout<<"Please enter number: ";
    float num;
    cin>>num;
    
    return num;
}

char getOperator()
{
    
    cout<<"Please enter either +, *, - or /:  "; 
    char symbol;
    cin>>symbol;
    
    return symbol;
}