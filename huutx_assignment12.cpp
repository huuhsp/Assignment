#include "huutx_assignment12.h"

template <class T> 
    Stack<T> :: Stack(int N)
    {
    	Size_max = N;
        T_Stack = new T[Size_max];
        i_Top = -1;
    } 

template <class T> 
    Stack<T> :: ~Stack()
    {
        delete [] T_Stack;
    }

/**********************************************************
 * Check the stack is empty
/*********************************************************/
template<class T>
    bool Stack<T>::isEmpty()
    {
        if (i_Top == -1)
            return true;
        return false;
    }

/**********************************************************
 * Check the stack is full
/*********************************************************/
template<class T>
    bool Stack<T>::isFull()
    {
        if (i_Top == Size_max)
            return true;
        return false;
    }

/**********************************************************
 * Remove an element from the top of the stack
/*********************************************************/
template <class T> 
    void Stack<T> :: Pop()
    {
        if(!isEmpty())
        {
        	T Value;
            Value = T_Stack[i_Top];
            i_Top--;
            cout << Value << " ";
        }
        else
			cout << "Stack is empty!";
    }

/**********************************************************
 * Push element to top of stack
/*********************************************************/
template <class T> 
    bool Stack<T> :: Push(T Value)
    {
        if(!isFull())
        {
            i_Top++;
            T_Stack[i_Top] = Value;
            return true;
        }
        else
			return false;
    }

int main()
{
    Stack<int> Stack(100);
    int i;
    for(i = 1; i<10; i++)
	{
		Stack.Push(i);
	}
    
	while(i>1)
	{
		Stack.Pop();
		i--;
	}
}
