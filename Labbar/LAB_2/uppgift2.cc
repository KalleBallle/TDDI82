
#include "node.h"
#include "c_p.h"
#include <string>
   
#include <iostream>
   
c_p<Node<std::string>> create_example()
{
    c_p<Node<std::string>> n0 { new Node<std::string> { "olof" } };
    c_p<Node<std::string>> n1 { new Node<std::string> { "karl" } };
    c_p<Node<std::string>> n2 { new Node<std::string> { "david" } };
    c_p<Node<std::string>> n3 { new Node<std::string> { "hugo" } };
    c_p<Node<std::string>> n4 { new Node<std::string> { "stanic" } };
    c_p<Node<std::string>> n5 { new Node<std::string> { "hej" } };
  
  
  
    n0.get()->insert(n1);
  
    n0.get()->insert(n2);
    n1.get()->insert(n5);
    n2.get()->insert(n3);
    n2.get()->insert(n4);
    n3.get()->insert(n4);
    n3.get()->insert(n5);
  
    return n0;
}
  
void print_nodes(std::vector<c_p<Node<std::string>>> nodes)
{
    for ( c_p<Node<std::string>> node : nodes)
    {
        std::cout << node.get()->value << " ";
    }
    std::cout << std::endl;
}
  
int main()
{
    c_p<Node<std::string>> root { create_example() };
    std::vector< c_p<Node<std::string>>> nodes { get_all_nodes(root) };
 
    std::cout << "After insertions: " << std::endl;
    print_nodes(nodes);
 
    root.get()->remove(nodes[2]);
 
    nodes = get_all_nodes(root);
 
    std::cout << "After removal: " << std::endl;
    print_nodes(nodes);

}

