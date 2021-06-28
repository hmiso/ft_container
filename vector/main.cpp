#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

template <typename Container>
void print(Container& c, const std::string& prefix = "VECTOR") {
    typename Container::iterator first = c.begin();
    typename Container::iterator second = c.end();

    std::cout << prefix << ": ";
    std::cout << "sz = " << c.size() << ", ";
    std::cout << "data = [ ";
    while (first != second) {
        std::cout << *first++ << " ";
    }
    std::cout << "]" << std::endl;
}

void test_ft_constructor()
{
    std::cout << std::endl;
    std::cout << "*** DEFAULT FT_CONSTRUCTOR ***" << std::endl << std::endl;

    ft::vector<int> v;
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;


    std::cout << "*** FILL FT_CONSTRUCTOR ***" << std::endl << std::endl;
    ft::vector<int> v1(20);
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    print(v1, "V1");

    ft::vector<std::string> v2(20, "s");
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    print(v2, "V2");
    std::cout << std::endl;
    
    std::cout << "*** COPY FT_CONSTRUCTOR ***" << std::endl << std::endl;
    ft::vector<std::string> v3(v2);
    print(v3, "V3");
    std::cout << std::endl;


    std::cout << "*** RANGE FT_CONSTRUCTOR ***" << std::endl << std::endl;
    ft::vector<int> v4(5, 10);
    ft::vector<int>::iterator   v4_f = v4.begin();
    ft::vector<int>::iterator   v4_l = v4.end();
    ft::vector<int> v5(v4_f++, v4_l);
    print(v4, "V4");
    print(v5, "V5");
    
     
}

void test_std_constructor()
{
    std::cout << std::endl;
    std::cout << "*** DEFAULT STD_CONSTRUCTOR ***" << std::endl;
    std::vector<int> v;
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    

    std::cout << "*** FILL STD_CONSTRUCTOR ***" << std::endl << std::endl;
    std::vector<int> v1(20);
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    print(v1, "V1");

    std::vector<std::string> v2(20, "s");
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    print(v2, "V2");
    std::cout << std::endl;

    std::cout << "*** COPY STD_CONSTRUCTOR ***" << std::endl << std::endl;
    std::vector<std::string> v3(v2);
    print(v3, "V3");
    std::cout << std::endl;


    std::cout << "*** RANGE STD_CONSTRUCTOR ***" << std::endl << std::endl;
    std::vector<int> v4(5, 10);
    std::vector<int>::iterator   v4_f = v4.begin();
    std::vector<int>::iterator   v4_l = v4.end();
    std::vector<int> v5(v4_f++, v4_l);
    print(v4, "V4");
    print(v5, "V5");
    
}

void test_ft_sizes()
{
    ft::vector<int> v(15, 100);
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "max_size(): " << v.max_size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    
}

void test_std_sizes()
{
    std::vector<int> v(15, 100);
    std::cout << "empty(): " << v.empty() << std::endl;
    std::cout << "size(): " << v.size() << std::endl;
    std::cout << "max_size(): " << v.max_size() << std::endl;
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
}

void test_ft_resize()
{
    ft::vector<int> v;

    for (int i=1; i < 10; i++) v.push_back(i);
    v.resize(5);
    v.resize(8,100);
    v.resize(12);
    print(v, "v contains");
}

void test_std_resize()
{
    std::vector<int> v;

    for (int i=1; i < 10; i++) v.push_back(i);
    v.resize(5);
    v.resize(8,100);
    v.resize(12);
    print(v, "v contains");
}

void test_ft_reserve()
{
    ft::vector<int> v;

	for (int i = 0; i < 7; i++)
		v.push_back(i);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	v.reserve(8);
	std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	std::cout << std::endl;
	v.reserve(16);
	std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	std::cout << std::endl;
    print(v, "v");
}

void test_std_reserve()
{
    std::vector<int> v;

	for (int i = 0; i < 7; i++)
		v.push_back(i);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	v.reserve(8);
	std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	std::cout << std::endl;
	v.reserve(16);
	std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
	std::cout << std::endl;
    print(v, "v");
}

void test_ft_index_operator()
{
    ft::vector<int> v (10);

    ft::vector<int>::size_type sz = v.size();

    for (unsigned i = 0; i < sz; i++) 
        v[i] = i;
    for (unsigned i = 0; i < sz / 2; i++)
    {
        int temp;
        temp = v[sz - 1 - i];
        v[sz - 1 - i] = v[i];
        v[i] = temp;
    }
    print(v, "v");
}

