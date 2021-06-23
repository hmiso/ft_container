#include <iostream>
#include "map.hpp"
#include <map>

template <typename iterator>
void print_iterators(iterator a, iterator b) {
    while (a != b) {
        std::cout << *a++ << " ";
    }
    std::cout << std::endl;
}

template<class _Map>
void print_map(_Map& m)
{
    typename _Map::iterator it = m.begin();
    typename _Map::iterator end = m.end();
    while (it != end)
    {
        std::cout << "{" << it->first << "=" << it->second << "} ";
        it++;
    }
    std::cout << std::endl;
}


void test_ft_constructor()
{
    ft::map<std::string, int> def;
    def.insert(std::pair<std::string, int>("a", 1));
    def.insert(std::pair<std::string, int>("b", 2));
    def.insert(std::pair<std::string, int>("c", 3));
    def.insert(std::pair<std::string, int>("d", 4));
    def.insert(std::pair<std::string, int>("e", 5));
    def.insert(std::pair<std::string, int>("b", 10));
    std::cout << "def contains:" << " ";
    print_map(def);

    ft::map<std::string, int>   mCopy(def);
    std::cout << "mCopy contains:" << " ";
    print_map(mCopy);

    ft::map<std::string, int>   mRange(mCopy.begin(), mCopy.end());
    std::cout << "mRange contains:" << " ";
    print_map(mRange);

    ft::map<std::string, int>   mAssign;
    mAssign = mRange;
    std::cout << "mAssign contains:" << " ";
    print_map(mAssign);
    std::cout << std::endl;
}

void test_std_constructor()
{
    std::map<std::string, int> def;
    def.insert(std::pair<std::string, int>("a", 1));
    def.insert(std::pair<std::string, int>("b", 2));
    def.insert(std::pair<std::string, int>("c", 3));
    def.insert(std::pair<std::string, int>("d", 4));
    def.insert(std::pair<std::string, int>("e", 5));
    def.insert(std::pair<std::string, int>("b", 10));
    std::cout << "def contains:" << " ";
    print_map(def);

    std::map<std::string, int>   mCopy(def);
    std::cout << "mCopy contains:" << " ";
    print_map(mCopy);

    std::map<std::string, int>   mRange(mCopy.begin(), mCopy.end());
    std::cout << "mRange contains:" << " ";
    print_map(mRange);

    std::map<std::string, int>   mAssign;
    mAssign = mRange;
    std::cout << "mAssign contains:" << " ";
    print_map(mAssign);
    std::cout << std::endl;
}

void test_ft_index_operator()
{
    ft::map<std::string, int> mapa;
    mapa.insert(std::pair<std::string, int>("a", 1));
    mapa.insert(std::pair<std::string, int>("b", 2));
    mapa.insert(std::pair<std::string, int>("c", 3));
    std::cout << "mapa contains:" << " ";
    print_map(mapa);
    mapa["HELLO"] = 10;
    mapa["b"] = 11;
    print_map(mapa);
    std::cout << std::endl;
}

void test_std_index_operator()
{
    std::map<std::string, int> mapa;
    mapa.insert(std::pair<std::string, int>("a", 1));
    mapa.insert(std::pair<std::string, int>("b", 2));
    mapa.insert(std::pair<std::string, int>("c", 3));
    std::cout << "mapa contains:" << " ";
    print_map(mapa);
    mapa["HELLO"] = 10;
    mapa["b"] = 11;
    print_map(mapa);
    std::cout << std::endl;
}

void test_ft_capacity()
{
    std::cout << "* FT CAPACITY *" << std::endl;
    ft::map<int, int> map1;
    map1.insert(std::pair<int, int>(1, 2));
    map1.insert(std::pair<int, int>(2, 3));
    map1.insert(std::pair<int, int>(3, 4));

    std::cout << "map1 contains: " << " ";
    print_map(map1);
    std::cout << "map1 SIZE(): " << map1.size() << std::endl;
    std::cout << "map1 EMPTY(): " << map1.empty() << std::endl;
    std::cout << "map1 MAX_SIZE(): " << map1.max_size() << std::endl;

    ft::map<int, int> map2;
    std::cout << "map2 SIZE(): " << map2.size() << std::endl;
    std::cout << "map2 EMPTY(): " << map2.empty() << std::endl;
    std::cout << "map2 MAX_SIZE(): " << map2.max_size() << std::endl;
    std::cout << std::endl;
}

