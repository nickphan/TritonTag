#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Student{

public:
  //Student Info
  std::string name;
  std::string email;
  std::string team;
  Student* target;

  //Necessary node fields
  std::vector<Student*> next;

  //Functions
  Student();
  Student(std::string n);
  Student(std::string n, std::string e, std::string t);

  bool operator==(const Student& other);
  bool operator!=(const Student& other);
  bool operator>(const Student& other);
  bool operator>=(const Student& other);


private:


  /* we'll start this off with everything public*/


};


