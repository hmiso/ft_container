#pragma once

#include <iostream>

template <class Key, class T>
class map_node
{
	public:

	std::pair<Key, T> pair;
	unsigned char height;
	int flag_empty;
	bool end;
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
	map_node(const map_node &ptr){
		this->height =  ptr.height;
		this->left = ptr.left;
		this->right = ptr.right;
		this->parrent = ptr.parrent;
		this->pair.first = ptr.pair.first;
		this->pair.second = ptr.pair.second;
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

	avl_tree &operator=(const avl_tree &ptr){
		this->root = ptr.root;
	}
	void delete_end(map_node<Key, T> *p) {
		if (!p){
			return ;
		}
		if (p->right)
			delete_end(p->right);
		else {
			p->parrent->right = 0;
		}
	}

	void delete_end() {
		map_node<Key, T> *temp = this->root;
		while(temp->right->end != true){
			temp = temp->right;
		}
		temp->right = NULL;
		this->end->parrent = NULL;
	}

	void set_end(){
		map_node<Key, T> *temp = this->root;
		while(temp->right != NULL){
			temp = temp->right;
		}
		temp->right = this->end;
		this->end->parrent = temp;
	}

	avl_tree(){
		this->root = new map_node<Key, T>;
		this->end = new map_node<Key, T>;
		this->root->right = end;
		this->end->end = true;
		this->end->height = 0;
		this->end->parrent = this->root;
	}
	avl_tree(const avl_tree &ptr){
		this->root = ptr.root;
	}
	unsigned char height(map_node<Key, T>* p)
	{
		if (p && p->end == true){
			return 0;
		}
		return p?p->height:0;
	}
	map_node<Key, T> *findmin(map_node<Key, T> *p) const	{ return (p->left?findmin(p->left):p); }
	map_node<Key, T> *findmax(map_node<Key, T> *p) const	{ return (p->right?findmax(p->right):p); }
	int bfactor(map_node<Key, T>* p)
	{
		return height(p->right)-height(p->left);
	}

	void fixheight(map_node<Key, T>* p)
	{
		int hl = height(p->left);
		int hr = height(p->right);
		p->height = (hl>hr?hl:hr)+1;
	}
	map_node<Key, T>* get_end(){
		return this end;
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
		if (p->left){
			p->left->parrent = p;
		}
		q->right = p;
		q->parrent = p->parrent;
		p->parrent = q;
		fixheight(p);
		fixheight(q);
		return q;
	}

	map_node<Key, T>* rotateleft(map_node<Key, T>* p) // левый поворот вокруг q
	{
		map_node<Key, T>* q = p->right;
		p->right = q->left;
		if (p->right){
			p->right->parrent = p;
		}
		q->left = p;
		q->parrent = p->parrent;
		p->parrent = q;
		fixheight(p);
		fixheight(q);
		return q;
	}	
	map_node<Key, T> *insert(map_node<Key, T> *ptr, map_node<Key, T> *parrent, Key k, T val){
		if (this->end->parrent){
			this->delete_end();
		}
		if (!ptr) {
			map_node<Key, T> *temp = new map_node<Key, T>;
			temp->parrent = parrent;
			temp->height = 1;
			temp->pair.first = k;
			temp->pair.second = val;
			temp->right = NULL;
			temp->left = NULL;
			temp->flag_empty = 1;
			return temp;
		}
		if (k < ptr->pair.first) {
			ptr->left = insert(ptr->left, ptr, k, val);
		} else {
			ptr->right = insert(ptr->right, ptr, k, val);
		}
		if (!this->end->parrent)
			this->set_end();		
		return balance(ptr);
	}
	map_node<Key, T> * insert(Key k, T val){
		if (this->root->flag_empty == 0){
			this->root->flag_empty = 1;
			this->root->pair.first = k;
			this->root->pair.second = val;
			return this->root;
		}
		return insert(this->root, this->root, k, val);
	}
	map_node<Key, T> * insert(const std::pair<Key, T> val){
		if (this->root->flag_empty == 0){
			this->root->flag_empty = 1;
			this->root->pair.first = val.first;
			this->root->pair.second = val.second;
			return this->root;
		}
		return insert(this->root, this->root, val.first, val.second);

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