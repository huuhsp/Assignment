#include <iostream>

using namespace std;

/************************************************************************
* Name:         importData
* Description:  Import data matrix
* Parameter:
    pArr: Pointer to memory allocated in importData() function
    szRow: Row of matrix
    szCol: Column of matrix
* Return:
    true: success
    false: fail
************************************************************************/
bool importData(int*** pArr, int szRow, int szCol){
    pArr[0] = new int*[szRow];
    for(int i=0;i<szRow;i++)
        pArr[0][i] = new int[szCol];

	for(int i=0;i<szRow;i++)
    for (int j=0;j<szCol;j++)
    {
        cin >> pArr[0][i][j];
    }
    return true;
}

/***********************************************************************
* Name:         add2Matrix
* Description:  Add two matrices
* Parameter:    
    pArr1, pArr2: Pointer to memory allocated in importData() function.
    szRow: Row of matrix.
    szCol: Column of matrix.
* Return value: int**, return value add two matrices
************************************************************************/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
    int** pResult;
    pResult = new int*[szRow];
    for(int i=0;i<szRow;i++)
        pResult[i] = new int[szCol];

    for (int i=0; i<szRow; i++)
    {
       for (int j=0; j<szCol; j++) {
           pResult[i][j] = pArr1[i][j] + pArr2[i][j];
       }
    }
    return pResult;
}

/***********************************************************************
* Name:         printMatrix
* Description:  display the matrix to the screen
* Parameter:    
    pArr: Pointer to memory allocated in importData() function.
    szRow: Row of matrix.
    szCol: Column of matrix.
* Return value: void
************************************************************************/
void printMatrix(int** pArr, int szRow, int szCol)
{
    for (int i=0; i<szRow; i++)
    {
        for (int j=0; j<szCol; j++)
        {
                cout << pArr[i][j] <<" ";
        }
        cout << endl;
    }
}

/***********************************************************************
* Name:         freeMem
* Description:  free memory the area of memory pointed to by the pointer pArr
* Parameter:    
    pArr: Pointer to memory allocated in importData() function.
    szRow: Row of matrix.
    szCol: Column of matrix.
* Return value: void
************************************************************************/
void freeMem(int** pArr, int szRow, int szCol)
{
    for(int i=0;i<szRow;i++)
        delete pArr[i];
    delete pArr;
}

int main()
{
	int** pArr1;
	int** pArr2;
	int** pResult;
	int szRow, szCol;
    cout << "Import the size of the matrix:" << endl;
	cin >> szRow >> szCol;

    cout << "Import the values of matrix 1:" << endl ;
    importData(&pArr1,szRow,szCol);

    cout << "Import the values of matrix 2:" << endl;
    importData(&pArr2,szRow,szCol);

    pResult = add2Matrix(pArr1,pArr2,szRow,szCol);
    cout << "The result of adding two matrices:" << endl;
    printMatrix(pResult,szRow,szCol);

    freeMem(pResult,szRow,szCol);
    freeMem(pArr1,szRow,szCol);
    freeMem(pArr2,szRow,szCol);
}
