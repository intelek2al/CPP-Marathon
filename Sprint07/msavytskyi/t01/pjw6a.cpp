#include "str/String.h"

#include <cassert>

int main()
{
	{
		CBL::String str;

		assert(str.length() == 0);

		str = "OH MY";

		assert(str == "OH MY");

		std::cout << "Simple string OK" << std::endl;
	}

	{
		CBL::String str;
		str = "Hello Tamriel";

		auto strCpy = str;

		assert(str == strCpy);

		str = CBL::String(str, 2);

		assert(str == "llo Tamriel");

		str = CBL::String(strCpy, 2, 3);

		assert(str == "llo");

		CBL::String itStr(strCpy.begin() + 6, strCpy.end());

		assert(itStr == "Tamriel");

		assert(itStr.front() == 'T');
		assert(itStr.back() == 'l');

		str = CBL::String(10, 'k');

		assert(str == "kkkkkkkkkk");

		str = '!';

		assert(str == "!");

		std::cout << "Constructors OK" << std::endl;
	}

	{
		CBL::String str1;
		str1 = "Hello";
		CBL::String str2;
		str2 = " Tamriel";

		str1 += str2;

		assert(str1 == "Hello Tamriel");

		str1 += " lol";

		assert(str1 == "Hello Tamriel lol");

		str1 += '!';

		assert(str1 == "Hello Tamriel lol!");

		std::cout << "String concat OK" << std::endl;
	}

	{
		CBL::WString str;
		str = L"The standard string class provides support for such objects with"
			  "an interface similar to that of a standard container of bytes, but"
			  "adding features specifically designed to operate with strings of"
			  "single-byte characters.";
		std::string tmp = "The standard string class provides support for such objects with"
						  "an interface similar to that of a standard container of bytes, but"
						  "adding features specifically designed to operate with strings of"
						  "single-byte characters.";

		assert(str.find('p') == 26);
		assert(str.find('p', 30) == 37);
		assert(str.find('p', 210) == CBL::String::npos);
		std::cout << str.rfind('p') << std::endl;
		std::cout << tmp.rfind('p') << std::endl;
		// // assert(str.rfind('p') == 26);
		// std::cout << str.rfind('p', 173) << std::endl;
		// std::cout << tmp.rfind('p', 173) << std::endl;
		// // assert(str.rfind('p', 173) == CBL::WString::npos);
		// std::cout << str.rfind('p', 210) << std::endl;
		// std::cout << tmp.rfind('p', 210) << std::endl;
		// assert(str.rfind('p', 210) == CBL::WString::npos);

		// std::cout << "==========================" << std::endl;
		// std::cout << str.find(L"class") << std::endl;
		// std::cout << tmp.find("class") << std::endl;
		// assert(str.find(L"class") == 20);
		// assert(str.find(CBL::WString(L"class"), 20) == 20);
		// assert(str.find(L"of") == 93);
		// assert(str.find(L"of", 170) == 192);

		// assert(str.rfind(L"class", 50) == CBL::WString::npos);
		// assert(str.rfind(CBL::WString(L"class"), 20) == 20);
		// assert(str.rfind(L"of") == 192);
		// assert(str.rfind(L"of", 170) == 192);

		std::cout << "Find OK" << std::endl;
	}

	{
		CBL::String str;
		str = "some string";

		assert(str.compare("some string") == 0);
		assert(str.compare(str) == 0);

		assert(str.compare("some stri") > 0);
		assert(str.compare("DINGLE BOB") > 0);
		assert(str.compare("z") < 0);

		std::cout << "Comparsion OK" << std::endl;
	}

	{
		CBL::String str;

		str += CBL::String("1") + "2";
		str += "3" + CBL::String("4");
		str += CBL::String("5") + CBL::String("6");
		str += CBL::String("7") + '8';
		str += '9' + CBL::String("0");

		assert(str == "1234567890");

		std::cout << "Concat operators OK" << std::endl;
	}

	{
		CBL::String str1;
		str1 = "lol";
		CBL::String str2;
		str2 = "kek";

		assert(!(str1 == str2));
		assert(str1 != str2);
		assert(!(str1 <= str2));
		assert(!(str1 < str2));
		assert(str1 >= str2);
		assert(str1 > str2);

		std::cout << "Comparsion operators OK" << std::endl;
	}
	return 0;
}
