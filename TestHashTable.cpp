
/**
* 做一個hashtable把資料儲存進去並有一些基礎的資料功能
*
* @author 			陳怡瑄
* @ID 				b05505046
* @Department 		Engineering Science and Ocean Engineering
* @Affiliation 	National Taiwan University
*
* TestHashTable.cpp
* version 1.0
*/

#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.cpp"
#include "HashTableChained.h"
#include"String.h"
#include"Double.h"
#include "CheckerBoard.h"
#include "Entry.h"
#include "DList.h"
#include "DList.cpp"
#include <process.h>

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards);
template<typename K, typename V>
void initDouble(HashTableChained<K, V>* table, int numBoards);
template<typename K, typename V>
void initString(HashTableChained<K, V>* table, int numBoards);
CheckerBoard* randomBoard();

int main() {

	// initialize random seed:
	srand(time(NULL));

	int numBoards = 100;

	HashTableChained<CheckerBoard*, Integer*>* table = new HashTableChained<CheckerBoard*, Integer*>(numBoards);
	initTable(table, numBoards);

	HashTableChained<Double*, Integer*>* doub = new HashTableChained<Double*, Integer*>(numBoards);
	initDouble(doub, numBoards);


	HashTableChained<String*, Integer*>* str = new HashTableChained<String*, Integer*>(numBoards);
	initString(str, numBoards);

	cout << endl << "----------checkerboard----------" << endl;
	table->printHashtable();
	cout << endl << "----------double----------" << endl;
	doub->printHashtable();
	cout << endl << "----------string----------" << endl;
	str->printHashtable();
	cout << endl << "----------string----------" << endl;
	




	system("pause");
	return 0;
	// To test your hash function, add a method to your HashTableChained class
	// that counts the number of collisions--or better yet, also prints
	// a histograph of the number of entries in each bucket.  Call this method
	// from here.
}


/**
*  Generates a random 8 x 8 CheckerBoard.
**/
CheckerBoard* randomBoard() {
	CheckerBoard* board = new CheckerBoard;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board->setElementAt(x, y, rand());
		}
	}
	return board;
}


/**
*  Empties the given table, then inserts "numBoards" boards into the table.
*  @param table is the hash table to be initialized.
*  @param numBoards is the number of random boards to place in the table.
**/
template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
	table->makeEmpty();
	for (int i = 0; i < numBoards; i++) {
		table->insert(randomBoard(), new Integer(i));
	}
}

/**
*  Generates a random string board.
**/
String* randomString() {
	string b = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string random;
	for (int i = 0; i < 10; i++){
		random.push_back(b.at(size_t(rand() % 31)));
	}
	String *x = new String(random);

	return x;}
template<typename K, typename V>
void initString(HashTableChained<K, V>* table, int numBoards)
{
	table->makeEmpty();
	for (int i = 0; i < numBoards; i++) {
		table->insert(randomString(), new Integer(i));
	}
}

/**
*  Generates a random Double board.
**/
Double* randomDouble() {
	Double*a = new Double(rand() / (RAND_MAX + 1.0)*rand());
	return a;
}
template<typename K, typename V>
void initDouble(HashTableChained<K, V>* table, int numBoards)
{
	table->makeEmpty();
	for (int i = 0; i < numBoards; i++) {
		table->insert(randomDouble(), new Integer(i));
	}
}