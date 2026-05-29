#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include "c_p.h" 

template <typename T>
class Node
{
public:
    
    Node(T value = 0);

    void insert(c_p<Node<T>> node);
    void remove(c_p<Node<T>> node);

    typename std::vector<c_p<Node<T>>>::const_iterator begin() const;
    typename std::vector<c_p<Node<T>>>::const_iterator end() const;

public:

   T value { };

private:

    std::vector<c_p<Node<T>>> neighbours { }; 

};

template <typename T>

std::vector<c_p<Node<T>>> get_all_nodes( c_p<Node<T>> root);
#include "node.tcc"

#endif
