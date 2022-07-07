#pragma once
#include <Windows.h>
#include <iostream>
#include <unistd.h>
using namespace std;

/**********************************************************************
 * Class: CShape
/*********************************************************************/
class CShape
{
    public:
        int color;
        virtual void draw(int x, int y) = 0;
};

/**********************************************************************
 * Class: CLine
 * Description: Draw line
/*********************************************************************/
class CLine : public CShape 
{
    private:
        int length;
    public:
        CLine(int length, int color);
        void draw(int x, int y);
};

/**********************************************************************
 * Class: CLine
 * Description: Draw circle
/*********************************************************************/
class CCircle : public CShape
{
    private:
        int radium;
    public:
        CCircle(int radium, int color);
        void draw(int x, int y);
};

/**********************************************************************
 * Class: CLine
 * Description: Draw rectangle
/*********************************************************************/
class CRectangle : public CShape
{
    public:
        int width;
        int height;
        CRectangle(int width, int height, int color);
        CRectangle() {};
        void draw(int x, int y);
};

/**********************************************************************
 * Class: CLine
 * Description: Draw square
/*********************************************************************/
class CSquare : public CRectangle
{
    public:
        CSquare(int size, int color);
};

class CPicture 
{
    public:
        CShape *P_arr[4];
};