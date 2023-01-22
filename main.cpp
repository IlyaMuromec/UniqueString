
#include <iostream>
#include "Counter.h"
#include "MyString.h"

#define	  stop __asm nop

int main()
{
	// test class 

	MyString s1("tyu"); // 1 string "tya"
	MyString s2("zxc"); // 1 string "zxc"
	MyString s3("abc"); // 1 string "abc"
	MyString s4(s3.GetString()); // 2 strings "abc"
	
	MyString s5 = s3; // copy constructor, 3 strings "abc"
	
	s2 = s5; // operator =, 4 strings "abc", delete string "zxc"
	
	const char* str = "akl";
	MyString s11(str);
	MyString::printfAll();

	{
		MyString s9("ccc");
		MyString s6("zxc");
		MyString s7("bbb");
		MyString s10("www");

		MyString::printfAll();
		MyString::sort();
		MyString::printfAll();

		s2 = std::move(s6); // move operator =, 1 string "zxc"
		static MyString s8 = std::move(s7); // move copy constructor, 1 string "bbb"
		MyString::printfAll();
	}

	stop
	std::cout << s11 << std::endl;
	MyString::printfAll();
	s11.SetString("soft");
	MyString::printfAll();
	stop
}