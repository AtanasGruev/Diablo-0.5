#ifndef STRING_STRING_STRING_H_
#define STRING_STRING_STRING_H_

#pragma warning(disable : 4996)

#include <iostream>

class String
{
private:
	char* str; //actual string 
	int len; //length of string
	void copyStringObject(const String&); //function to copy member-data "str" from another String object
	void copyStringChar(const char*); //function to copy an array of characters
	void deleteString(); //deletes dynamically-allocated memory
public:
	String(); //default constructor
	String(const char*); //constructor with parameters
	String(const String&); //copy constructor
	String(String&&); //move constructor
	~String(); //destructor

	//getters
	const char* getStr() const;
	int getLen() const;

	//copy assignement operator and operator>>
	String& operator=(const String&);
	String& operator=(const char*);	
	bool operator==(const char*);
	friend std::istream& operator>>(std::istream& iStream, String& string);
	friend std::ostream& operator<<(std::ostream& oStream, String& string);

	//prints string
	void print() const;
};

#endif // !STRING_STRING_STRING_H_

