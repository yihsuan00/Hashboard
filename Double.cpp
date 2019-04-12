/**
*  A class that stores a variable of type double and generates a hash code for it.
*
**/
#include <sstream>
#include "Double.h"
#include<string>
#include<iostream>
using namespace std;

/**
*  Construct a new Double with the given variable.
*  @param d the double variable by which the Double stores.
*/
Double::Double(const double& d) {
	this->d = d;
}

/**
*  Get the value of the double variable.
*  @return the stored value.
*/
double Double::getvalue() const {
	return d;
}

/**
*  Returns true if "this" Double and "db" have identical values.
*  @param db is the second Double.
*  @return true if the double values are equal, false otherwise.
*/
bool Double::equals(const Double& db) {
	// Replace the following line with your solution.  Be sure to return false
	//   (rather than throwing a ClassCastException) if "db" is not
	//   a Double.
	if (db.d == d)
		return true;
	else
	return false;
}

/**
*  Returns a hash code for this Double.
*  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
*/
int Double::hashCode() {
	ostringstream strs;//��C++������stringstream function��double ��string
	strs << d;
	string str = strs.str();
	int hash = 0;
	for (int i = 0; i < str.length(); i++)//�Q��string �ഫ�覡��hashcode
	{
		hash = hash + (i + 1)*(int)str[i];//(i+1)�i��[�v�A���ƦC�|�v�Thashcode���M�u�n�զX�@�˴N�|�o��collision���v�Ӱ�

	}
	return hash;
}
