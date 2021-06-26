#pragma once

# include "avl_tree.hpp"
# include "iterator/map_iterator.hpp"
# include <functional>
# include <memory>
# include <utility>

namespace ft{

template<class Pair, class KeyComp>
struct pair_comp
{
    KeyComp _kcomp;

    pair_comp(const KeyComp& kc = KeyComp()) : _kcomp(kc) {}

    bool operator()(const Pair& p1, const Pair& p2) const
    {
        return _kcomp(p1.first,p2.first);
    }
};

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
		typedef Mapiterator<Key, T, Compare>									iterator;
		typedef Mapiterator<Key, T, Compare>									const_iterator;
		typedef RevMapiterator<Key, T, Compare>								reverse_iterator;
		typedef RevMapiterator<Key, T, Compare>								const_reverse_iterator;
		typedef ptrdiff_t 											difference_type;
		typedef size_t												size_type;
		typedef avl_tree<key_type, T, Compare>								tree;
		typedef pair_comp<value_type, key_compare> 					value_compare;
		private:
		avl_tree<Key, T, Compare>  start;
		size_t count_map;
		key_compare comp;

		public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			this->count_map = 0;
		}
		
		map (iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			this->count_map = 0;
			while (first != last) {
				this->insert(*first);
				++first;
				this->count_map++;
			}
		}
		
		map (const map& x){
			this->count_map = 0;			
			iterator beg = x.begin();
			iterator en = x.end();
			while (beg != en){
				this->insert(*beg);
				++beg;
				this->count_map++;
			}
			
		}
		
		~map(){
			if (this->start.root)
				this->start.deletes(this->start.root);
		}

		map &operator=(const map<Key, T> &other){
			this->count_map = other.count_map;
			const_iterator it = other.begin();
			const_iterator it2 = other.end();
			while (it != it2) {
				this->insert(*it);
				++it;
			}
			return (*this);
		}

		iterator begin(){
			return iterator(this->start.findmin(this->start.root));
		}

		const_iterator begin() const{
			return const_iterator(this->start.findmin(this->start.root));
		}

		iterator end(){
			if (this->start.root->right->end == true){
				return this->start.root;
			}
			return (this->start.end);
		}

		const_iterator end() const{
			return (this->start.end);
		}

		reverse_iterator rbegin(){
			return reverse_iterator(this->start.end);
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(this->start.end);
		}

		bool empty() const{
			if (this->count_map == 0){
				return true;
			} else {
				return false;
			}
		}

		size_type size() const{
			return this->count_map;
		}

		size_type max_size() const{
			return allocator_type().max_size();
		}

		mapped_type& operator[] (const key_type& k){
			iterator its = begin();
			for (iterator it = begin(); it != end(); ++it)
			{
				if (it->first == k)
					return (it->second);
			}
			insert(std::pair<key_type, mapped_type>(k, 0));
			for (iterator it = begin(); it != end(); ++it)
			{
				if (it->first == k)
					return (it->second);
			}
			return (its->second);
		}

		std::pair<iterator,bool> insert(const value_type& val){
			iterator it = this->begin();
			iterator it2 = this->end();
			while (it != it2){
				if (it->first == val.first){
					return std::pair<iterator, bool>(it, 0);
				}
				++it;
			}
			this->start.root = this->start.insert(val);
			this->count_map++;
			return(std::pair<iterator, bool>(it, 1));

		}

		iterator insert (iterator position, const value_type& val){
			iterator next = position--;
			if (position.func && position->first < val.first && next->first > val.first){
				this->start.insert(position.func, val);
				return ++position;
			} else {
				return insert(val).first;
			}
		}

		void insert (iterator first, iterator last){
			while (first != last){
				this->count_map++;
				this->start.root = this->start.insert(*first);
				++first;
			}
		}

		size_type erase (const key_type& k){
			size_type count = 0;
			iterator it = this->begin();
			iterator it2 = this->end();
			while (it != it2){
				if (it->first == k){
					this->start.remove(*it);
					count++;
					--this->count_map;
				}
			}
			return count;
		}

		void erase (iterator first, iterator last){
			while (first != last) {
				iterator tmp = first++;
				erase(tmp);
			}
		}
		void erase (iterator position){
			start.remove(*position);
			--this->count_map;
		}

		void swap (map& x){
				map_node<Key, T> *tmp_root;
				map_node<Key, T> *tmp_end;
				tmp_root= x.start.root;
				tmp_end = x.start.end;
				x.start = this->start;
				size_t count_tmp = x.count_map;
				x.count_map = this->count_map;
				this->start.root = tmp_root;
				this->start.end = tmp_end;
				this->count_map = count_tmp;
		}

		void clear(){
			erase(this->begin(), this->end());
		}

		key_compare key_comp() const{
			return this->comp;
		}

		value_compare value_comp() const{
			return this->comp;
		}

		iterator find (const key_type& k){
			iterator i = begin();
			for (; i != end(); ++i) {
				if (i->first == k)
					break ;
			}
			return i;			
		}

		const_iterator find (const key_type& k) const{
			const_iterator i = begin();
			for (; i != end(); ++i) {
				if (i->first == k)
					break ;
			}
			return i;
		}

		size_type count (const key_type& k) const{
			size_type count = 0;
			for (const_iterator i = begin(); i != end(); ++i) {
				if (i->first == k)
					++count;
			}
			return count;			
		}

		iterator lower_bound (const key_type& k){
			iterator i = begin();
			while (i != end() && comp(i->first, k))
				++i;
			return i;			
		}

		const_iterator lower_bound (const key_type& k) const{
			const_iterator i = begin();
			while (i != end() && comp(i->first, k))
				++i;
			return i;			
		}

		iterator upper_bound (const key_type& k){
			iterator i = begin();
			while (i != end() && comp(i->first, k))
				++i;
			if (i != end())
				++i;
			return i;			
		}

		const_iterator upper_bound (const key_type& k) const{
			const_iterator i = begin();
			while (i != end() && comp(i->first, k))
				++i;
			if (i != end() && i->first != k)
				++i;
			return i;			
		}

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return std::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
		}

		std::pair<iterator,iterator> equal_range (const key_type& k){
			return std::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
		}

			friend bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
			const_iterator i = lhs.begin();
			const_iterator j = rhs.begin();

			while (i != lhs.end() && j != rhs.end())
			{
				if (i->first != j->first)
					return false;
				++i;
				++j;
			}
			if (i != lhs.end() || j != rhs.end())
				return false;
			return true;
		}

		friend bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs ) {
			return !(lhs == rhs);
		}

		friend bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs,
            const ft::map<Key, T, Compare, Alloc>& rhs ) {
			if (lhs.size() < rhs.size())
				return true;
			else if (lhs.size() > rhs.size())
				return false;
			else {
				const_iterator j = rhs.begin();
				for (const_iterator i = lhs.begin(); i != lhs.end(); ++i) {
					if (i->first < j->first)
						return true;
					if (i->first > j->first)
						return false;
					++j;
				}
				return false;
			}
		}
	
		friend bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs,
        	const ft::map<Key, T, Compare, Alloc>& rhs ) {
			return !(rhs < lhs);
		}

		friend bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs,
            const ft::map<Key, T, Compare, Alloc>& rhs ) {
			return rhs < lhs;
		}
		
		friend bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs ) {
			return !(lhs < rhs);
		}
	};
}