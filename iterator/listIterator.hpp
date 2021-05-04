#pragma once

#include "iterator.hpp"

template <typename T>
class listIterator : public Iterator<std::bidirectional_iterator_tag, T>
{
private:
	struct node{
		next * node;
		prev * node;
		value_type data;
	} * node;

public:
	listIterator(node * mynode);
};
