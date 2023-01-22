
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include "Counter.h"
#include "MyString.h"


// -----------------------------------
// Constructor
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
MyString::MyString(MyString&& other)
{
	m_pCounter = other.m_pCounter;
	other.m_pCounter = nullptr;
}

// -----------------------------------
// Operator =
MyString& MyString::operator=(const MyString& other)
{
	if (m_pCounter != other.m_pCounter)
	{
		if (other.m_pCounter)
		{
			m_pCounter->RemoveOwner();
		}

		m_pCounter = other.m_pCounter;
		if (m_pCounter)
		{
			m_pCounter->AddOwner();
		}
	}
	return *this;
}

// -----------------------------------
// Move operator =
MyString& MyString::operator=(MyString&& other)
{
	if (m_pCounter != other.m_pCounter)
	{
		if (other.m_pCounter)
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
		m_pCounter->RemoveOwner();
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
		this->m_pCounter->RemoveOwner();
		this->m_pCounter->AddString(pStr);
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