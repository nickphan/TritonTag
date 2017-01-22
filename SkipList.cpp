#include "SkipList.h"

SkipList::SkipList()
{
  for(int i = 0; i < 4; i++){
    head->next.push_back(NULL);
  }
}

/*

  Insert method.
  Inserts students into the skiplist

  Param: s, the student object we are inserting
  Return: true if the student was successfully inserted. false otherwise

*/

bool SkipList::insert(Student* s)
{

  
  Student* curr = head;
  int levels = head->next.size()-1;
  
  std::vector<Student*> toFix;
  for(int i = 0; i < head->next.size(); i++){
    toFix.push_back(NULL);
  }
  
  while(levels >= 0)
  {

    if(curr->next[levels] == NULL || *(curr->next[levels]) > *s){
      toFix[levels] = curr;
      levels--;
    }else{
      curr = curr->next[levels];
    }
    if(*curr == *s){
      return false;
    }
    
  }

  int height = 1;
  
  while(height < head->next.size())
  {
    int result = rand() % 1000; //result is 0-1000
    if(result <= 200){		//0.025 chance
      height++;
    }else{
      break;
    }
  }

  for(int i = 0; i < height; i++)
  {
    s->next.push_back(toFix[i]->next[i]);
    toFix[i]->next[i] = s;
  }
  length++;

  return true;

  
}


/*

  Find by name.
  Finds whether or not there exists a student with a certain name in list

  Param: name, the name of student to look for
  Return: whether or not the student exists

*/


bool SkipList::find(std::string name)
{
  Student* curr = head;
  int levels = head->next.size()-1;

  while(levels >= 0)
  {
    if(curr->next[levels] == NULL || curr->next[levels]->name > name){
      levels--;
    }else{
      curr = curr->next[levels];
    }
    if(curr->name == name){
      return true;
    }
  }
  return false;
}


/*

  Remove method.
  Removes student from list and connects the adjacent students

  Param: name, the name of student to remove.

*/


void SkipList::remove(std::string name)
{
  Student* curr = head;
  Student* prev = head;
  int levels = head->next.size()-1;

  while(levels >= 0)
  {
    if(curr->next[levels] == NULL || curr->next[levels]->name > name){
      levels--;
    }else{
      prev = curr;
      curr = curr->next[levels];
    }
    if(curr->name == name){
      break;
    }
  }
  for(int i = 0; i <= levels; i++){
    prev->next[i] = curr->next[i];
    
    //curr->prev[i]->next[i] = curr->next[i];
    //curr->next[i]->prev[i] = curr->prev[i];
  }
  length--;
}

/*
  
  For TritonTag Purposes.
  Returns the student after the one searched for in the list.
  This will be the target of the person searched for.

  Param: name, the name of the student searching for.
  Return: the student who is the target of the student in the parameter 

*/

Student* SkipList::getTarget(std::string name)
{
  Student* curr = head;
  int levels = head->next.size()-1;
  
  while(levels >= 0)
  {
    if(curr->next[levels] == NULL || curr->next[levels]->name > name){
      levels--;
    }else{
      curr = curr->next[levels];
    }
    if(curr->name == name){
      if(curr->next[0] != NULL){
        return curr->next[0];
      }else{
        if(head->next[0] != NULL){
          return head->next[0];
        }else{
          //ONLY 1 PERSON IN LIST
        }
      }
    }
  }
  Student* s;
  return s;

}


/*

  Writes the list to ofstream.

  Param: out, the outfile

*/
void SkipList::writeToFile(std::ofstream &out)
{
  Student* curr = head->next[0];
  while(curr != NULL){
    out << curr->name + '\t' + curr->email + '\t' + curr->team + '\t' + curr->target->name << '\n';
    if(curr->next[0] != NULL){
      curr = curr->next[0];
    }else{
      break;
    }
  }
}


int SkipList::getLength()
{
  return length;
}

void SkipList::printListInfo()
{
  Student* curr = head->next[0];
  while(curr != NULL){
    cout << curr->name << "'s target is " << curr->target->name << endl;
    if(curr->next[0] != NULL){
      curr = curr->next[0];
    }else{
      break;
    }
  }
}


