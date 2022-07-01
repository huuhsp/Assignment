#include "huutx_assignment09.h"

/****************************************************************************************
* Name:         ImportData
* Description:  Import numerator and denominator
* Parameter:    CFraction &CFraction_
* Return:       Void
****************************************************************************************/
void CFraction :: ImportData(CFraction &CFraction_)
{
    cout << "Numerator value: ";
    cin >> CFraction_.num;
    while(1)
    {
    cout << "Denominator value: ";
    cin >> CFraction_.den;
    if(CFraction_.den == 0)
    	cout << "The denominator must be non-zero, retype!" << endl;
    else break;
	}
}

/****************************************************************************************
* Name:         ExportData
* Description:  Export fractions
* Parameter:    CFraction &CFraction_
* Return:       Void
****************************************************************************************/
void CFraction :: ExportData(CFraction &CFraction_)
{
	if(CFraction_.num == 0) cout << CFraction_.num;
	else if(CFraction_.den == 1) cout << CFraction_.num;
	else cout << CFraction_.num << "/" << CFraction_.den;
}

/****************************************************************************************
* Name:         Compact
* Description:  Compact fractions
* Parameter:    CFraction &CFraction_
* Return:       Void
****************************************************************************************/
void CFraction :: Compact(CFraction &CFraction_)
{
	for(int i = (CFraction_.num < CFraction_.den ? CFraction_.num : CFraction_.den); i>=2; i--)
    {
        if(CFraction_.den%i==0 && CFraction_.num%i==0)
        {
            CFraction_.num/=i;
            CFraction_.den/=i;
            break;
        }
    }
}

/****************************************************************************************
* Name:         operator+
* Description:  Support plus two fractions.
* Parameter:    CFraction &CFraction_
* Return:       The result of the plus of two fractions
****************************************************************************************/
CFraction operator+ (const CFraction& CFraction_1, const CFraction& CFraction_2)
{
    CFraction CFraction_Value;
	CFraction_Value.num = CFraction_1.num*CFraction_2.den + CFraction_2.num*CFraction_1.den;
    CFraction_Value.den = CFraction_1.den * CFraction_2.den;
    
    CFraction_Value.Compact(CFraction_Value);
    return CFraction_Value;
}

/****************************************************************************************
* Name:         operator-
* Description:  Support subtract two fractions.
* Parameter:    CFraction &CFraction_
* Return:       The result of the subtract of two fractions
****************************************************************************************/
CFraction operator- (const CFraction& CFraction_1, const CFraction& CFraction_2)
{
    CFraction CFraction_Value;
	CFraction_Value.num = CFraction_1.num*CFraction_2.den - CFraction_2.num*CFraction_1.den;
    CFraction_Value.den = CFraction_1.den * CFraction_2.den;
    
    CFraction_Value.Compact(CFraction_Value);
    return CFraction_Value;
}

/****************************************************************************************
* Name:         operator*
* Description:  Support multiply two fractions.
* Parameter:    CFraction &CFraction_
* Return:       The result of the multiply of two fractions
****************************************************************************************/
CFraction operator* (const CFraction& CFraction_1, const CFraction& CFraction_2)
{
    CFraction CFraction_Value;
	CFraction_Value.num = CFraction_1.num * CFraction_2.num;
    CFraction_Value.den = CFraction_1.den * CFraction_2.den;
    
    CFraction_Value.Compact(CFraction_Value);
    return CFraction_Value;
}

/****************************************************************************************
* Name:         operator/
* Description:  Support divide two fractions.
* Parameter:    CFraction &CFraction_
* Return:       The result of the divide of two fractions
****************************************************************************************/
CFraction operator/ (const CFraction& CFraction_1, const CFraction& CFraction_2)
{
    CFraction CFraction_Value;
	CFraction_Value.num = CFraction_1.num * CFraction_2.den;
    CFraction_Value.den = CFraction_1.den * CFraction_2.num;
    
    CFraction_Value.Compact(CFraction_Value);
    return CFraction_Value;
}

int main()
{
    CFraction CFraction_1, CFraction_2, CFraction_Value;
    cout << "Enter the fraction 1" << endl;
    CFraction_1.ImportData(CFraction_1);
    cout << "Enter the fraction 2" << endl;
    CFraction_2.ImportData(CFraction_2);
    
    cout << endl <<"Plus 2 fractions: ";
    CFraction_Value = CFraction_1 + CFraction_2;
    CFraction_Value.ExportData(CFraction_Value);
    
    cout << endl <<"Subtract 2 fractions: ";
    CFraction_Value = CFraction_1 - CFraction_2;
    CFraction_Value.ExportData(CFraction_Value);  
	  
    cout << endl <<"Multiply 2 fractions: ";
    CFraction_Value = CFraction_1 * CFraction_2;
    CFraction_Value.ExportData(CFraction_Value);
        
    cout << endl <<"Divide 2 fractions: ";
    CFraction_Value = CFraction_1 / CFraction_2;
    CFraction_Value.ExportData(CFraction_Value);
      
}
