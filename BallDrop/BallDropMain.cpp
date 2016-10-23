#include <iostream>
#include "Constants.h"
#include "Drop.h"
#include "math.h"

double calculateHeight(double initalSec, double initalHeight)
{
    using namespace std;
    
    double distanceFallen;
    double height=initalHeight;
    double second = initalSec-initalSec;
    double mod = fmod(initalSec,1);
    //cout<<"At "<<second<<" seconds, the ball is at height: "<<initalHeight<<" meters"<<endl;
    
    while (second != (initalSec-mod))
    {
        distanceFallen = (myConstants::gravity*power(second, 2))/2;
        height = height - distanceFallen;
        //cout<<height<<" "<<distanceFallen<<endl;
        
        if (height<=0)
        {
            cout<<"At "<<second<<" seconds, the ball has hit the ground"<<endl;
            break;
        }
        else
        {
           cout<<"At "<<second<<" seconds, the ball is at height: "<<height<<" meters"<<endl;
           second = ++second;
           
            if (second == (initalSec-mod) && (mod!=0 or mod!=0.0))
            {
                mod = mod + second;
                
                if (height <= 0)
                {
                  cout<<"It hit the ground before the time ran out, current time is: "<< mod<<" seconds"<<endl;   
                }
                
                else
                {
                    distanceFallen = (myConstants::gravity*power(mod, 2))/2;
                    height = height - distanceFallen;
                    
                    if (height <= 0)
                    {
                        cout<<"At "<<second<<" seconds, the ball has hit the ground."<<endl;
                        break;
                    }
                    
                    else
                    {
                        cout<<"After "<<mod<<" seconds it didn't hit the ground, as it is "<<height<<" meters from the ground."<<endl;
                        break;
                    };
                };
                //second = second - mod;
                //mod = fmod(second,1);
                
            };
        };
        
        
    }
}

int main()
{
    double height = getHeight();
    double seconds = getTime();
    
    calculateHeight(seconds, height);
    
    return 0;
}
