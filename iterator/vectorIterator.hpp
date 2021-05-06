#pragma once

#include <stddef.h>
#include "iterator.hpp"
#include <iostream>
#include <memory>
#include "node.hpp"

template <typename T>
class vectorIterator : public iterator<std::bidirectional_iterator_tag, T>
{

public:
		T *ptr;
        vectorIterator() {
			this->ptr = NULL;
		}
		vectorIterator(const T* ptr) {
			this->ptr = ptr;
		}
		vectorIterator(const vectorIterator &ptr) {
			*this = ptr;
		}
		~vectorIterator() {}

		vectorIterator &operator = (const vectorIterator &ptr){
			this->ptr = ptr.ptr;
		}
		bool operator == (const vectorIterator &ptr){
			if (*this == ptr){
				return true;
			} else {
				return false;
			}
		}
		bool operator != (const vectorIterator &ptr){
			if (*this != ptr){
				return true;
			} else {
				return false;
			}
		}
		reference    operator*() const{
        	return *this->ptr;
    	}
    	pointer operator -> () const {
        	return &(*this->ptr);
		}
		vectorIterator &operator++(){
			this->ptr++;
			return *this;
		}
		vectorIterator operator++(int){
			vectorIterator *tmp;
			tmp = *this;
			this->ptr++;
			return tmp;
		}
		vectorIterator &operator--(){
			this->ptr--;
			return *this;
		}
		vectorIterator operator--(int){
			vectorIterator *tmp;
			tmp = *this;
			this->ptr--;
			return tmp;
		}
};