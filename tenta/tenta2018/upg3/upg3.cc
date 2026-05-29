#include <algorithm>
#include <iostream>
#include <vector>
#include <random>




bool is_prime(int n)
{
    if ( n < 2 || ( n > 2 && n % 2 == 0 ) )
        return false;
    for ( int i {3}; i < sqrt(n); i+=2 )
    {
        if ( n % i == 0 )
            return false;
    }
    return true;
}

int main()
{
    std::mt19937 rng;
    std::uniform_int_distribution<> dist(2, 75);
    std::vector<int> numbers(10);
    std::generate(numbers.begin(),numbers.end(), [&dist,&rng]
    {
        return dist(rng);
    });
    
    numbers.erase(std::remove_if(numbers.begin(),numbers.end(), [](int prime)
    {
        return ! is_prime(prime);
    }),numbers.end());

    std::sort(numbers.begin(),numbers.end());

    // int sum = std:: inner_product(numbers.begin(), numbers.end(),numbers.begin(), 0);

   
     int product{};
     std:: for_each(numbers.begin(),numbers.end(),
              [&product](int n)
              {
                  if(product != 0)
                  {
                      product = product * n ;
                  }
                  else
                  {
                      product = n ;
                  }
                  std::cout << n << " " ;
              });
  std::cout << "product: " << product << std::endl ;
     
        return 0;

        

} 
