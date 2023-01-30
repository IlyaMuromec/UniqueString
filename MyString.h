#pragma once

// Class MyString
// Class MyString has a privite pointer on element of single list (Counter).
// Feature of class is holding each string in only one exemplar. 
// This feature provides bield-in class Counter that implements special single list

class MyString
{
	Counter* m_pCounter;

public:
	MyString(const char*);
	MyString(const MyString&);
	MyString(MyString&&);
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);
	~MyString();

	const char* GetString(void);
	void SetString(const char*);

	static void printfAll(void);
	static void sort(void);

	friend std::ostream& operator<<(std::ostream& os, MyString& s);
};

std::ostream& operator<<(std::ostream& os, MyString& s);