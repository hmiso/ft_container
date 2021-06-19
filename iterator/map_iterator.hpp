#pragma once

# include "../map.hpp"
# include "../avl_tree.hpp"

template <class Key, class T>
class Mapiterator
{
	private:

	avl_tree<Key, T> func;
	public:

	Mapiterator(map_node<Key, T> *ptr){
		this->func.root = ptr;
	}
	Mapiterator(){
		this->func.root = NULL;
	}
	Mapiterator& operator=(const Mapiterator &ptr){
		this->func.root = ptr.func.root;
		return (*this);
	}
	std::pair<Key, T> *operator->(){
		return (&this->func.root->pair);
	}
	Mapiterator &operator++(){
	if (this->func.root->right)
		this->func.root = func.findmin(this->func.root->right);
	else {
		while (this->func.root->parrent && this->func.root->parrent->right == this->func.root){
			this->func.root = this->func.root->parrent;
		}
		this->func.root = this->func.root->parrent;
	}
	return (*this);

	}
};

template <class Key, class T>
class RevMapiterator
{

};
