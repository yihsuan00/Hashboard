/**
*  HashTableChained extends a Dictionary as a hash table with chaining.
*  All objects used as keys must have a valid hashCode() method, which is
*  used to determine which bucket of the hash table an entry is stored in.
*  Each object's hashCode() is presumed to return an int between
*  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
*  implements only the compression function, which maps the hash code to
*  a bucket in the table's range.
*
*  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
**/

#ifndef HASHTABLECHAINED_H
#define HASHTABLECHAINED_H

#include "Dictionary.h"
#include "DList.h"
#include<math.h>

template<typename K, typename V>
class DList;

template<typename K, typename V>
class DListNode;




template<typename K, typename V>
class HashTableChained : public Dictionary<K, V> {
private:

	/**
	*  Place any data fields here.
	**/
	int count;//the total number of the entries in the hashtable;
	float loadfactor;//the load factor of the hash table;
	DList<K,V> *table;
	int collisionboom;


public:
	int capacity;//創建新table要用
	friend class String;
	friend class Double;
	friend class Integer;
	friend class DList<K,V>;
	friend class DListNode<K,V>;
	friend class Entry<K,V>;


	/**
	*  Construct a new empty hash table intended to hold roughly sizeEstimate
	*  entries.  (The precise number of buckets is up to you, but we recommend
	*  you use a prime number, and shoot for a load factor between 0.5 and 1.)
	**/
	HashTableChained(int sizeEstimate);

	/**
	*  Construct a new empty hash table with a default size.  Say, a prime in
	*  the neighborhood of 100.
	**/
	HashTableChained();

	/**
	*  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
	*  to a value in the range 0...(size of hash table) - 1.
	*
	*  This function should be used by insert, find, and remove.
	**/
	int compFunction(int code);

	/**
	*  Returns the number of entries stored in the dictionary.  Entries with
	*  the same key (or even the same key and value) each still count as
	*  a separate entry.
	*  @return number of entries in the dictionary.
	**/
	virtual int size();

	/**
	*  Tests if the dictionary is empty.
	*
	*  @return true if the dictionary has no entries; false otherwise.
	**/
	virtual bool isEmpty();

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
	virtual void insert(const K& key, const V& value);

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
	virtual bool find(const K& key);

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
	virtual void remove(const K&  key);

	/**
	*  Remove all entries from the dictionary.
	*/
	virtual void makeEmpty();
	/**
	*  let table has the proper buckets.
	*/
	int getnearprime(int i);
	/**
	*  estimate whether the input number is prime
	*/
	bool isprime(int i);
	/**
	*  print the nuber of entries in each bucket;
	*  get the collision number;
	*/
	void printHashtable();
};

#endif

