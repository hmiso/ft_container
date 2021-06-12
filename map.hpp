#pragma once

# include "avl_tree.hpp"
# include "iterator/map_iterator.hpp"
# include <functional>
# include <memory>
# include <utility>

namespace ft{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > class map{
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef std::pair<const key_type,mapped_type>				value_type;
		typedef std::less<key_type>									key_compare;
		typedef Alloc												allocator_type;
		typedef T&													reference;
		typedef const T&											const_reference;
		typedef T*													pointer;
		typedef const T*											const_pointer;
		typedef Mapiterator<Key, T>									iterator;
		typedef Mapiterator<Key, T>									const_iterator;
		typedef RevMapiterator<Key, T>								reverse_iterator;
		typedef RevMapiterator<Key, T>								const_reverse_iterator;
		typedef ptrdiff_t 											difference_type;
		typedef size_t												size_type;
		typedef avl_tree<key_type, T>								tree;
		
		private:
		avl_tree<Key, T>  start;
		size_t count_map;
		key_compare comp;

		public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			this->count_map = 0;
		}
		
		map (iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			while (first != last) {
				start.insert(*first);
				++first;
				this->count_map++;
			}
		}
		
		map (const map& x);
		
		~map(){}

		map &operator=(const map<Key, T> &other);

		iterator begin(){
			return iterator(this->start.findmin(this->start.root));
		}

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		reverse_iterator rbegin();

		const_reverse_iterator rbegin() const;

		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		mapped_type& operator[] (const key_type& k);

		std::pair<iterator,bool> insert (const value_type& val);

		iterator insert (iterator position, const value_type& val);

		void insert (iterator first, iterator last);

		size_type erase (const key_type& k);

		void erase (iterator first, iterator last);

		void swap (map& x);

		void clear();

		key_compare key_comp() const;

		// value_compare value_comp() const;

		iterator find (const key_type& k);

		const_iterator find (const key_type& k) const;

		size_type count (const key_type& k) const;

		iterator lower_bound (const key_type& k);

		const_iterator lower_bound (const key_type& k) const;

		iterator upper_bound (const key_type& k);

		const_iterator upper_bound (const key_type& k) const;

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

		std::pair<iterator,iterator>             equal_range (const key_type& k);
	};
}