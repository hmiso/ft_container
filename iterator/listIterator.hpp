#pragma once

#include <stddef.h>
#include "iterator.hpp"
#include <iostream>
#include <memory>
#include "node.hpp"

// template <typename T>
// class listIterator : public iterator<std::bidirectional_iterator_tag, T>
// {
// private:
// 	typedef struct node{
// 		next * node;
// 		prev * node;
// 		value_type data;
// 	}node;

// public:
// 	listIterator(node * mynode){
// 		this->node->next = mynode->next;
// 		this->node->prev = mynode->prev;
// 		this->node->data = mynode->data;
// 	}
// };

template <typename T>
class listIterator : public iterator<std::bidirectional_iterator_tag, T>
{
	typedef	T*		pointer;
	typedef T&		reference;

public:
    node<T> *ptr;

    listIterator(){
        this->ptr = NULL;
    }

    listIterator(node<T> *ptr){
        this->ptr = ptr;
    }
    listIterator(const listIterator &ptr){
        this->ptr = ptr.ptr;
    }
	
    ~listIterator(){}

    listIterator &operator = (const listIterator &ptr){
        this->ptr = ptr.ptr;
        return (*this);
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
    listIterator &operator++(){
        this->ptr = this->ptr->ptrNext;
        return *this;
    }
    listIterator operator++(int){
        listIterator tmp(*this);
        tmp = tmp.ptr->ptrNext;
        return tmp;
    }
    listIterator &operator--(){
        this->ptr = this->ptr->ptrPrevie;
        return *this;
    }
    listIterator operator--(int){
        listIterator *tmp;
        tmp = this->ptr->ptrPrevie;
        return tmp;        
    }
};

template <typename T>
class RevlistIterator : public iterator<std::bidirectional_iterator_tag, T>
{
	typedef	T*		pointer; // не смотря на то что я наследуюсь от базового итератора без них не компилируется
	typedef T&		reference;
private:
    node<T> *ptr;

public:

    RevlistIterator(){
        this->ptr = NULL;
    }

    RevlistIterator(const node<T> *ptr){
        this->ptr = ptr;
    }
	RevlistIterator(RevlistIterator const &ptr){
		this = ptr;
	}

    ~RevlistIterator(){}

    RevlistIterator &operator = (const node<T> *ptr){
        this->ptr->data = ptr->data;
        this->ptr->ptrNext = ptr->ptrNext;
        this->ptr->ptrPrevie = ptr->ptrPrevie;
        return (*this);
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
    RevlistIterator &operator++(){
        this->ptr = this->ptr->ptrPrevie;
        return *this;
    }
    RevlistIterator operator++(int){
        RevlistIterator *tmp;
        tmp = this->ptr->ptrPrevie;
        return tmp;
    }
    RevlistIterator &operator--(){
        this->ptr = this->ptr->ptrNext;
        return *this;
    }
    RevlistIterator operator--(int){
        RevlistIterator *tmp;
        tmp = this->ptr->ptrNext;
        return tmp;        
    }
};

template <typename T>
class ConstlistIterator : public iterator<std::bidirectional_iterator_tag, T>
{
	typedef	const T		pointer;
	typedef const T&	reference;

public:
    node<const T> *ptr;

    ConstlistIterator(){
        this->ptr = NULL;
    }

    ConstlistIterator(node<T> *ptr){
        this->ptr = ptr;
    }
    ConstlistIterator(const ConstlistIterator &ptr){
        this->ptr = ptr.ptr;
    }
	
    ~ConstlistIterator(){}

    ConstlistIterator &operator= (ConstlistIterator &ptr){
        this->ptr = ptr.ptr;
        return (*this);
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
    ConstlistIterator &operator++(){
        this->ptr = this->ptr->ptrNext;
        return *this;
    }
    ConstlistIterator operator++(int){
        ConstlistIterator tmp(*this);
        tmp = tmp.ptr->ptrNext;
        return tmp;
    }
    ConstlistIterator &operator--(){
        this->ptr = this->ptr->ptrPrevie;
        return *this;
    }
    ConstlistIterator operator--(int){
        ConstlistIterator *tmp;
        tmp = this->ptr->ptrPrevie;
        return tmp;        
    }
};