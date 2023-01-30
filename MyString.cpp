
#define _CRT_SECURE_NO_WARNINGS

// Class MyString

#include <string>
#include <iostream>
#include "Counter.h"
#include "MyString.h"

// -----------------------------------
// Constructor
// If pStr!=0 then static method AddString try to find in single list same string
// If same string is not exist then method create new string in list 
MyString::MyString(const char* pStr)
{
	if (pStr) 
	{
		this->m_pCounter = Counter::AddString(pStr);
	}
	else
	{
		m_pCounter = nullptr;
	}
}

// -----------------------------------
// Copy constructor
// New string just joins to exist string
MyString::MyString(const MyString& other)
{
	m_pCounter = other.m_pCounter;
	if (m_pCounter)
	{
		m_pCounter->AddOwner();
	}
}

// -----------------------------------
// Move copy constructor
// Create new string instead of another
MyString::MyString(MyString&& other)
{
	m_pCounter = other.m_pCounter;
	other.m_pCounter = nullptr;
}

// -----------------------------------
// Operator =
// Replace one string by another
MyString& MyString::operator=(const MyString& other) 
{
	if (m_pCounter != other.m_pCounter)
	{
		if (/*other.*/m_pCounter)
		{
			m_pCounter->RemoveOwner(); // decrease number of owners or delete string
		}

		m_pCounter = other.m_pCounter;
		if (m_pCounter)
		{
			m_pCounter->AddOwner(); // increase number of owners
		}
	}
	return *this;
}

// -----------------------------------
// Move operator =
// Replace one string by another
MyString& MyString::operator=(MyString&& other)
{
	if (m_pCounter != other.m_pCounter) 
	{
		if (m_pCounter) 
		{
			m_pCounter->RemoveOwner();
		}
		m_pCounter = other.m_pCounter;
		other.m_pCounter = nullptr;
	}
	return *this;
}

// ----------------------------------
// Destructor
MyString::~MyString()
{
	if (m_pCounter)
	{
		m_pCounter->RemoveOwner(); // decrease number of owners or delete string
	}
}

// -----------------------------------
// Methods of class
const char* MyString::GetString(void)
{
	return this->m_pCounter->m_pStr;
}


void MyString::SetString(const char * pStr)
{
	if (strcmp(this->m_pCounter->m_pStr, pStr)!=0) 
	{
		if (m_pCounter)
		{
			this->m_pCounter->RemoveOwner();  // decrease number of owners or delete string
		}
		this->m_pCounter->AddString(pStr); // method AddString creates new string in list 
	}
}

//-------------------------------------
// Static method
void MyString::printfAll(void)
{
	Counter::printfAll();
}

void MyString::sort(void)
{
	Counter::sort();
}

//----------------------------------------
// global function
std::ostream& operator<<(std::ostream& os, MyString& s)
{
	os << "\nString:\n" << s.m_pCounter;
	return os;
}