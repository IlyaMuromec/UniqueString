# UniqueStrings
Class MyString has a privite pointer on a node of single list (class Counter).
Feature of this class is holding each string in only one exemplar. 
This feature provides bield-in class Counter that implements special single list.

Member of Counter: 
- a pointer on Counter 'm_pNext' for tracking next node;
- pointer on char (string) 'm_pStr' that node contains;
- variable type size_t 'm_owners' that contains number of owners.

Main methods of Counter:
- 'void AddOwner()' for increasing number oweners same string;
- 'void RemoveOwner()' for decreasing number of owners or deleting string.

Also class Counter has static:
- pointer on Counter 'pHead' as a start point of list;
- variable type size_t 'm_curCounters' that contains number of node (strings) in list;
- methos 'Counter* AddString(const char *)' for findind same string and creating new

Topics studied: embedded objects, operator overloading, move semantics, static data of class, static methods
