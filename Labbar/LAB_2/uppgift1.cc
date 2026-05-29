#include "c_p.h"
#include "string"
#include "iostream"
#include <vector>

int main()
{
    std::string* tjo{new std::string{ "hej"}} ;
      std::string* tjaba{new std::string{ "hejsan"}} ;
      std::vector<int>*  whalla{new  std::vector<int>{1,2,3,4,5}} ;
    c_p ett{tjo};
    c_p two{ett} ;
    c_p four{tjaba};
   const c_p five{whalla};
               std::cout << five->at(1) << std::endl;
    std::cout << *four;
    c_p<std::string> three{} ;
 


    three = ett ;
    ett.print_obj();
    std::cout << four.get_counter();
    four = std::move(ett);
    four = nullptr;
    // std::cout << ett.get_counter(); 
      std::cout << two.get_counter();
      if( three != four)
      {
          std::cout << "penis" ;
      }

      std::cout << two.use_count();
      std::cout << *two.get();
      
    return 0;
}
