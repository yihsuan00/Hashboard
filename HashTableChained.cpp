/**
*  HashTableChained extends a Dictionary as a hash table with chaining.
*  All objects used as keys must have a valid hashCode() method, which is
*  used to determine which bucket of the hash table an entry is stored in.
*  Each object's hashCode() is presumed to return an int between
*  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
*  implements only the compression function, which maps the hash code to
*  a bucket in the table's range.
*
**/

#include "HashTableChained.h"
#include"DList.h"
//#include "String.h"
//#include"String.cpp"
//#include"Double.cpp"
//#include"Integer.h"
//#include "Double.h"
#include<math.h>
#include<iostream>
#include "Entry.h"

template<typename K, typename V>
bool HashTableChained<K, V>::isprime(int i)
{
	if (i< 2)
		return false;
	for (int j = 2; j <= sqrt(i); j++) {
		if (i % j == 0)
			return false;
	}//檢驗質數的過程

	return true;
}
template<typename K, typename V>
int HashTableChained<K, V>::getnearprime(int i)
{
	int a;
	if (isprime(i))
		a = i;
	else {
		while (isprime(i) == false)
		{ 
			i++;
			if (isprime(i))
				a=i;
		}
		}
	return a;
}

/**
*  Construct a new empty hash table intended to hold roughly sizeEstimate
*  entries.  (The precise number of buckets is up to you, but we recommend
*  you use a prime number, and shoot for a load factor between 0.5 and 1.)
**/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
	loadfactor = 0.7f;
	capacity = getnearprime(int(sizeEstimate / loadfactor));
	table = new DList<K,V>[capacity];
	/*for (int i = 0; i <= capacity; i++)
	{
		table[i] = new DList();
	}*/
	count = 0;
	collisionboom = 0;
}

/**
*  Construct a new empty hash table with a default size.  Say, a prime in
*  the neighborhood of 100.
**/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
	capacity = 101;
	table = new DList<K,V>[capacity];
	/*for (int i = 0; i <= capacity; i++)
	{
		table[i] = new DList();
	}*/
	count = 0;
	collisionboom = 0;
}
	// Your solution here.


/**
*  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
*  to a value in the range 0...(size of hash table) - 1.
*
*  This function should have package protection (so we can test it), and
*  should be used by insert, find, and remove.
**/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
	

	// Replace the following line with your solution.
	return code%capacity;
}

/**
*  Returns the number of entries stored in the dictionary.  Entries with
*  the same key (or even the same key and value) each still count as
*  a separate entry.
*  @return number of entries in the dictionary.
**/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
	// Replace the following line with your solution.
	return count;
}

/**
*  Tests if the dictionary is empty.
*
*  @return true if the dictionary has no entries; false otherwise.
**/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
	if (size() == 0)
		return true;
	else
		return false;
}

/**
*  Create a new Entry object referencing the input key and associated value,
*  and insert the entry into the dictionary.
*  Multiple entries with the same key (or even the same key and
*  value) can coexist in the dictionary.
*
*  This method should run in O(1) time if the number of collisions is small.
*
*  @param key the key by which the entry can be retrieved.
*  @param value an arbitrary object.
**/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
	Entry<K,V> e(key, value);
	int index = compFunction(key->hashCode());
	DList<K,V> bucket = table[index];	
	if (bucket.isempty() == false)
	{
		collisionboom++;
	}
	table[index].insertBack(e);
	count++;
}



	// Replace the following line with your solution

/**
*  Search for an entry with the specified key.  If such an entry is found,
*  return true; otherwise return false.
*
*  This method should run in O(1) time if the number of collisions is small.
*
*  @param key the search key.
*  @return true if an entry containing the key is found, or false if
*          no entry contains the specified key.
**/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
	int index = compFunction(key->hashCode());
	DList<K,V> bucket = table[index];
	Entry<K, V>e(key, NULL);
	return bucket.findnode(e);
	
	


	// Replace the following line with your solution.
}

/**
*  Remove an entry with the specified key.  If such an entry is found,
*  remove it from the table.
*  If several entries have the specified key, choose one arbitrarily, then
*  remove it.
*
*  This method should run in O(1) time if the number of collisions is small.
*
*  @param key the search key.
*/
template<typename K, typename V>
void HashTableChained<K,V>::remove(const K&  key) {
	int index = compFunction(key->hashCode());
	DList<K,V> bucket = table[index];
	Entry<K, V>e(key, NULL);
	if (bucket.isempty())
		return;
	else 
	{
		bucket.remove(bucket.findsite(e));
		count--;
	}
}
	


	// Replace the following line with your solution.


/**
*  Remove all entries from the dictionary.
*/
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
	if (isEmpty())
		return;
	else {
		for (int i = 0; i < capacity; i++)
		{
			table[i].clear();//負責清空所有的element
		}
	}
	count = 0;
}
	// Your solution here.

template<typename K, typename V>
void HashTableChained<K, V>::printHashtable()
{
	int k = 0;
	for (int i = 0; i < capacity; i++)
	{
		DList<K, V> bucket = table[i];
		cout << "table" <<  i << "has" << table[i].length()<<"\n";
		if(table[i].length()>1)
			k = k + table[i].length() - 1;
	}
	cout << "total collision : " << k<<"\n";
	cout << "collision: " << collisionboom;

	
}

