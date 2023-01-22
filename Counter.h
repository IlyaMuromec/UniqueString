#pragma once

// Counter represent unidirectional list with unique strings
class Counter
{
	Counter* m_pNext; 
	char * m_pStr; // pointer on dynamically created string
	size_t m_owners; // counter of owners of this string

	Counter(const char *p);
	void AddOwner();
	void RemoveOwner();
	~Counter();
	friend class MyString;

	static size_t m_curCounters; // counter of unique strings
	static Counter* pHead; // the first object in one direction list
	static Counter* AddString(const char *);
	void static printfAll(void);
	void static sort(void);
 
	friend std::ostream& operator<<(std::ostream& os, Counter* c);
};

std::ostream& operator<<(std::ostream& os, Counter* c);