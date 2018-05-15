#ifndef STRING_STRING_STRING_H_
#define STRING_STRING_STRING_H_

#pragma warning(disable : 4996)

class String
{
private:
	char* str; //actual string 
	int len; //length of string
	void copyStringObject(const String&); //function to copy member-data "str" from another String object
	void copyStringChar(const char*); //function to copy an array of characters
	void deleteString(); //deletes dynamically-allocated memory
	void safeString(); //saves a string in order for it to be extended (+= and + operators)
public:
	String(); //default constructor
	String(const char*); //constructor with parameters
	String(const String&); //copy constructor
	String(String&&); //move constructor
	~String(); //destructor

	//getters
	const char* getStr() const;
	int getLen() const;

	//copy assignement operator
	String& operator=(const String&);
	String& operator=(const char*);	

	//prints string
	void print() const;
};

#endif // !STRING_STRING_STRING_H_

