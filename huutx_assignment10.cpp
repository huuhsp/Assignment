#include "huutx_assignment10.h"

/*************************************************************
* Name: operator+
* Description: Concatenate two strings
* Parameter:
    * const String& str_1
    * const String& str_2
* Return: Result of concatenate two strings
*************************************************************/
String operator+ (const String& str_1, const String& str_2)
{
    String str_plus;
	str_plus = str_1;
	
    int index_1 = 0;
    while(str_1.str[index_1] != '\0'){
		index_1++;
    }
    
    int index_2 = 0;
    while(str_2.str[index_2] != '\0')
    {
        str_plus.str[index_1] = str_2.str[index_2];
        index_1++;
        index_2++;
    }
    return str_plus;
}

/*************************************************************
* Name: operator>>
* Description: Allow string input
* Parameter:
    * istream& Cin
    * String& str
*************************************************************/
istream& operator>> (istream& in, String& str)
{
	str.str = new char[100];
    in >> str.str;
    return in;
}

/*************************************************************
* Name: operator>>
* Description: Allow string output
* Parameter:
    * ostream& Cin
    * String& str
*************************************************************/
ostream& operator<< (ostream& out, String& str)
{
    out << str.str;
    return out;
}

/*************************************************************
* Name: ~String
* Description:
*************************************************************/
String :: ~String()
{
    delete [] str;
}
int main()
{
    String str_1,str_2;
    cout << "Enter string 1: " << endl;
    cin >> str_1;
    cout << "Enter string 2: " << endl;
    cin >> str_2;

	cout << "String after concatenating two substrings: " << endl;
    String str_plus = str_1 + str_2;
    cout << str_plus;
}
