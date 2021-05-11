#include <list>
#include <iterator>
#include <iostream>
#include "list.hpp"

// class Int
// {
// 	private:
// 	int b;
// 	public:
// 	Int(const int & b):b(b)
// 	{

// 	}

// 	void print() const 
// 	{
// 		std::cout << b << std::endl;
// 	}
// };
int main(){
	// int b = 5;
	// const Int a = Int(5);
	// a.print();
	// std::list<int> ptr_orig;
	// ptr_orig.push_back(1);
	// ptr_orig.push_back(2);
	// const int rr = ptr_orig.front();
	// std::cout << rr << std::endl;
	// std::list<int> ptr_orig2;
	// std::list<int>::iterator it;
	// it = ptr_orig.begin();
	// std::cout << *it << std::endl;
	// *it = 3;
	// std::cout << *it << std::endl;
	// std::list<int>::const_iterator constIt;
	//  constIt = ptr_orig.begin();
	// *constIt = 5;
	// max(const Morojenoe &);
	// std::list<int> ptr2;
	// max(Morojenoe("shok"));
	// ptr2.push_back(1);
	// ptr2.push_back(2);
	// ptr2.push_back(3);
	// ft::list<int>::iterator it2;
	// it2 = ptr2.begin();
	// std::cout << *it2 << std::endl;
	// it2++;
	// std::cout << *it2 << std::endl;
	// it2++;
	// std::cout << *it2 << std::endl;
	// *it2 = 5;
	// std::cout << *it2 << std::endl;
	// std::list<int>::const_iterator constIt2;
	// constIt2 = ptr2.begin();
	// std::list<int>::iterator ds = constIt2;
	// *constIt2 = 12;
	// std::cout << *constIt2 << std::endl;
	// std::cout << ptr2.size() << std::endl;
	// std::cout << ptr2.front() << std::endl;
	// const int ss = ptr2.front();
	// std::cout << *(ptr2.begin()) << std::endl;


	ft::list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	ft::list<int>::iterator ai;
	ai = a.begin();
	++ai;
	a.insert(ai, 4);
	ai = a.begin();
	while(ai != a.end()){
		std::cout << *ai << std::endl;
		++ai;
	}
	
	
	// std::cout << a.front() << std::endl;

	// ft::list<int> a;
	// a.push_back(1);
	// a.push_back(2);
	// a.push_front(3);
	// a.pop_back();
	// ft::list<int>::iterator ai;
	// ai = a.begin();
	// std::cout << *ai << std::endl;
	// ++ai;
	// std::cout << *ai << std::endl;
	// ++ai;
	// std::cout << *ai << std::endl;
}