#include<iostream>
#include"DList.h"
using namespace std;

template<typename K,typename V>
DListNode<K, V> * DList<K,V>::newNode(Entry<K, V> item,
	DListNode <K, V>* prev, DListNode<K, V>* next) {
	return new DListNode<K, V>(item, prev, next);
}

template<typename K, typename V>
DList<K, V>::DList() {
	head = tail = NULL;
	size = 0;
}

template<typename K, typename V>
bool DList<K, V>:: isempty() {
	return size == 0;
}

template<typename K, typename V>
int DList<K, V>:: length() {
	return size;
}

template<typename K, typename V>
void DList<K, V>::insertBack(const Entry<K, V> &item)
{
	DListNode<K, V>*back;
	back = newNode(item, tail, NULL);
	if (isempty())
	{
		head = back;
		tail = back;
	}
	else {
		tail->next = back;
	}
	size++;
	
}

template<typename K, typename V>
void DList<K, V>::insertAfter(const Entry<K, V>& item, DListNode<K, V>* node) {
	if (node == NULL)
		return;
	DListNode<K, V>* tmp;
	tmp = newNode(item, node, node->next);
	node->next->prev = tmp;
	node->next = tmp;
	size++;

}

template<typename K, typename V>
void DList<K, V>::remove(DListNode<K, V> *node)
{
	if (node == NULL)
		return;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	node = 0;//Á×§K½sÄ¶¿ù»~;
	size--;
}

template<typename K, typename V>
bool DList<K, V>::findnode(const Entry<K, V>& item)
{
	bool finditem = false;
	DListNode<K, V> *current = head;
	while (current != NULL, current->equal(item) == false)
	{
		current = current->next;
		if (current->equal(item))
			finditem = true;
	}
	if (current->equal(item))
		finditem = true;

	return finditem;

}

template<typename K, typename V>
DListNode<K, V>* DList<K, V>::findsite(const Entry<K, V>& item)
{
	DListNode<K, V> *current = head;
	while (current != NULL, current->equal(item) == false)
	{
		current = current->next;
		if (current->equal(item))
			return current;
	}
	if (current->equal(item))
		return current;
	else
	{
		current = NULL;
		return current;
	}

}

template<typename K, typename V>
void DList<K, V>::clear()
{
	DListNode<K, V> *current = head;


	while (current != NULL)
	{
		DListNode<K, V> *temp = current->next;
		remove(current);
		temp = current;
	}
}