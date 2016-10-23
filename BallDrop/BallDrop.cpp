#include <iostream>

double getHeight()
{
    using namespace std;
    
    cout<<"Please enter height: ";
    double height;
    cin>>height;
    
    return height;
}

double getTime()
{
    using namespace std;
    
    cout<<"Please enter time in seconds: ";
    double seconds;
    cin>>seconds;
    
    return seconds;
}

double power(double num, double operand)
{
    using namespace std;
    
    //cout<<"Working"<<endl;
    
     double num2 = num;
    
    while(operand>1)
    {
        
        //cout<<operand<<endl;
        //cout<<num<<endl;
        
        num2 = num * num2;
        operand = operand-1;
        
        if(operand==1)
        {
            return num2;
            break;
        }
    }
}

//int main()
//{
    //using namespace std;
    
    //cout<<"Enter a number: ";
    //double num;
    //cin>>num;
    
    //cout<<"Enter the exponent: ";
    //double num2;
    //cin>>num2;
    
    //double num3=power(num, num2);
    
    //cout<<num3;
    
    //return 0;
//}