void test_std_index_operator()
{
    std::vector<int> v (10);

    std::vector<int>::size_type sz = v.size();
    for (unsigned i = 0; i < sz; i++)
        v[i] = i;
    for (unsigned i = 0; i < sz / 2; i++)
    {
        int temp;
        temp = v[sz - 1 - i];
        v[sz - 1 - i] = v[i];
        v[i] = temp;
    }
    print(v, "v");
    
}

void test_ft_at()
{
    ft::vector<int> v(10, 21);
	for (unsigned i = 0; i < v.size(); i++)
	    v.at(i) = i;
    print(v);
    try { v.at(11); } // out of range
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
}

void test_std_at()
{
    std::vector<int> v(10, 21);
	for (unsigned i = 0; i < v.size(); i++)
	    v.at(i) = i;
    print(v);
    try { v.at(11); } // out of range
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
}

void test_ft_assignment_operator()
{
    ft::vector<int> foo(3,0);
    ft::vector<int> bar(5,0);

    bar = foo;
    foo = ft::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << std::endl;
    std::cout << "Size of bar: " << int(bar.size()) << std::endl;
    
    ft::vector<int> v1(3, 1);
    print(v1, "before assignment");
    v1[1] = 30;
    print(v1, "after assignment");
}

void test_std_assignment_operator()
{
    std::vector<int> foo(3,0);
    std::vector<int> bar(5,0);

    bar = foo;
    foo = std::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << std::endl;
    std::cout << "Size of bar: " << int(bar.size()) << std::endl;

    std::vector<int> v1(3, 1);
    print(v1, "before assignment");
    v1[1] = 30;
    print(v1, "after assignment");
}

void test_ft_front_back()
{
    std::cout << "*** STD_FRONT ***" << std::endl;
    ft::vector<int> v;
    v.push_back(42);
    v.push_back(40);
    v.front() -= v.back();
    std::cout << "v.front() is now " << v.front() << std::endl;
    std::cout << std::endl;

    std::cout << "*** STD_BACK ***" << std::endl;
    ft::vector<int> v1;
    v1.push_back(10);
    while (v1.back() != 0)
        v1.push_back (v1.back() - 1);
    print(v1);
}

void test_std_front_back()
{
    std::cout << "*** STD_FRONT ***" << std::endl;
    std::vector<int> v;
    v.push_back(42);
    v.push_back(40);
    v.front() -= v.back();
    std::cout << "v.front() is now " << v.front() << std::endl;
    std::cout << std::endl;

    std::cout << "*** STD_BACK ***" << std::endl;
    std::vector<int> v1;
    v1.push_back(10);
    while (v1.back() != 0)
        v1.push_back (v1.back() - 1);
    print(v1);
}

void test_ft_assign()
{
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign(7,100);

    ft::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1);

    int myints[] = { 1776,7,4 };
    third.assign(ft::vector<int>::iterator(myints), ft::vector<int>::iterator(myints + 3));

    std::cout << "Size of first: " << first.size() << std::endl;
    std::cout << "Size of second: " << second.size() << std::endl;
    std::cout << "Size of third: " << third.size() << std::endl;
}

void test_std_assign()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign(7,100);

    std::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1);

    int myints[] = { 1776,7,4 };
    third.assign(myints, myints + 3);

    std::cout << "Size of first: " << first.size() << std::endl;
    std::cout << "Size of second: " << second.size() << std::endl;
    std::cout << "Size of third: " << third.size() << std::endl;
}

void test_ft_push_pop()
{
    ft::vector<int> v;
    v.push_back(1);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.push_back(2);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.push_back(3);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    for (int i = 4; i < 100; ++i)
        v.push_back(i);
    print(v);
    ft::vector<int>::iterator it = v.end();
    while (it-- != ++++++v.begin())
        v.pop_back();
    print(v);
}

void test_std_push_pop()
{
    std::vector<int> v;
    v.push_back(1);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.push_back(2);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.push_back(3);
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    for (int i = 4; i < 100; ++i)
        v.push_back(i);
    print(v);
    std::vector<int>::iterator it = v.end();
    while (it-- != ++++++v.begin())
        v.pop_back();
    print(v);
}

void test_ft_insert()
{
    ft::vector<int> v;
    for (int i = 1; i < 21; ++i)
        v.push_back(i);
    v.insert(v.begin(), 100);
    v.insert(--v.end(), 99);
    print(v, "after insert at begin and end");
    v.insert(v.begin() + 10, 8, 999);
    print(v, "insert eight 999");
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.insert(v.begin(), v.begin() + 5, v.end());
    print(v);
}

