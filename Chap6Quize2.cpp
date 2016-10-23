#include <iostream>
#include <string>
#include <utility>

struct Student
{
    std::string name;
    int grade;
};

// void printInformation(Student pupil)
// {
//     std::cout<<"ID:   "<<pupil.id<<"\n";
//     std::cout<<"Name: "<<pupil.name<<"\n";
//     std::cout<<"Age:  "<<pupil.age<<"\n";
//     std::cout<<"Wage: "<<pupil.wage<<"\n";
    
// }

void sortGrade(Student *students, int length)
{
  for(int index = 0; index<length; ++index)
  {
      int largestIndex = index;
      
      for(int secIndex = index+1; secIndex<length; ++secIndex)
      {
          if (students[secIndex].grade > students[largestIndex].grade)
          {
              largestIndex = secIndex;
          };
      };
      
     std::swap(students[index], students[largestIndex]); 
  };
  
};

int main()
{

    // Student joe = {14,"Joe",32,24.150};
    // Student frank = {15,"Frank",28, 18.27};
    
    // printInformation(joe);
    
    // std::cout<<"\n";
    
    // printInformation(frank);
    
    std::cout<<"Number of students: "<<"\n";
    int size;
    std::cin>>size;
    
    Student *students = new Student[size];
    
    for(int index = 0; index < size; ++index)
    {
        std::cout<<"Enter student name: "<<"\n";
        std::cin>>students[index].name;
        
        std::cout<<"Enter student grade: "<<"\n";
        std::cin>>students[index].grade;
    };
    
    sortGrade(students, size);
    
    for(int index = 0; index<size; ++index)
    {
        std::cout<<students[index].name<<" has got a grade of "<<students[index].grade<<"\n";
        
    };
    
    delete [] students;
    
    return 0;
}