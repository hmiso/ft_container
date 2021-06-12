#include "test.hpp"

#include <stack>
#include "queue.hpp"
#include "avl_tree.hpp"
#include "map.hpp"
#include "map"
int main()
{

    // test_vector();
    // std::cout << "\n";
    // test_list();

    // std::cout << "\n";
    // test_queue();
    // std::cout << "\n";    
    // test_stack();
    // std::cout << "\n";
    // test_map();
    // std::cout << "\n";

    std::map<int, int> f;

    f[0] = 1;
    f[1] = 2;
    f[2] = 3;
    f[3] = 4;


    std::map<int, int>::iterator q;
    std::map<int, int>::iterator w;

    q = f.begin();
    w = f.end();

    std::cout << q->first << std::endl;
    ++q;
    std::cout << q->first << std::endl;
    ++q;
    std::cout << q->first << std::endl;
        
}