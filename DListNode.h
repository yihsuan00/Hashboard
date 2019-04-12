#ifndef DLISTNODE_H
#define DLISTNODE_H

#include<iostream>
using namespace std;

template<typename K,typename V>
class DList;


template<typename K, typename V>
class Entry;

template<typename K, typename V>
class DListNode {

public:
	Entry<K,V> item;
	DListNode<K, V>* prev;
	DListNode<K, V>* next;
	friend class DList<K, V>;
	DListNode(const Entry<K,V>& i, DListNode<K, V>* p, DListNode<K, V>* n) {
		item = i;
		prev = p;
		next = n;
	}
	bool equal(const Entry<K, V>& i)
	{
		if (item.getkey() == i.getkey())
			return true;
		else return false;

	}
};
#endif

