
#include <algorithm>
#include <sstream>
#include <fstream>
#include <set>
#include <string>
#include <iostream>
#include <iterator>

std::set<std::string> read(std::ifstream&  file)
{
   std::set<std::string> books;
     std::string line{};
      if(    std::getline(file,line))
       { 
      
           std::istringstream iss{line};
           std::string word{};
           //när du gör >> från en strängstörm dellar det automatiskt upp de på mellanrumen 
           while(iss >> word)
           {
             books.insert(word);
           } 

       }
      return books;

}

int main()
{
   std::ifstream file{};
   file.open("books.txt");
   std::set<std::string> Chris;
   
     std::set<std::string> Erik;
     
   if(file.is_open())
   {
           
       Chris = read(file);
       Erik = read(file);
   }       
   else
   {
       std::cout << "failed" ;
   }
   

   for_each(Erik.begin(),Erik.end(),[&](std::string s)
   {
      
       
 std::cout << " "<<  *Chris.find(s)  ;

       
                 });

       }
