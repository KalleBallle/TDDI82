template <typename T>
c_p<T>::c_p(T* const& obj)
  : obj{obj}, counter{new int{1}} {}
    
template <typename T>
c_p<T>::c_p()
  : obj{nullptr}, counter{nullptr} {}

template <typename T>
c_p<T>::c_p(c_p const& pointer)
  : obj{pointer.obj}, counter{pointer.counter}
{
  ++(*counter);
}

template <typename T>
c_p<T>::c_p(c_p && pointer)
  :obj{pointer.obj},counter{pointer.counter}  
{
  pointer.counter = nullptr;
  pointer.obj = nullptr;
}

template <typename T>
c_p<T>& c_p<T>::operator=(const c_p& other) 
{
  if(other.obj == obj)
  {
    return *this;
  }
  delete_cp();
  obj = other.obj;
  counter = other.counter;
  ++(*counter);
  return *this;
}

/*
template <typename T>
c_p<T>& c_p<T>::operator=(const c_p& other) const
{
  if(other.obj == obj)
  {
    return *this;
  }
  delete_cp();
  obj = other.obj;
  counter = other.counter; 
  ++(*counter);
  return *this;
}
*/
template <typename T>
const T& c_p<T>::operator*() const
{
  return *obj;
}

template <typename T>
T& c_p<T>::operator*() 
{
  return *obj;
}

template <typename T>
c_p<T>& c_p<T>::operator=(std::nullptr_t pointer)
{
  delete_cp();
  obj = pointer;
  counter = pointer;
  return *this;
}

template <typename T>
c_p<T>& c_p<T>::operator=(c_p&& other)
{
  delete_cp();
  obj = other.obj;
  counter = other.counter;
  other.counter = nullptr; 
  other.obj = nullptr; 
  return *this;
}
/*
template <typename T>
c_p<T>& c_p<T>::operator=(c_p&& other) const
{
  delete_cp(); 
  obj = other.obj;
  counter = other.counter;
  other.counter = nullptr; 
  other.obj = nullptr; 
  return *this;
}
*/
template <typename T>
void c_p<T>::print_obj() const
{
  std::cout << *obj;
}
template <typename T>
int c_p<T>::get_counter() const 
{
  return *counter;
}

template <typename T>
bool c_p<T>::operator==(c_p const & other) const
{
  return obj == other.obj;
}

template <typename T>
bool c_p<T>::operator!=(c_p const & other) const
{
  return obj != other.obj;
}

template <typename T>
int c_p<T>::use_count() const
{
  if(counter == nullptr)
  {
    return 0;
  } else {
    return *counter;
  }
}

template <typename T>
const T* c_p<T>::get() const
{
  return obj;
}

template <typename T>
T* c_p<T>::get()
{
  return obj;
}

template <typename T>
c_p<T>::~c_p()
{ 
  delete_cp();
}

template <typename T>
void c_p<T>::delete_cp()
{ 
  if(counter != nullptr)
  {
    --(*counter);
    if(*counter == 0)
    {
      delete counter;
      delete obj;
    }
  }
  
}
template <typename T> 
  T* c_p<T>::operator->()
{
    return obj ;
}
template <typename T> 
  const T* c_p<T>::operator->() const
{
    return obj ;
}
