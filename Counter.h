#pragma once

// Counter implements single list with unique strings
class Counter
{
	Counter* m_pNext;  // pointer on next node of list
	char * m_pStr; // pointer on dynamically created string
	size_t m_owners; // counter of owners of this string

	Counter(const char *p);
	void AddOwner(); // increase number oweners same string
	void RemoveOwner(); // decrease number of owners or delete string
	~Counter();
	friend class MyString;

	static size_t m_curCounters; // counter of unique node (strings) in list
	static Counter* pHead; // the first object in list
	static Counter* AddString(const char *); // find same string in list or create new
	void static printfAll(void);
	void static sort(void);
 
	friend std::ostream& operator<<(std::ostream& os, Counter* c);
};

std::ostream& operator<<(std::ostream& os, Counter* c);