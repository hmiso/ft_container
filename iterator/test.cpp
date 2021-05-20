#include <iostream>
#include <list>

class ptr{
	private:
	int m;
	public:
	ptr(int m){
		this->m = 1;
	}
	~ptr(){
		std::cout << "ptr destroy" << std::endl;
	}
};


int main ()
{

   std::list<int> ptr;
   ptr.push_back(1);
   ptr.push_back(2);
   ptr.push_back(3);
   ptr.push_back(4);
   std::list<int>::iterator it;
   std::list<int>::iterator it1;
   it = ptr.end();
   it1 = ptr.begin();


//   std::list<ptr> mylist1, mylist2;
//   std::list<ptr>::iterator it;
//   ptr test
//   // set some initial values:
//   for (int i=1; i<=4; ++i)
//      mylist1.push_back(ptr());      // mylist1: 1 2 3 4

//   for (int i=1; i<=3; ++i)
//      mylist2.push_back(ptr());   // mylist2: 10 20 30

//   it = mylist1.begin();
//   ++it;                         // points to 2

//   mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                      
//   mylist2.splice (mylist2.begin(),mylist1, it);
//                                 // mylist1: 1 10 20 30 3 4
//                                 // mylist2: 2
//                                 // "it" is now invalid.
//   it = mylist1.begin();
//   std::advance(it,3);           // "it" points now to 30

//   mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//                                 // mylist1: 30 3 4 1 10 20

//   std::cout << "mylist1 contains:";
//   for (it=mylist1.begin(); it!=mylist1.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "mylist2 contains:";
//   for (it=mylist2.begin(); it!=mylist2.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout << mylist2.empty() << std::endl;

  return 0;
}