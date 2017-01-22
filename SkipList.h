#include "Student.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;


class SkipList{
  
public:

  //For Skiplist Functionality
  SkipList();
  bool insert(Student* s);
  bool find(std::string name);
  void remove(std::string name);

  //For TritonTag
  Student* getTarget(std::string name);
  void writeToFile(std::ofstream &out);
  //bool find(Student* s)

  //For Testing  
  int getLength();
  void printListInfo();

private:

  Student* head = new Student();

  //Testing purposes
  int length = 0;
};
