#include "String.h"
#include <iostream>
#include <cassert>

void String::copyStringObject(const String& copyString)
{
	len = copyString.len;
	str = new char[len + 1];
	assert(str != NULL);
	strcpy(str, copyString.str);
}

void String::copyStringChar(const char* copyChar)
{
	len = strlen(copyChar);
	str = new char[len + 1];
	assert(str != NULL);
	strcpy(str, copyChar);
}

void String::deleteString()
{
	delete[] str;
}

String::String() : len(0), str(NULL)
{}

String::String(const char* stringValue)
{
	copyStringChar(stringValue);
}

String::String(const String& copyString)
{
	copyStringObject(copyString);
}

String::String(String&& string)
{
	copyStringObject(string);
	string.str = nullptr;
}

String::~String()
{
	deleteString();
}

const char* String::getStr() const
{
	return str;
}

int String::getLen() const
{
	return len;
}

String& String::operator=(const String& sameString)
{
	if (this != &sameString)
	{
		deleteString();
		copyStringObject(sameString);
	}
	return *this;
}

String& String::operator=(const char* sameString)
{
	deleteString();
	copyStringChar(sameString);
	return *this;
}

std::istream& operator>>(std::istream& iStream, String& string)
{
	char buffer[1000];
	int sizeBuffer = strlen(buffer);
	iStream >> buffer;
	string.len = strlen(buffer);
	string.str = new char[string.len + 1];
	assert(string.str);
	strcpy(string.str, buffer);

	return iStream;
}

std::ostream& operator<<(std::ostream& oStream, String& string)
{
	oStream << string.str;
	return oStream;
}

void String::print() const
{
	for (int i = 0; i < len; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}

bool String::operator==(const char* otherChar)
{
	return !strcmp(str, otherChar);
}

