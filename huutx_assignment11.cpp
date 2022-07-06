#include "huutx_asignment11.h"

CLine :: CLine(int length, int color)
{
    this->length = length;
    this->color = color;
}

void CLine :: draw(int x, int y)
{
    HPEN HPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    HPen = CreatePen(PS_SOLID, 3, RGB(0, 0, color));
    SelectObject(device_context, HPen);
    MoveToEx(device_context, x, y, (LPPOINT)NULL);
    LineTo(device_context, x + length, y + 180);
}

CCircle :: CCircle(int radian, int color)
{
    this->radium = radian;
    this->color = color;
}

void CCircle :: draw(int x, int y)
{
    HPEN HPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    HPen = CreatePen(PS_SOLID, 3, RGB(0, color, color));
    SelectObject(device_context, HPen);
    Ellipse(device_context, x, y, x + 2*radium, y + 2*radium);
}

CRectangle :: CRectangle(int width, int height, int color)
{
    this->width = width;
    this->height = height;
    this->color = color;
}

void CRectangle :: draw(int x, int y)
{
    HPEN HPen;
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    HPen = CreatePen(PS_SOLID, 3, RGB(0, color, color));
    SelectObject(device_context, HPen);
    Rectangle(device_context, x, y, x+width, y+height);
}

CSquare :: CSquare(int size, int color)
{
    this->width = size;
    this->height = size;
    this->color = color;
}

void ChangeCoordinates(int &x, int &y, int position)
{
    if(position == 1)
        x += 110;
    else if(position == 2)
        x += 210;
    else if(position == 3)
        x += 160;
    else if(position == 4)
        x += 210;
}
int main()
{
    CPicture Picture;
    Picture.P_arr[0] = new CLine(100, 255);
    Picture.P_arr[1] = new CCircle(100, 255);
    Picture.P_arr[2] = new CRectangle(150, 200, 255);
    Picture.P_arr[3] = new CSquare(200, 255);

    int i_Arr[4];
    cout << "Enter order of appearance of drawings: " << endl; 
    cout << "1. Line" << endl << "2. Circle" << endl << "3. Rectangle" << endl << "4. Square" << endl;
    cout << "Order: ";
    for(int i=0;i<4;i++)
    {
        cin >> i_Arr[i];
        try
        {
            if(i_Arr[i] < 0 || i_Arr[i] > 4)
                throw(i_Arr[i]);
        }
        catch(int num)
        {
            cout << "Number must is 1, 2, 3, 4!\n" << endl;
            exit(0);
        }
    }

    int i_CoordinatesX = 0;
    int i_CoordinatesY = 0;
    cout << "Enter position coordinates: " << endl;
    cout << "x: ";
    cin >> i_CoordinatesX;
    cout << "y: ";
    cin >> i_CoordinatesY;
    
    system("CLS");
    while(1)
    {    
    for(int i=0;i<4;i++){
    Picture.P_arr[i_Arr[i]-1]->draw(i_CoordinatesX, i_CoordinatesY);
    ChangeCoordinates(i_CoordinatesX, i_CoordinatesY, i_Arr[i]);
    }
    sleep(1000);
    }
}
