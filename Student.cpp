#include "Student.h"

Student::Student(){
  name = "";
  email = "";
  team = "";
  target = 0;
}

Student::Student(std::string n){
  name = n;
  email = "";
  team = "";
  target = 0;
}

Student::Student(std::string n, std::string e, std::string t){
  name = n;
  email = e;
  team = t;
  target = 0;
}

bool Student::operator==(const Student& other)
{
  if(this->name == other.name && 
     this->email == other.email &&
     this->team == other.team)
  {
    return true;
  }else{
    return false;
  }
}

bool Student::operator!=(const Student& other)
{
  return !(*this == other);
}

bool Student::operator>(const Student& other)
{
  return this->name > other.name;
}

bool Student::operator>=(const Student& other)
{
  return this->name>=other.name;
}

