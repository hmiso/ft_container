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
// int main(){
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


	// ft::list<int> a;
	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// ft::list<int>::iterator ai;
	// ai = a.begin();
	// ++ai;
	// a.insert(ai, 4);
	// ai = a.begin();
	// while(ai != a.end()){
	// 	std::cout << *ai << std::endl;
	// 	++ai;
	// }
	
	
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
// }
// #include <iostream>
// #include <list>

int main ()
{
  ft::list<int> mylist1, mylist2;
  ft::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                          
//   mylist2.splice (mylist2.begin(),mylist1, it);
//                                 // mylist1: 1 10 20 30 3 4
//                                 // mylist2: 2
//                                 // "it" is now invalid.
//   it = mylist1.begin();
//   std::advance(it,3);           // "it" points now to 30

//   mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

  std::cout << "mylist1 contains:";
  for (it=mylist1.begin(); it!=mylist1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
// int main ()
// {

//    ft::list<int> ptr;
//    ptr.push_back(1);
//    ptr.push_back(2);
//    ptr.push_back(3);
//    ptr.push_back(4);
//    ft::list<int>::iterator it;
//    ft::list<int>::iterator it1;
//    it1 = ptr.begin();
//    it = ptr.end();
//    while (it1 != it)
//    {
//       std::cout << *it1 << std::endl;
//       ++it1;
//    }
   
// }