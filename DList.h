#ifndef DLIST_H
#define DLIST_H

#include<iostream>
#include"DListNode.h"
using namespace std;

template<typename K, typename V>
class DListNode;


template<typename K,typename V>
class Entry;

template<typename K, typename V>
class DList{
protected:
	int size;
	DListNode<K,V>* head;
	DListNode<K,V>* tail;
	DListNode<K, V> *newNode(Entry<K, V> item,DListNode <K, V>* prev, DListNode<K, V>* next);
	// class Entry<K, V>;
public:


	DList();

	bool isempty();

	int length();

	void insertBack(const Entry<K, V> &item);

	void insertAfter(const Entry<K, V>& item, DListNode<K, V>* node);

	void remove(DListNode<K, V> *node);

	bool findnode(const Entry<K, V>& item);

	DListNode<K, V>* findsite(const Entry<K, V>& item);
	/*bool equal(const Entry<K, V>& i)
	{
		if (this->item.getkey() == i->getkey())
			return true;
		else return false;
		
	}*/
	void clear();
	
};
#endif