#pragma once

#include <stddef.h>

template <typename T>
class node{
    typedef T         value_type;
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
