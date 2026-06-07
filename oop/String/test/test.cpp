#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING

#include <iostream>

#include "doctest.h"
#include "String.h"

TEST_CASE("Constuctors test")
{
    String strs[] = { 
						String(), String("Testing strings"), String(strs[1]), 
					  	String(strs[2], 3, 7), String("Hello world!", 12), String(10, 'x')
					};

    CHECK(strs[0].c_str() == "");
    CHECK(strs[1].c_str() == "Testing strings");
    CHECK(strs[2].c_str() == "Testing strings");
    CHECK(strs[3].c_str() == "ting st");
    CHECK(strs[4].c_str() == "Hello world!");
    CHECK(strs[5].c_str() == "xxxxxxxxxx");
}

TEST_CASE("Operators test")
{
    String tmp("Testing string");
	String s1 = tmp, s2 = "Other tests";// s3 = 'x';

    CHECK(s1.c_str() == "Testing string");
    CHECK(s2.c_str() == "Other tests");

    //operator+
	//s1 + s2;
	//s2 + "operator+(char*)";
	//s3 + 'c';

	//operator+=
	//s1 += s2;
	//s2 += "operator+(char*)";
	//s3 += 'c';
	
	//std::cout << "S1 = " << s1 << std::endl;
	//std::cout << "S2 = " << s2 << std::endl;
	//std::cout << "S3 = " << s3 << std::endl;
}

TEST_CASE("Relational operators test")
{
    String s1("It's OK!"), s2("Something wrong?"), s3("Nope, it's fine.");
	
    //operator[]
    CHECK(s2[2] == 'm');
	
	//operator!=
    CHECK((s1 != s2) == true);
    CHECK((s1 != s3) == true);
    CHECK((s2 != s3) == true);
	CHECK((s3 != "something") == true);

	//operator==
    CHECK((s1 == s2) == false);
    CHECK((s1 == s3) == false);
    CHECK((s2 == s3) == false);
	CHECK((s3 == "something") == false);

	//operator>=
    CHECK((s1 >= s2) == true);
    CHECK((s1 >= s3) == true);
    CHECK((s2 >= s3) == true);
	CHECK((s3 >= "something") == true);

	//operator<=
	CHECK((s1 <= s2) == false);
    CHECK((s1 <= s3) == false);
    CHECK((s2 <= s3) == false);
	CHECK((s3 <= "something") == false);

	//operator>
	CHECK((s1 > s2) == true);
    CHECK((s1 > s3) == true);
    CHECK((s2 > s3) == true);
	CHECK((s3 > "something") == true);

	//operator<
	CHECK((s1 < s2) == false);
    CHECK((s1 < s3) == false);
    CHECK((s2 < s3) == false);
	CHECK((s3 < "something") == false);
}

TEST_CASE("I/O test")
{
    String s;
	
	// operator >>
	std::cin >> s;
	
	// operator <<
	std::cout << s << std::endl;
}

TEST_CASE("Additional functions test")
{
    String s1, s2("Testing strings"), s3(s2);
	
    CHECK(s1.length() == 0);
    CHECK(s2.c_str() == "Testing strings");
    CHECK(s3.length() == 15);
}
