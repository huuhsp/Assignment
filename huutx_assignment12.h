#include <iostream>
using namespace std;

template <class T>
    class Stack
    {
        private:
            int Size_max;
            T* T_Stack; 
            int i_Top;
        public:
            Stack(int N);
            ~Stack();

            bool isEmpty();
            bool isFull();
            void Pop();
            bool Push(T);
    };
