#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>


int main()
{
    std::vector<int> num;   
    std::copy(std::istream_iterator<int>(std::cin),std::istream_iterator<int>(),std::back_inserter(num));
    std::cout <<std::endl <<  num[0];
 int sum = std::accumulate(num.begin(), num.end(), 0);
 num.erase(std::remove_if(num.begin(),num.end() ,
                       [&](int n)
                       { 
                           return (sum % n == 0);
                        
                               
                       }),num.end());
 
   std::sort(num.begin(), num.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  });

   std::cout << std::endl << "utskrift:" ;
   std::copy(num.begin(), num.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
   
}