void test_std_capacity()
{
    std::cout << "* FT CAPACITY *" << std::endl;
    std::map<int, int> map1;
    map1.insert(std::pair<int, int>(1, 2));
    map1.insert(std::pair<int, int>(2, 3));
    map1.insert(std::pair<int, int>(3, 4));

    std::cout << "map1 contains: " << " ";
    print_map(map1);
    std::cout << "map1 SIZE(): " << map1.size() << std::endl;
    std::cout << "map1 EMPTY(): " << map1.empty() << std::endl;
    std::cout << "map1 MAX_SIZE(): " << map1.max_size() << std::endl;

    std::map<int, int> map2;
    std::cout << "map2 SIZE(): " << map2.size() << std::endl;
    std::cout << "map2 EMPTY(): " << map2.empty() << std::endl;
    std::cout << "map2 MAX_SIZE(): " << map2.max_size() << std::endl;
    std::cout << std::endl;
}

void test_ft_clear()
{
    std::cout << "* FT CLEAR *" << std::endl;
    ft::map<int, int> mapa;
    mapa.insert(std::pair<int, int>(1, 2));
    mapa.insert(std::pair<int, int>(2, 3));
    mapa.insert(std::pair<int, int>(3, 4));
    mapa.insert(std::pair<int, int>(4, 5));    
    mapa.insert(std::pair<int, int>(5, 6));    
    std::cout << "before clear:" << " ";
    print_map(mapa);
    std::cout << "mapa SIZE(): " << mapa.size() << std::endl;
    mapa.clear();
    std::cout << "after clear:" << " ";
    print_map(mapa);
    std::cout << "mapa SIZE(): " << mapa.size() << std::endl;
    std::cout << std::endl;
}

void test_std_clear()
{
    std::cout << "* STD CLEAR *" << std::endl;
    std::map<int, int> mapa;
    mapa.insert(std::pair<int, int>(1, 2));
    mapa.insert(std::pair<int, int>(2, 3));
    mapa.insert(std::pair<int, int>(3, 4));
    mapa.insert(std::pair<int, int>(4, 5));
    mapa.insert(std::pair<int, int>(5, 6));
    std::cout << "before clear:" << " ";
    print_map(mapa);
    std::cout << "mapa SIZE(): " << mapa.size() << std::endl;
    mapa.clear();
    std::cout << "after clear:" << " ";
    print_map(mapa);
    std::cout << "mapa SIZE(): " << mapa.size() << std::endl;
    std::cout << std::endl;
}

void test_ft_insert()
{
    std::cout << "* FT INSERT *" << std::endl;
    ft::map<std::string, int> mapa;
    mapa.insert(std::pair<std::string, int>("a", 1));
    mapa.insert(std::pair<std::string, int>("b", 2));
    mapa.insert(std::pair<std::string, int>("c", 3));
    std::cout << "mapa contains:" << " ";
    mapa.insert(++++mapa.begin(), std::pair<std::string, int>("d", 4));
    print_map(mapa);
    
    ft::map<std::string, int>   mapp;
    mapp.insert(mapa.begin(), mapa.end());
    std::cout << "mapp contains:" << " ";
    print_map(mapp);
    std::cout << std::endl;
}

void test_std_insert()
{
    std::cout << "* STD INSERT *" << std::endl;
    std::map<std::string, int> mapa;
    mapa.insert(std::pair<std::string, int>("a", 1));
    mapa.insert(std::pair<std::string, int>("b", 2));
    mapa.insert(std::pair<std::string, int>("c", 3));
    std::cout << "mapa contains:" << " ";
    mapa.insert(++++mapa.begin(), std::pair<std::string, int>("d", 4));
    print_map(mapa);
    
    std::map<std::string, int>   mapp;
    mapp.insert(mapa.begin(), mapa.end());
    std::cout << "mapp contains:" << " ";
    print_map(mapp);
    std::cout << std::endl;
}

void test_ft_erase()
{
    std::cout << "* FT ERASE *" << std::endl;
    ft::map<int, int> mapa;
    mapa.insert(std::pair<int, int>(3, 1));
    mapa.insert(std::pair<int, int>(2, 2));
    mapa.insert(std::pair<int, int>(1, 3));
    std::cout << "mapa contains:" << std::endl;
    print_map(mapa);

    ft::map<int,int>::iterator it = mapa.begin();
    ft::map<int, int>::iterator tmp(it++);
    mapa.erase(tmp);
    std::cout << "after erase:" << " ";
    print_map(mapa);
    std::cout << "after second erase:" << " ";
    mapa.erase(mapa.begin(), mapa.end());
    print_map(mapa);
    std::cout << std::endl;
}

