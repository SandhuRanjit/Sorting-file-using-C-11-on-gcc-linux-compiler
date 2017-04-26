#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<memory>
#include"sort_file.h"
using namespace std;


void readfile(std::vector<std::shared_ptr<name_score> >& vec, std::string& filename)
{
   ifstream in(filename); 
   std::string strline;
   vector<string> vecstr;
  
   if(!in.is_open()) {
     return ;
   }
   try { 
   while (getline(in, strline)) {
     vecstr.push_back(strline);
     std::size_t pos = strline.find_first_of(",");
     std::string first="";
     std::string second="";
     int score =-1;  
     if(pos != std::string::npos) {
       first = strline.substr(0,pos);
     }
     else {
       continue;
     }
     std::size_t pos1 = strline.find_last_of(",");
     if(pos != std::string::npos) {
       second = strline.substr(pos+1,pos1);
     }
     else {
       continue;
     }
     score = stoi(strline.substr(pos1+1,strline.size()));
     if(!first.empty() && !second.empty() && score != -1) {
       vec.push_back(std::make_shared<name_score>(first,second,score)); 
     }  
    }
     
   }
   catch(...) {
    cout<<"something went: sorting aborted "; 
    in.close(); 
   }
   in.close();
};  



int main(int argc,char* argv[])
{
 if (argc < 2) {
   return 1;
 }  

 ofstream out("graded.txt");
 // read the file
 try { 
  string filename(argv[1]);
  cout<< filename;
  std::vector<std::shared_ptr<name_score> > vec; 
  readfile(vec,filename); 
  std::sort(vec.begin(),vec.end(),cmp);          
  for(auto it :vec) {
   cout<<it->first<<it->second; 
   cout<<it->score<<endl; 
   out<<endl; 
   out<<it->first<<","<<it->second<<","<<it->score;       
  }   
 }
 catch(...) {
  cout<<"some thing went wrong : aborting";
  out.close();
 }
 cout<<"Finished: created names-graded.txt"; 
 out.close();  
getchar();
}
