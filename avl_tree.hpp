#pragma once

#include <iostream>

template <class Key, class T>
class map_node
{
	public:

	std::pair<Key, T> pair;
	int height;
	int flag_empty;
	map_node* left;
	map_node* right;
	map_node* parrent;

	map_node(Key k, T val){
		this->height = 1;
		this->left = NULL;
		this->right = NULL;
		this->parrent = NULL;
		this->pair.first = k;
		this->pair.second = val;
	}
	map_node(map_node *prev, Key k, T val){
		this->height = 1;
		this->left = NULL;
		this->right = NULL;
		this->parrent = NULL;
		this->pair.first = k;
		this->pair.second = val;
		this->parrent = prev;
		this->flag_empty = 1;
	}	
	map_node(){
		this->height = 1;
		this->left = NULL;
		this->right = NULL;
		this->parrent = NULL;
		this->flag_empty = 0;
	}
	map_node &operator= (map_node const &ptr){
		this->height = ptr.height;
		this->left = ptr.left;
		this->right = ptr.right;
		this->parrent = ptr.parrent;
		this->pair = ptr.pair;
		this->flag_empty = ptr.flag_empty;
	}
};

template <class Key, class T>
class avl_tree{
	public:
	typedef std::pair<const Key, T>				value_type;

	map_node<Key, T> *root;
	map_node<Key, T> *end;

	avl_tree(){
		this->root = new map_node<Key, T>;
		this->end = new map_node<Key, T>;
	}
	unsigned char height(map_node<Key, T>* p)
	{
		return p?p->height:0;
	}
		map_node<Key, T> findmin(map_node<Key, T> p) const	{ return (p->_left?findmin(p->_left):p); }
		map_node<Key, T> findmax(map_node<Key, T> p) const	{ return (p->_right?findmax(p->_right):p); }
	int bfactor(map_node<Key, T>* p)
	{
		return height(p->right)-height(p->left);
	}

	void fixheight(map_node<Key, T>* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl>hr?hl:hr)+1;
	}
	map_node<Key, T>* balance(map_node<Key, T>* p) // балансировка узла p
	{
		fixheight(p);
		if( bfactor(p)==2 )
		{
			if( bfactor(p->right) < 0 )
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if( bfactor(p)==-2 )
		{
			if( bfactor(p->left) > 0  )
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}
	map_node<Key, T>* rotateright(map_node<Key, T>* p) // правый поворот вокруг p
	{
		map_node<Key, T>* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	map_node<Key, T>* rotateleft(map_node<Key, T>* q) // левый поворот вокруг q
	{
		map_node<Key, T>* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}	
	map_node<Key, T> *insert(map_node<Key, T> *ptr, map_node<Key, T> *parrent, Key k, T val){
		if (!ptr) {
			map_node<Key, T> *temp = new map_node<Key, T>;
			temp->parrent = parrent;
			temp->height = 1;
			temp->pair.first = k;
			temp->pair.second = val;
			temp->right = NULL;
			temp->left = NULL;
			return temp;
		}
		if (k < ptr->pair.first) {
			ptr->left = insert(ptr->left, ptr, k, val);
		} else {
			ptr->right = insert(ptr->right, ptr, k, val);
		}
		return balance(ptr);
	}
	void insert(Key k, T val){
		if (this->root->flag_empty == 0){
			this->root->flag_empty = 1;
			this->root->pair.first = k;
			this->root->pair.second = val;
			return ;
		}
		insert(this->root, this->root, k, val);
	}
	T find(Key k){
		map_node<Key, T> *temp = this->root;
		while (temp && temp->pair.first != k)
		{
			if (temp->pair.first > k){
				temp = temp->left;
			} else {
				temp = temp->right;
			}
		}
		if (temp){
			return temp->pair.second;
		} else {
			return 0;
		}
	}
};
