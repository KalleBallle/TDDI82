#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string> 
#include <vector>
//#include <list>
#include <algorithm>

std::vector<std::string> read_file(std::string filename)
{
  std::ifstream file{};
  //std::vector<std::string> text ;
  //std::string line{};

  file.open(filename);

  if(file.is_open())
   {
      return std::vector<std::string>(std::istream_iterator<std::string>(file),
				 std::istream_iterator<std::string>());
    }
  else 
   {  
    throw std::logic_error("testa ett annat fillnamn");
  };
}

void print(const std::vector<std::string> & text)
{
  std::for_each(text.cbegin(), text.cend(), [](std::string s ) {std::cout << s << ' ';} );
  std::cout << std::endl;
}

void print_unique(std::vector<std::string>  & text)
{
  std::string longest_word {} ;
  longest_word = *max_element(text.begin(),text.end(),[text](std::string word1, std::string word2 ) {return word1.size() < word2.size();});
  		
  for_each(text.begin(),unique(text.begin(),text.end()),
	   [text,longest_word](std::string word)
	   {
	     std::cout << std::setw(longest_word.size()) << word << ' ' << count(text.begin(),text.end(),word) << std::endl;
	   }
	   );
    
}

void remove_word(std::vector<std::string> & text, std::string parameter)
{
  text.erase(std::remove(text.begin(),text.end(),parameter),text.end());
}

void substitute(std::vector<std::string> & text, std::string  parameter)
{
  std::string old_word{parameter};
    old_word.erase(std::find(old_word.begin(),old_word.end(),'+') ,old_word.end());
  std::string new_word{parameter.substr(parameter.find_first_of('+') + 1)};
  std::replace(text.begin(), text.end(), old_word, new_word);
}

void table(std::vector<std::string>   text)
{
  std::sort(text.begin(), text.end());
  std::cout << std::left;
  print_unique(text);	   
}

void frequency(std::vector<std::string>  text)
{
  std::sort(text.begin(), text.end(),
	    [text](std::string word1, std::string word2)
	    {
	      int num1{(int)std::count(text.begin(), text.end(), word1)};
	      int num2{(int)std::count(text.begin(), text.end(), word2)};
	      return num1 > num2 ;
	    });

  std::cout << std::right;
  print_unique(text);
}

int main(int argc, char** argv)
{ 
  std::vector<std::string> text{};
  std::string filename{};
  std::vector<std::string> arguments{argv,argv+argc};

  arguments.erase(arguments.begin()); //Tar bort "/a.out
  filename = *arguments.begin();
  arguments.erase(arguments.begin());

  try {
    text = read_file(filename);
} catch (const std::logic_error & e) {
    std::cerr << "Error: Could not open file \"" << filename << "\" — " << e.what() << std::endl;
    return 1;
}

  for(std::string a : arguments)
    {
      std::string flag{a};
      std::string parameter{};
   
      if (a.find('=') != a.npos)
	{
	  flag.erase(std::find(flag.begin(),flag.end(),'='),flag.end());
	  parameter = a.substr(a.find_first_of('=') + 1);
	}

      if(flag == "--print")
	{
	  print(text);
	}
      else if(flag == "--table")
	{
	  table(text);
	}
      else if (flag == "--frequency")
	{
	  frequency(text);
	}
      else if (flag == "--remove")
	{
	  remove_word(text, parameter);
	}
      else if (flag == "--substitute")
	{
	  substitute(text, parameter);
	}
      else
	{ 
	  std::cout<< std::endl << "!!!" << flag << " är inte ett giltigt kommando !!!" << std::endl << std::endl ;
	}
	
    }
}

