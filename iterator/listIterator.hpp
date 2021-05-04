#pragma once

#include "iterator.hpp"
#include <iostream>
#include <memory>


template <typename T>
class listIterator : public iterator<std::bidirectional_iterator_tag, T>
{
private:
	typedef struct node{
		next * node;
		prev * node;
		value_type data;
	}node;

public:
	listIterator(node * mynode){
		this->node->next = mynode->next;
		this->node->prev = mynode->prev;
		this->node->data = mynode->data;
	}
};


