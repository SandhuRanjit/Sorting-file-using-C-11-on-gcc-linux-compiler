#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<memory>

using namespace std;

struct  name_score
{
  std::string first;
  std::string second;
  int score;
  name_score(std::string _first,std::string _second,int _score)
  :first(_first)
  ,second(_second)
  ,score(_score)
{}
};


struct {
bool operator()( std::shared_ptr<name_score>& a, std::shared_ptr<name_score>& b)
 { 
    if( a->score > b->score) {
      return true;
   }
   else if(a->score < b->score) {
     return false;
   }
   if(a->first.compare(b->first) == 0 && a->second.compare(b->second) == 0) {
     return true;
   }
 
  if(a->first.compare(b->first) == 0 ) {
    if(a->second.compare(b->second) > 0) {
        return false;
    }
    else {
      return true;
    }
  }

  if(a->second.compare(b->second) == 0 ) {
    if(a->first.compare(b->first) > 0) {
        return false;
    }
    else {
      return true;
    }
  }    

 }
}cmp;  

