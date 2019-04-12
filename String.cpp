/**
*  A class that stores a string and generates a hash code for it.
*
**/

#include "String.h"
#include<string>

/**
*  Construct a new String with the given variable.
*  @param str the string by which the String stores.
*/
String::String(const string& str) {
	this->str = str;
}

/**
*  Get the value of the string variable.
*  @return the stored value.
*/
string String::getvalue() const {
	return str;
}


/**
*  Returns true if "this" String and "strg" have identical values.
*  @param strg is the second String.
*  @return true if the string values are equal, false otherwise.
*/
bool String::equals(const String& strg) {
	// Replace the following line with your solution.  Be sure to return false
	//   (rather than throwing a ClassCastException) if "strg" is not
	//   a String.
	if (strg.str == str)
		return true;
	else
		return false;
}

/**
*  Returns a hash code for this String.
*  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
*/
int String::hashCode() {
	int hash = 0;
	for (int i = 0; i < str.length(); i++)
	{
		hash = hash + (i + 1)*(int)str[i];//(i+1)進行加權，讓排列會影響hashcode不然只要組合一樣就會發生collision機率太高

	}
	// Replace the following line with your solution.
	return hash;
}