void test_std_erase()
{
    std::cout << "* FT ERASE *" << std::endl;
    std::map<int, int> mapa;
    mapa.insert(std::pair<int, int>(3, 1));
    mapa.insert(std::pair<int, int>(2, 2));
    mapa.insert(std::pair<int, int>(1, 3));
    std::cout << "mapa contains:" << std::endl;
    print_map(mapa);

    std::map<int,int>::iterator it = mapa.begin();
    std::map<int, int>::iterator tmp(it++);
    mapa.erase(tmp);
    std::cout << "after erase:" << " ";
    print_map(mapa);
    std::cout << "after second erase:" << " ";
    mapa.erase(mapa.begin(), mapa.end());
    print_map(mapa);
    std::cout << std::endl;
}

void test_ft_swap()
{
    ft::map<int, int> m;
    m.insert(std::pair<int, int>(10, 9));
    m.insert(std::pair<int, int>(9, 8));
    m.insert(std::pair<int, int>(8, 7));
    m.insert(std::pair<int, int>(7, 6));
    std::cout << "m contains:" << " ";
    print_map(m);

    ft::map<int, int> m1;
    m1.insert(std::pair<int, int>(5, 4));
    m1.insert(std::pair<int, int>(4, 3));
    m1.insert(std::pair<int, int>(3, 2));
    m1.insert(std::pair<int, int>(2, 1));
    std::cout << "m1 contains:" << " ";
    print_map(m1);

    m1.swap(m);
    std::cout << "after swap:" << std::endl;
    std::cout << "m contains:" << " ";
    print_map(m);
    std::cout << "m1 contains:" << " ";
    print_map(m1);
    std::cout << std::endl;
}

void test_std_swap()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(10, 9));
    m.insert(std::pair<int, int>(9, 8));
    m.insert(std::pair<int, int>(8, 7));
    m.insert(std::pair<int, int>(7, 6));
    std::cout << "m contains:" << " ";
    print_map(m);

    std::map<int, int> m1;
    m1.insert(std::pair<int, int>(5, 4));
    m1.insert(std::pair<int, int>(4, 3));
    m1.insert(std::pair<int, int>(3, 2));
    m1.insert(std::pair<int, int>(2, 1));
    std::cout << "m1 contains:" << " ";
    print_map(m1);

    m1.swap(m);
    std::cout << "after swap:" << std::endl;
    std::cout << "m contains:" << " ";
    print_map(m);
    std::cout << "m1 contains:" << " ";
    print_map(m1);
    std::cout << std::endl;
}

void test_ft_count()
{
    ft::map<int, int> m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));
    if (m.count(300))
        std::cout << "The key 300 is present" << std::endl;
    else
        std::cout << "The key 300 is not present" << std::endl;

    if (m.count(500))
        std::cout << "The key 500 is present" << std::endl;
    else
        std::cout << "The key 500 is not present" << std::endl;
}

void test_std_count()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));
    if (m.count(300))
        std::cout << "The key 300 is present" << std::endl;
    else
        std::cout << "The key 300 is not present" << std::endl;

    if (m.count(500))
        std::cout << "The key 500 is present" << std::endl;
    else
        std::cout << "The key 500 is not present" << std::endl;
}

void test_ft_find()
{
    ft::map<int, int> m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));

    if (m.find(300) == m.end())
        std::cout << "300 is Not found" << std::endl;
    else
        std::cout << "300 is Found" << std::endl;

    if (m.find(1000) != m.end())
        std::cout << "1000 is Found" << std::endl;
    else
        std::cout << "1000 is Not found" << std::endl;
}

void test_std_find()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));

    if (m.find(300) == m.end())
        std::cout << "300 is Not found" << std::endl;
    else
        std::cout << "300 is Found" << std::endl;

    if (m.find(1000) != m.end())
        std::cout << "1000 is Found" << std::endl;
    else
        std::cout << "1000 is Not found" << std::endl;
}

void test_ft_equal_range()
{
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    std::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;
}

void test_std_equal_range()
{
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;
}

void test_ft_lower_upper_bound()
{
    ft::map<int, int>    m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));
    m.insert(std::pair<int, int>(400, 4));
    m.insert(std::pair<int, int>(500, 5));
    ft::map<int, int>::iterator low, up;
    std::cout << "m contains:" << " ";
    print_map(m);
    low = m.lower_bound(200);
    up = m.upper_bound(200);
    std::cout << "lower bound is: " << (*low).first << std::endl;
    std::cout << "upper bound is: " << (*up).first << std::endl;
}

