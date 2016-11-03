#include <iostream>
#include "HiLo.h"


int main()
{
    bool play = true;
    while (play == true)
    {
        int randomNumber = getRandomNumber(1,10);
        
        for (int count = 1; count <8; count++)
        
        {
            using namespace std;
            
            cout<<"Round "<<count<<" of 7"<<endl;
            
            // cout<<randomNumber<<endl;
            
            int guess = getInt();
            
            if (guess == randomNumber)
            {
                cout<<"Congratulations You Win!"<<endl;
                break;
            }
            else if (guess > randomNumber)
            {
                cout<<"Too High, try again."<<endl;
            }
            else if (guess < randomNumber)
            {
                cout<<"Too Low, try again."<<endl;
            };
            
            if ((count+1) == 8)
            {
                cout<<"Sorry you failed to guess the number, it was: "<<randomNumber<<endl;
                break;
            };
        };
        
        
        char again = getChar();
        
        if (again == "Y" || again == "y")
        {
            continue;
        }
        else
        {
            cout<<"Goodbye, Hope to see you soon!"<<endl;
            break;
        }
    };
    
    return 0;
}