#pragma once

#include <stddef.h>

#include <iostream>
#include <memory>


template <typename T>
class vectorIterator
{
	typedef	T*		pointer;
	typedef T&		reference;
public:
		T *ptr;
		vectorIterator base() { return (this); }
        vectorIterator() {
			this->ptr = NULL;
		}
		vectorIterator(const pointer ptr) {
			this->ptr = ptr;
		}
		vectorIterator(const vectorIterator &ptr) {
			*this = ptr;
		}
		~vectorIterator() {}

		vectorIterator &operator = (const vectorIterator &ptr){
			this->ptr = ptr.ptr;
			return (*this);
		}
		bool operator == (const vectorIterator &ptr){
			if (this->ptr == ptr.ptr){
				return true;
			} else {
				return false;
			}
		}
		bool operator != (const vectorIterator &ptr){
			if (this->ptr != ptr.ptr){
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
			vectorIterator tmp;
			tmp = *this;
			this->ptr++;
			return tmp;
		}
		vectorIterator &operator--(){
			this->ptr--;
			return *this;
		}
		vectorIterator operator--(int){
			vectorIterator tmp;
			tmp = *this;
			this->ptr--;
			return tmp;
		}
		size_t	operator-(vectorIterator ptr) const{
			return this->ptr - ptr.ptr;
		}
		vectorIterator operator-(size_t n) const{
			vectorIterator tmp = *this;
			tmp.ptr -= n;
			return(tmp);
		}
		vectorIterator operator+(size_t n) const{
			vectorIterator tmp = *this;
			tmp.ptr += n;
			return(tmp);
		}
		bool operator > (const vectorIterator &ptr){
			return ptr < *this;
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
class RevvectorIterator
{
	typedef	T*		pointer;
	typedef T&		reference;
public:
		T *ptr;
		pointer base() { 				
			pointer ptr = this->ptr;
			ptr++;
			return(ptr);
		}
        RevvectorIterator() {
			this->ptr = NULL;
		}
		RevvectorIterator(const pointer ptr) {
			this->ptr = ptr;
		}
		RevvectorIterator(const RevvectorIterator &ptr) {
			*this = ptr;
		}
		~RevvectorIterator() {}

		RevvectorIterator &operator = (const RevvectorIterator &ptr){
			this->ptr = ptr.ptr;
			return (*this);
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
			RevvectorIterator *tmp;
			tmp = *this;
			this->ptr--;
			return tmp;
		}
		RevvectorIterator &operator--(){
			this->ptr++;
			return *this;
		}
		RevvectorIterator operator--(int){
			RevvectorIterator *tmp;
			tmp = *this;
			this->ptr++;
			return tmp;
		}
		size_t	operator-(RevvectorIterator ptr) const{
			return this->ptr - ptr.ptr;
		}
		RevvectorIterator operator-(size_t n) const{
			RevvectorIterator tmp = *this;
			tmp.ptr += n;
			return(tmp);
		}
		RevvectorIterator &operator+(size_t n) const{
			return this->ptr - n;
		}
		bool operator > (const RevvectorIterator &ptr){
			return ptr < *this;
		}
		bool operator < (const RevvectorIterator &ptr){
			return !bool(*this) && bool(ptr);
		} // вообще не понимаю 
		bool operator <= (const RevvectorIterator &ptr){
			return !(ptr < *this);
		} // вообще не понимаю 
		bool operator >= (const RevvectorIterator &ptr){
			return !(*this < ptr);
		} // вообще не понимаю 
		RevvectorIterator &operator+=(size_t n){
			this->ptr -= n;
			return (*this);
		}
		RevvectorIterator &operator-=(size_t n){
			this->ptr += n;
			return (*this);
		}
};