#include <iostream>

using namespace std;

class String
{
    public:
		char* str;
	public:
		~String();
		friend String operator + (const String&, const String&);
		friend ostream& operator << (ostream&, String&);
		friend istream& operator >> (istream&, String&);
};
