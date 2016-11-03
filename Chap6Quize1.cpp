#include <iostream>

enum items
{
    ITEM_HEALTH_POTION,
    ITEM_TORCH,
    ITEM_ARROW,
    MAX_ITMES
};


int countTotalItems(int *items)
{
    int totalItems= 0;
    for (int index = 0; index < MAX_ITMES; ++index)
    
      totalItems += items[index]; 
    
    
    return totalItems; 
};


int main()
{
    int items[MAX_ITMES]={2,5,10};
    
    std::cout<<"Player has "<<countTotalItems(items)<<" items in total. \n";
    std::cout<<ITEM_ARROW<<"\n";
    
    return 0;
}