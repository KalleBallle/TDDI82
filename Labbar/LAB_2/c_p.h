#include <iostream>
#ifndef C_P_H
#define C_P_H

//Komplettering -> saknas 
//Komplettering: Fråga 1 i answers.txt vad i node gör for-loopen möjlig? 

//Komplettering: Funktioner som är konstanta ska innebära att man inte kan ändra på det som pekas på. 
//Det ska finnas två varianter av ´operator*´, ´operator->´ och ´get()´
// en för när pekaren är konstant och en när den inte är det. 
// och det är bara med hjälp av den icke-konstanta varianten som användaren får ändra på den underliggande datan. 

template <typename T>
class c_p
{
public:
  c_p(T* const& obj);
  c_p();
  c_p(c_p const& pointer);
    c_p(c_p && pointer);
    ~c_p();

    T& operator*();
    const T& operator*() const;
    c_p<T>& operator=( std::nullptr_t pointer);
    c_p<T>& operator=(const c_p& other);
    // c_p<T>& operator=(const c_p& other) const;
    c_p<T>& operator=(c_p&& other);
    // c_p<T>& operator=(c_p&& other) const; 
  
    
  
  bool operator==(const c_p&) const;
  bool operator!=(const c_p&) const;
  
  int get_counter() const;
    void print_obj() const;
    int use_count() const;
    
    const T* get() const;
    T* get();
    T* operator->();
    const T* operator->() const;

private:
  T* obj;  
  int* counter;
  void delete_cp();  
};

#include "c_p.tcc" 
#endif
