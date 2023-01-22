
#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <iostream>
#include "Counter.h"

// definition of static members of class Counter 
size_t Counter::m_curCounters=0; 
Counter* Counter::pHead=nullptr;

Counter::Counter(const char* pStr): m_owners(1)
{
	m_pStr = new char [strlen(pStr)+1];
	strcpy(m_pStr, pStr);

	m_curCounters++;
	m_pNext = nullptr;
}

Counter::~Counter()
{
	delete m_pStr;
}

void Counter::AddOwner()
{
	m_owners++;
}

void Counter::RemoveOwner()
{
	m_owners--;
	if (m_owners == 0)
	{
		if (this != Counter::pHead)
		{
			Counter* p = Counter::pHead; 
			size_t tmp = Counter::m_curCounters-1;
			
			while (p->m_pNext != this)
			{
				p = p->m_pNext;
				tmp--;
			}
			if (tmp) 
			{
				p->m_pNext = this->m_pNext; // for case when this is not last node
			}
			else 
			{
				p->m_pNext = nullptr; // for case when this is last node
			}
		}
		else
		{
			if (Counter::m_curCounters>1)
			{
				Counter::pHead = Counter::pHead->m_pNext;
			}
		}
		delete this;
		m_curCounters--;
	}
}

Counter* Counter::AddString(const char* pStr)
{
	Counter* p = pHead;
	Counter* p_last = pHead;

	if (m_curCounters > 0)
	{
		while (p != nullptr) // enter
		{
			if (strcmp(p->m_pStr, pStr) == 0) // match 
			{
				p->AddOwner();
				return p;
			}
			p_last = p;
			p = p->m_pNext;
		}
		p_last->m_pNext = new Counter(pStr);
		return p_last->m_pNext;
	}
	else
	{
		pHead = new Counter(pStr);
		return pHead;
	}
}

//--------------
void Counter::printfAll(void)
{
	if (Counter::m_curCounters)
	{
		size_t N = Counter::m_curCounters;
		Counter* p = Counter::pHead;
		std::cout << "\nPrint all strings:\n";
		for (size_t i = 0; i < N; i++)
		{
			std::cout << p->m_pStr << " number: " << p->m_owners << '\n';
			p = p->m_pNext;
		}
	}
}

void Counter::sort(void)
{
	if (Counter::m_curCounters > 1)
	{
		size_t N = Counter::m_curCounters;
		int flag = 1;
		for (int i = 0; flag == 1; i++)
		{
			Counter* p = Counter::pHead;
			Counter* pp = Counter::pHead;
			flag = 0;
			for (int j = 0; j < (N - i - 1); j++)
			{
				if (strcmp(p->m_pStr, p->m_pNext->m_pStr) < 0)
				{
					if (p == Counter::pHead) // Head=p=s1->s2->s3
					{
						Counter::pHead = Counter::pHead->m_pNext;	// Head=s2
						p->m_pNext = p->m_pNext->m_pNext;			// s1->s3
						Counter::pHead->m_pNext = p;				// s2->s1->s3
						pp = Counter::pHead;						// pp->s2, p->s1, 
					}
					else // ...sn0->sn1->sn2->sn3..., pp=sn0, p=sn1
					{
						pp->m_pNext = pp->m_pNext->m_pNext;	// pp=sn0->sn2
						p->m_pNext = p->m_pNext->m_pNext;	// p=sn1->sn3
						pp->m_pNext->m_pNext = p;			// ...sn0->sn2->sn1->sn3...
						pp = pp->m_pNext;					// pp=sn2
						p = pp->m_pNext;					// p=sn1
					}
					flag = 1;
				}
				else
				{
					pp = p;
					p = p->m_pNext;
				}
			}
		}
	}
}


std::ostream& operator<<(std::ostream& os, Counter* c)
{
	os << c->m_pStr<< " number: " << c->m_owners;

	return os;
}

