#include <list>
#include <iterator>
#include <iostream>
#include "list.hpp"


int main(){
	std::list<int> ptr_orig;
	ptr_orig.push_back(1);
	ptr_orig.push_back(2);
	const int rr = ptr_orig.front();
	std::cout << rr << std::endl;
	// std::list<int> ptr_orig2;
	// ptr_orig2 = ptr_orig.front();
	// std::list<int>::iterator it;
	// it = ptr.begin();
	// std::cout << *it << std::endl;
	// *it = 3;
	// std::cout << *it << std::endl;
	// std::list<int>::const_iterator constIt;
	// constIt = ptr.begin();
	// *constIt = 5;

	ft::list<int> ptr2;
	ptr2.push_back(1);
	ptr2.push_back(2);
	ptr2.push_back(3);
	// ft::list<int>::iterator it2;
	// it2 = ptr2.begin();
	// std::cout << *it2 << std::endl;
	// it2++;
	// std::cout << *it2 << std::endl;
	// it2++;
	// std::cout << *it2 << std::endl;
	// *it2 = 5;
	// std::cout << *it2 << std::endl;
	// ft::list<int>::const_iterator constIt2;
	// constIt2 = ptr2.begin();
	// *constIt2 = 12;
	// std::cout << *constIt2 << std::endl;
	// std::cout << ptr2.size() << std::endl;
	// std::cout << ptr2.front() << std::endl;
	const int ss = ptr2.front();
	// std::cout << *(ptr2.begin()) << std::endl;
}