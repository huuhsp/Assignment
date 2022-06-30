#include <iostream>
using namespace std;

float fplus(float a, float b)
{
    return a+b;
}

float fminus(float a, float b)
{
    return a-b;
}

float fmultiply(float a, float b)
{
    return a*b;
}

float fdivide(float a, float b)
{
    if(b==0)
    {
        throw "cannot be divided by zero";
    }
    else 
        return a/b;
}

void operation(float a, float b, float(*p2Func)(float,float))
{
	cout << (*p2Func)(a,b);
}

int main()
{
    float a,b; 
    cout << "Enter number a and b: ";
    cin >> a >> b;
    
    float(*pPlus) (float, float) = fplus;
    float(*pMinus) (float, float) = fminus;
    float(*pMultiply) (float, float) = fmultiply;
    float(*pDivide) (float, float) = fdivide;
    
    cout << endl << "Plus two number: ";
    operation(a,b,fplus);
    cout << endl << "Minus two number: ";
    operation(a,b,fminus);
    cout << endl << "Multiply two number: ";
    operation(a,b,fmultiply);
    
	try{
    cout << endl << "Divide two number: ";
    operation(a,b,fdivide);
	}catch(const char* msg) {
    cout << msg << endl;
   }
	
}