void test_std_lower_upper_bound()
{
    std::map<int, int>    m;
    m.insert(std::pair<int, int>(100, 1));
    m.insert(std::pair<int, int>(200, 2));
    m.insert(std::pair<int, int>(300, 3));
    m.insert(std::pair<int, int>(400, 4));
    m.insert(std::pair<int, int>(500, 5));
    std::map<int, int>::iterator low, up;
    std::cout << "m contains:" << " ";
    print_map(m);
    low = m.lower_bound(200);
    up = m.upper_bound(200);
    std::cout << "lower bound is: " << (*low).first << std::endl;
    std::cout << "upper bound is: " << (*up).first << std::endl;
}

void test_ft_key_comp()
{
    ft::map<char,int> mymap;

    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:" << std::endl;
    char highest = mymap.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator it = mymap.begin();
    do 
        std::cout << it->first << " => " << it->second << std::endl;
    while (mycomp((*it++).first, highest));
    std::cout << std::endl;
}

void test_std_key_comp()
{
    std::map<char,int> mymap;

    std::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:" << std::endl;
    char highest = mymap.rbegin()->first;     // key value of last element

    std::map<char,int>::iterator it = mymap.begin();
    do 
        std::cout << it->first << " => " << it->second << std::endl;
    while (mycomp((*it++).first, highest));
    std::cout << std::endl;
}

void test_ft_value_comp()
{
    ft::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    std::pair<char,int> highest = *mymap.rbegin(); // last element

    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest));
}

void test_std_value_comp()
{
    std::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    std::pair<char,int> highest = *mymap.rbegin(); // last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest));
}

void test_ft_operators()
{
    std::cout << "* FT OPERATORS *" << std::endl;
    ft::map<int, char> alice;
    alice[1] = 'a';
    alice[2] = 'b';
    alice[3] = 'c';

    ft::map<int, char> bob;
    bob[7] = 'Z';
    bob[8] = 'Y';
    bob[9] = 'X';
    bob[10] = 'W';

    ft::map<int, char> eve;
    eve[1] = 'a';
    eve[2] = 'b';
    eve[3] = 'c';
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << std::endl;
    std::cout << "alice != bob returns " << (alice != bob) << std::endl;
    std::cout << "alice <  bob returns " << (alice < bob) << std::endl;
    std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
    std::cout << "alice >  bob returns " << (alice > bob) << std::endl;
    std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;
 
    std::cout << std::endl;
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << std::endl;
    std::cout << "alice != eve returns " << (alice != eve) << std::endl;
    std::cout << "alice <  eve returns " << (alice < eve) << std::endl;
    std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
    std::cout << "alice >  eve returns " << (alice > eve) << std::endl;
    std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;
}

void test_std_operators()
{
    std::cout << "* STD OPERATORS *" << std::endl;
    std::map<int, char> alice;
    alice[1] = 'a';
    alice[2] = 'b';
    alice[3] = 'c';

    std::map<int, char> bob;
    bob[7] = 'Z';
    bob[8] = 'Y';
    bob[9] = 'X';
    bob[10] = 'W';

    std::map<int, char> eve;
    eve[1] = 'a';
    eve[2] = 'b';
    eve[3] = 'c';
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << std::endl;
    std::cout << "alice != bob returns " << (alice != bob) << std::endl;
    std::cout << "alice <  bob returns " << (alice < bob) << std::endl;
    std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
    std::cout << "alice >  bob returns " << (alice > bob) << std::endl;
    std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;
 
    std::cout << std::endl;
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << std::endl;
    std::cout << "alice != eve returns " << (alice != eve) << std::endl;
    std::cout << "alice <  eve returns " << (alice < eve) << std::endl;
    std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
    std::cout << "alice >  eve returns " << (alice > eve) << std::endl;
    std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;
}

int main()
{
    test_ft_constructor();
    test_std_constructor();
    test_ft_index_operator();
    test_std_index_operator();
    test_ft_capacity();
    test_std_capacity();
    test_ft_clear();
    test_std_clear();
    test_ft_insert();
    test_std_insert();
    test_ft_erase();
    test_std_erase();
    test_ft_swap();
    test_std_swap();
    test_ft_count();
    test_std_count();
    test_ft_find();
    test_std_find();
    test_ft_equal_range();
    test_std_equal_range();
    test_ft_lower_upper_bound();
    test_std_lower_upper_bound();
    test_ft_key_comp();
    test_std_key_comp();
    test_ft_value_comp();
    test_std_value_comp();
    test_ft_operators();
    test_std_operators();

}