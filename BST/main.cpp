#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main()
{
    int treeKeys[16] {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    
    BST myTree;
    
    cout << "Printing tree in order before adding numbers: \n";
    
    myTree.printInOrder();
    
    for(int i = 0; i < 16; i++)
    {
       myTree.addLeaf(treeKeys[i]); 
    }
    
    cout << "Printing tree in order after adding numbers: \n";
    
    myTree.printInOrder();
    
    cout << endl;
    
    cout << " " << endl;
    
    for(int i = 0; i < 16; i++)
    {
       myTree.printChildren(treeKeys[i]);
       cout << endl;
    }
    
    int smallest = myTree.findSmallest();
    
    cout << "The smallest number in the the is: " << smallest << endl;
    
    cout << " " << endl;
    
    cout << "Enter a value to delete or alternatly enter -1 to exit \n";
    int input = 0;
    while(input != -1)
    {
        cout << "Delete Node: ";
        cin >> input;
        {
            if(input != -1)
            {
                cout << endl;
                myTree.removeNode(input);
                myTree.printInOrder();
                cout << endl;
            }
        }
    }
    
    return 0;
}