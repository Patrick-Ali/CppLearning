#include <iostream>
#include "io_float.h"

int main()
{
    using namespace std;
    
    float num1 = enterNum();
    
    float num2 = enterNum();
    
    while (true)
    
    {
         
        char symbol = getOperator();
        
        if (symbol == '+')
        {
            cout<<"Adding..."<<endl;
            
            float num3 = add(num1,num2);
        
            break;
        }
        else if (symbol == '*')
        {
            cout<<"Multiplying..."<<endl;
            
            float num3 = multiply(num1,num2);
    
            break;
        }
        else if (symbol == '-')
        {
            cout<<"Subtracting..."<<endl;
            
            float num3 = subtract(num1,num2);
        
            break;
        }
        else if (symbol == '/')
        {
            cout<<"Dividing..."<<endl;
            
            float num3 = divide(num1,num2);
    
            break;
        }
        else
        {
            cout<<"Invalid input, please try again."<<endl;
            continue;
        };
    };

    return 0;
}