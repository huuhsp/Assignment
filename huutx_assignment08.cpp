#include <iostream>
#include <malloc.h>
using namespace  std;
#define Malloc(n) (char*)malloc(n*sizeof(char));

/***************************************************************************
* Name:         findsubstr
* Description:  Find the position of the first sub string in the string str
* Parameter:
        str: parent chain
        sub: substring
* Return:
    Returns the position of the first sub in the string str, otherwise returns -1
****************************************************************************/
int findsubstr(char* str, char* sub)
 {
   for(int i=0;i<_msize(str);i++)
    {
    	bool check1 = true;
    	if(str[i]==sub[0])
    	{
	     	for(int j=0;j<_msize(sub);j++)
	     	{
	     		if(str[i+j]!=sub[j])
					check1 = false;
			}
			if(check1 == true) 
				return i;
		}
    }
 	return -1;
 }
 
int main()
{
    cout << "Enter the length of the parent string: ";
	int n; cin >> n;
    char* str1;
    str1 = Malloc(n);
    cout << "Enter string: ";
    for(int i=0;i<n;i++)
        cin >> str1[i];
    
    cout << "Enter the length of the substring: ";
    int m; cin >> m;
    char* str2;
    str2 = Malloc(m);
    cout << "Enter string: ";
    for(int i=0;i<m;i++)
        cin >> str2[i];

	cout << "position of substring: ";
    cout << findsubstr(str1,str2);
	
}
