#pragma once

#include <stddef.h>
#include "iterator.hpp"
#include <iostream>
#include <memory>
#include "node.hpp"

template <typename T>
class vectorIterator : public iterator<std::random_access_iterator_tag, T>
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
		size_t	operator-(vectorIterator ptr) const{
			return this->ptr - ptr.ptr;
		}
		vectorIterator &operator-(size_t n) const{
			return this->ptr - n;
		}
		vectorIterator &operator+(size_t n) const{
			return this->ptr + n;
		}
		bool operator > (const vectorIterator &ptr){
			return ptr < *this
		}
		bool operator < (const vectorIterator &ptr){
			return !bool(*this) && bool(ptr);
		} // вообще не понимаю 
		bool operator <= (const vectorIterator &ptr){
			return !(ptr < *this);
		} // вообще не понимаю 
		bool operator >= (const vectorIterator &ptr){
			return !(*this < ptr);
		} // вообще не понимаю 
		vectorIterator &operator+=(size_t n){
			this->ptr += n;
			return (*this);
		}
		vectorIterator &operator-=(size_t n){
			this->ptr -= n;
			return (*this);
		}
};

template <typename T>
class RevvectorIterator : public iterator<std::random_access_iterator_tag, T>
{

public:
		T *ptr;
        RevvectorIterator() {
			this->ptr = NULL;
		}
		RevvectorIterator(const T* ptr) {
			this->ptr = ptr;
		}
		RevvectorIterator(const RevvectorIterator &ptr) {
			*this = ptr;
		}
		~RevvectorIterator() {}

		RevvectorIterator &operator = (const RevvectorIterator &ptr){
			this->ptr = ptr.ptr;
		}
		bool operator == (const RevvectorIterator &ptr){
			if (*this == ptr){
				return true;
			} else {
				return false;
			}
		}
		bool operator != (const RevvectorIterator &ptr){
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
		RevvectorIterator &operator++(){
			this->ptr--;
			return *this;
		}
		RevvectorIterator operator++(int){
			vectorIterator *tmp;
			tmp = *this;
			this->ptr--;
			return tmp;
		}
		RevvectorIterator &operator--(){
			this->ptr++;
			return *this;
		}
		RevvectorIterator operator--(int){
			vectorIterator *tmp;
			tmp = *this;
			this->ptr++;
			return tmp;
		}
		size_t	operator-(RevvectorIterator ptr) const{
			return this->ptr - ptr.ptr;
		}
		RevvectorIterator &operator-(size_t n) const{
			return this->ptr + n;
		}
		vectorIterator &operator+(size_t n) const{
			return this->ptr - n;
		}
		bool operator > (const vectorIterator &ptr){
			return ptr < *this
		}
		bool operator < (const vectorIterator &ptr){
			return !bool(*this) && bool(ptr);
		} // вообще не понимаю 
		bool operator <= (const vectorIterator &ptr){
			return !(ptr < *this);
		} // вообще не понимаю 
		bool operator >= (const vectorIterator &ptr){
			return !(*this < ptr);
		} // вообще не понимаю 
		vectorIterator &operator+=(size_t n){
			this->ptr -= n;
			return (*this);
		}
		vectorIterator &operator-=(size_t n){
			this->ptr += n;
			return (*this);
		}
};