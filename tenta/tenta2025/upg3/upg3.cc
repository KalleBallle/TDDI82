#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <stdexcept>
#include <vector>

// Implementera Pair_Sum_Container hÃ¤r

template<typename right_container,typename left_container >
class   Pair_Sum_Container
{

public:
    Pair_Sum_Container(right_container const& rhs,
                       left_container const& lhs)
        :Right_Container{rhs},Left_Container{lhs}
    {

    }
    
    int size()
    {
        if(Right_Container.size() < Left_Container.size())
        {
            return static_cast<int>(Right_Container.size());
        }
        else
        {
 return static_cast<int>(Left_Container.size());
        }
    }
    
   typename right_container::value_type operator[](int const index)
    {

        
        if( index > size())
        {
            throw std::logic_error("fel pucko");
        }
       auto  rit = std::next(Right_Container.begin(),index);
        auto lit = std::next(Left_Container.begin(),index);

                                 
         return *rit + *lit ;
    }

private:
    right_container Right_Container;
    left_container Left_Container;

 
};


int main()
{
    
    
    {
        std::cout << "==== Testfall #1 ===="<< std::endl;

        using Left  = std::vector<int>;
        using Right = std::vector<int>;

        Left  left  { 1, 2, 3, 4 };
        Right right { 2, 3, 4, 5 };

        Pair_Sum_Container<Left, Right> p { left, right };

        // Testa undantag
        try 
        { 
            p[1000];
            std::cout << "Ett lÃ¤mpligt undantag kastades ej!"
                      << std::endl;
            return 0;
        }
        catch (std::exception&) { }

        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "==== Testfall #2 ===="<< std::endl;

        using Left  = std::set<double>;
        using Right = std::list<int>;

        Left  left  { 1.75, 2.5, 3.25, 4.0 };
        Right right { 4, 3, 2, 1 };

        Pair_Sum_Container<Left, Right> p { left, right };
        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "==== Testfall #3 ===="<< std::endl;

        using Left  = std::vector<std::string>;
        using Right = std::list<std::string>;

        Left  left  { "Christ", "E", "Mal", "Ni", "Pon", "T" };
        Right right { "offer", "ric", "te", "ls", "tus", "im" };

        Pair_Sum_Container<Left, Right> p { left, right };
        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }
    
}