void test_std_insert()
{
    std::vector<int> v;
    for (int i = 1; i < 21; ++i)
        v.push_back(i);
    v.insert(v.begin(), 100);
    v.insert(--v.end(), 99);
    print(v, "after insert");
    v.insert(v.begin() + 10, 8, 999);
    print(v, "insert eight 999");
    std::cout << "capacity(): " << v.capacity() << std::endl << std::endl;
    v.insert(v.begin(), v.begin() + 5, v.end());
    print(v);
} 

void test_ft_erase()
{
    ft::vector<int> v;
    for (int i=1; i<=10; i++)
        v.push_back(i);
    v.erase (v.begin() + 5);
    print(v, "erase 6th");
    v.erase (v.begin(),v.begin() + 3);
    print(v, "erase first 3 elements");
    
}

void test_std_erase()
{
    std::vector<int> v;
    for (int i=1; i<=10; i++)
        v.push_back(i);
    v.erase (v.begin() + 5);
    print(v, "erase 6th");
    v.erase (v.begin(),v.begin() + 3);
    print(v, "erase first 3 elements");    
}

void test_ft_clear()
{
    ft::vector<int> v;
    v.push_back (100);
    v.push_back (200);
    v.push_back (300);

    v.clear();
    print(v);
    v.push_back (1101);
    v.push_back (2202);
    print(v);
}

void test_std_clear()
{
    std::vector<int> v;
    v.push_back (100);
    v.push_back (200);
    v.push_back (300);

    v.clear();
    print(v);
    v.push_back (1101);
    v.push_back (2202);
    print(v);
}

void test_ft_swap()
{
    ft::vector<int> vec(5, 42);
    ft::vector<int> vec1(2, 21);
    print(vec, "vector vec contains");
    print(vec1, "vector vec1 contains");
    vec.swap(vec1);
    print(vec, "after swap vec contains");
    print(vec1, "after swap vec1 contains");
}

void test_std_swap()
{
    std::vector<int> vec(5, 42);
    std::vector<int> vec1(2, 21);
    print(vec, "vector vec contains");
    print(vec1, "vector vec1 contains");
    vec.swap(vec1);
    print(vec, "after swap vec contains");
    print(vec1, "after swap vec1 contains");
}

void test_ft_operators()
{
    ft::vector<int> first;
    for (int i = 1; i < 4; ++i)
        first.push_back(i);
    ft::vector<int> second;
    for (int i = 6; i < 11; ++i)
        second.push_back(i);
    ft::vector<int> third(first);

    print(first, "first contains");
    print(second, "second contains");
    print(third, "third contains");

    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "first == second returns " << (first == second) << std::endl;
    std::cout << "first != second returns " << (first != second) << std::endl;
    std::cout << "first <  second returns " << (first < second) << std::endl;
    std::cout << "first <= second returns " << (first <= second) << std::endl;
    std::cout << "first >  second returns " << (first > second) << std::endl;
    std::cout << "first >= second returns " << (first >= second) << std::endl;
 
    std::cout << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "first == third returns " << (first == third) << std::endl;
    std::cout << "first != third returns " << (first != third) << std::endl;
    std::cout << "first <  third returns " << (first < third) << std::endl;
    std::cout << "first <= third returns " << (first <= third) << std::endl;
    std::cout << "first >  third returns " << (first > third) << std::endl;
    std::cout << "first >= third returns " << (first >= third) << std::endl;
}

void test_std_operators()
{
    std::vector<int> first;
    for (int i = 1; i < 4; ++i)
        first.push_back(i);
    std::vector<int> second;
    for (int i = 6; i < 11; ++i)
        second.push_back(i);
    std::vector<int> third(first);
    
    print(first, "first contains");
    print(second, "second contains");
    print(third, "third contains");
    
    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "first == second returns " << (first == second) << std::endl;
    std::cout << "first != second returns " << (first != second) << std::endl;
    std::cout << "first <  second returns " << (first < second) << std::endl;
    std::cout << "first <= second returns " << (first <= second) << std::endl;
    std::cout << "first >  second returns " << (first > second) << std::endl;
    std::cout << "first >= second returns " << (first >= second) << std::endl;
 
    std::cout << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "first == third returns " << (first == third) << std::endl;
    std::cout << "first != third returns " << (first != third) << std::endl;
    std::cout << "first <  third returns " << (first < third) << std::endl;
    std::cout << "first <= third returns " << (first <= third) << std::endl;
    std::cout << "first >  third returns " << (first > third) << std::endl;
    std::cout << "first >= third returns " << (first >= third) << std::endl;
    
}

