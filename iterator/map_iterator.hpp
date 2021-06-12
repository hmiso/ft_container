#pragma once

# include "../map.hpp"
# include "../avl_tree.hpp"

template <class Key, class T>
class Mapiterator
{
	private:
	map_node<Key, T> *ptr;

	avl_tree<Key, T> func;
	public:

	Mapiterator(map_node<Key, T> *ptr){
		this->ptr = ptr;
	}

	Mapiterator &operator++(){
	if (this->ptr->right)
		this->ptr = func.findmin(this->ptr->right);
	else if (this->ptr != func.get_end())
	{
		while (this->ptr->parrent && this->ptr->parrent->right == this->ptr)
			this->ptr = this->ptr->parrent;
		this->ptr = this->ptr->parrent;
		if (this->ptr == NULL)
			this->ptr = func.get_end();
	}
	else
		this->ptr->left->parrent = NULL;
	return (*this);
	}
};

template <class Key, class T>
class RevMapiterator
{

};
