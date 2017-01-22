#include <iostream>
#include <fstream>
#include <sstream>

#include "SkipList.h"
using namespace std;




int main(int argc, char** argv){
  if(argc != 2){
    cout << "Invalid number of args" << endl;
    return 0;
  }

  std::string filename = argv[1];
  filename = filename.c_str();

  std::ifstream infile;
  infile.open(filename);

  vector<Student*> students;
  vector<Student*> targets;

  while(infile){
    string s;
    if(!getline(infile, s)){
      break;
    }

    istringstream ss(s);
    vector<std::string> record;

    while(ss){
      string next;
      if(!getline(ss, next, '\t')){
        break;
      }
      record.push_back(next);
    }
    
    /* record has each line parsed by tab*/
    /* Expecting name, email, team*/
    Student* studentToAdd = new Student(record[0], record[1], record[2]);
    students.push_back(studentToAdd);
    targets.push_back(studentToAdd);

  }
  infile.close();
  //students has all of the students

  SkipList list;

  for(unsigned int i = 0; i < students.size(); i++){
    Student* curr = students[i];
    int r = i;
    while(r == i){
      r = rand() % targets.size();
    }
    Student* targ = targets[r];
    curr->target = targ;
    targets.erase(targets.begin()+r);
    list.insert(curr);
  }

  std::ofstream outfile;
  outfile.open("GameFile.txt");

  outfile << "Name<TAB>Email<TAB>Team<TAB>Target\n";
  list.writeToFile(outfile);
  outfile.close();
}