void test_ft_rev_iter()
{
    ft::vector<int> v;

	for (int i = 0; i < 11; i++)
		v.push_back(i);
	
	ft::vector<int>::reverse_iterator it1 = v.rbegin();
	std::cout << *it1 << " ";

	ft::vector<int> v1;

	for (int i = 0; i < 30; i++)
		v1.push_back(i);

	ft::vector<int>::reverse_iterator it2 = v1.rbegin();
	std::cout << *it2 << " ";
    std::cout << std::endl;

}

void test_std_rev_iter()
{
    std::vector<int> v;

	for (int i = 0; i < 11; i++)
		v.push_back(i);
	
	std::vector<int>::reverse_iterator it1 = v.rbegin();
	std::cout << *it1 << " ";

	std::vector<int> v1;

	for (int i = 0; i < 30; i++)
		v1.push_back(i);

	std::vector<int>::reverse_iterator it2 = v1.rbegin();
	std::cout << *it2 << " ";
    std::cout << std::endl;
}

void test_ft_base()
{
    std::cout << "*** FT BASE ***" << std::endl;
    ft::vector<int> v;

	for (unsigned long i = 0; i < 6; i++)
		v.push_back(i);

    ft::vector<int>::iterator it = v.begin() + 3;
    ft::vector<int>::reverse_iterator r_it = v.rend() - 3;
 
    std::cout << "*it == " << *it << ", *r_it.base() == " << *r_it.base()
    << '\n' << "*r_it == " << *r_it <<", *(r_it.base() - 1) == " << *(r_it.base() - 1) << "\n";
	std::cout << std::endl;

	std::vector<int> v1;

	for (unsigned long i = 0; i < 6; i++)
		v1.push_back(i);

    std::vector<int>::iterator it1 = v1.begin() + 3;
    std::vector<int>::reverse_iterator r_it1 = v1.rend() - 3;
 
    std::cout << "*it == " << *it1 << ", *r_it.base() == " << *r_it1.base()
    << '\n' << "*r_it == " << *r_it1 <<", *(r_it.base() - 1) == " << *(r_it1.base() - 1) << "\n";
}

void test_std_base()
{
    std::cout << "*** STD BASE ***" << std::endl;
    std::vector<int> v;

	for (unsigned long i = 0; i < 6; i++)
		v.push_back(i);

    std::vector<int>::iterator it = v.begin() + 3;
    std::vector<int>::reverse_iterator r_it = v.rend() - 3;
 
    std::cout << "*it == " << *it << ", *r_it.base() == " << *r_it.base()
    << '\n' << "*r_it == " << *r_it <<", *(r_it.base() - 1) == " << *(r_it.base() - 1) << "\n";
	std::cout << std::endl;

	std::vector<int> v1;

	for (unsigned long i = 0; i < 6; i++)
		v1.push_back(i);

    std::vector<int>::iterator it1 = v1.begin() + 3;
    std::vector<int>::reverse_iterator r_it1 = v1.rend() - 3;
 
    std::cout << "*it == " << *it1 << ", *r_it.base() == " << *r_it1.base()
    << '\n' << "*r_it == " << *r_it1 <<", *(r_it.base() - 1) == " << *(r_it1.base() - 1) << "\n";
    
}


int main()
{
    test_ft_constructor();
    test_std_constructor();
    test_ft_sizes();
    test_std_sizes();
    test_ft_resize();
    test_std_resize();
    test_ft_reserve();
    test_std_reserve();
    test_ft_index_operator();
    test_std_index_operator();
    // test_ft_at();
    // test_std_at();
    test_ft_assignment_operator();
    test_std_assignment_operator();
    test_ft_front_back();
    test_std_front_back();
    test_ft_assign();
    test_std_assign();
    test_ft_push_pop();
    test_std_push_pop();
    test_ft_insert();
    test_std_insert();
    test_ft_erase();
    test_std_erase();
    test_ft_clear();
    test_std_clear();
    test_ft_rev_iter();
    test_std_rev_iter();
    test_ft_base();
    test_std_base();
    test_ft_swap();
    test_std_swap();
    test_ft_operators();
    test_std_operators();
}