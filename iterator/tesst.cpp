
#include <iostream>
#include <memory>

template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator {
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};

template <typename T>
class node{
    typedef T         value_type;
    typedef node*     node_pointer;
    public:
        node *ptrNext;
        node *ptrPrevie;
        value_type data;
        node(value_type data, node *ptrPrevie = NULL, node *ptrNext = NULL){
            this->data = data;
            this->ptrNext = ptrNext;
            this->ptrPrevie = ptrPrevie;
        };
        node(const node &copy){
            this->data = copy->data;
            this->ptrNext = copy->ptrNext;
            this->ptrPrevie = copy->ptrPrevie;
        };
        node(){
            this->data = NULL;
            this->ptrNext = NULL;
            this->ptrPrevie = NULL;
        }
        node &operator = (const node &ptr){
            this->data = ptr.data;
            this->ptrNext = ptr.ptrNext;
            this->ptrPrevie = ptr.ptrPrevie;
            return *this;
        }
        ~node(){}; 
};

template <typename T>
class listIterator : public iterator<std::bidirectional_iterator_tag, T>
{

public:
    node<T> *ptr;

    listIterator(){
        this->ptr = NULL
    }

    listIterator(const node<T> *ptr){
        this->ptr = ptr;
    }

    ~listIterator(){}

    listIterator &operator = (const node<T> *ptr){
        this->ptr->data = ptr->data;
        this->ptr->ptrNext = ptr->ptrNext;
        this->ptr->ptrPrevie = ptr->ptrPrevie;
        return (*this);
    }

    listIterator &operator++(){
        this->ptr = this->ptr->ptrNext;
        return (*this->ptr);
    }
    bool operator == (const node<T> *ptr){
        if (this->ptr == ptr){
            return true;
        } else {
            return false;
        } // я правильно понимаю что сравнение идет по адресам а не значениям?
    }
    bool operator != (const node<T> *ptr){
        if (this->ptr != ptr){
            return true;
        } else {
            return false;
        } // я правильно понимаю что сравнение идет по адресам а не значениям?
    }
    reference    operator*() const{
        return this->ptr->data;
    }
    pointer operator -> () const {
        return &(this->ptr->data);
    }
};


int main(){
    // node<int>ptr(10);
    // listIterator<int> ptr2(&ptr);
    // ptr = ++ptr2;
    // std::cout << ptr.data << std::endl;
    // node<int> ptr(10);
    // node<int> ptr3(30);
    // node<int> ptr2(20, &ptr, &ptr3);

    // std::cout << ptr2.data << " " << ptr2.ptrPrevie->data << " " << ptr2.ptrNext->data << " "  << std::endl;

    // node<int> *ptr4 = new node<int>(48);
}