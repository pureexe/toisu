/***
MOE_ENGINE
Develope By Pakkapon Phongthawee
Require
C++98 Compiler (Or newer)
linker libgdi32.a
***/

///////////////////////////////////
#ifndef MOE_ENGGINE_H_INCLUDED
#define MOE_ENGGINE_H_INCLUDED
////////////////////////////////////
#define _WIN32_WINNT 0x0500
#include<stdio.h>
#include<windows.h>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<sstream>
using namespace std;

class Moe
{
public:
    Moe()
    {
        myconsole=GetConsoleWindow();
        myhdc=GetDC(myconsole);
        drawcolor=RGB(255,255,255);
    };
    ~Moe()
    {
        ReleaseDC(myconsole,myhdc);
    };
    string intstr(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    void textbackground(int r,int g,int b)
    {
        SetBkColor(myhdc,RGB(r,g,b));
    }
    void textcolor(int r,int g,int b)
    {
        SetTextColor(myhdc,RGB(r,g,b));
    }
    void text(string word,int x,int y)
    {
        TextOut(myhdc,x,y,word.c_str(),word.length());
    }
    void setcursor(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
    }
    void circle(int radius,int x,int y)
    {
        for(int i=-radius; i<=radius; i++)
            for(int j=-radius; j<=radius; j++)
                if(i*i+j*j <= radius*radius)
                    SetPixel(myhdc,x+i,y+j,drawcolor);
    }
    void pixel(int x,int y)
    {
        SetPixel(myhdc,x,y,drawcolor);
    }
    void picture(string location,int x,int y,int width,int high)
    {
        HDC hdc = CreateCompatibleDC(NULL);
        HBITMAP cross = (HBITMAP)LoadImage(NULL,location.c_str(),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        SelectObject(hdc,cross);
        HWND myconsole = GetConsoleWindow();
        HDC hdc_x = GetDC(myconsole);
        BitBlt(hdc_x,x,y,width,high,hdc,0,0,SRCCOPY);
    };
    void title(string word)
    {
        SetConsoleTitle(word.c_str());
    }
    void high(int cols,int lines)
    {
        string word="mode con:cols=";
        word.append(intstr(cols));
        word.append(" lines=");
        word.append(intstr(lines));
        system(word.c_str());
    }
    POINT mouse()
    {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(myconsole,&p);
        return p;
    }
    POINT mousevector()
    {
        DWORD cNumRead;
        INPUT_RECORD irInBuf[128];
        SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),ENABLE_MOUSE_INPUT);
        DWORD EventCount;
        GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE),&EventCount);
        POINT a;
        int x,y;
        while(EventCount>0)
        {
            ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),irInBuf,128,&cNumRead);
            for(unsigned int i=0; i<cNumRead; i++)
            {
                y=irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
                x=irInBuf[i].Event.MouseEvent.dwMousePosition.X;
                if(irInBuf[i].Event.MouseEvent.dwEventFlags==DOUBLE_CLICK)
                {
                }
            }
            if(cNumRead==0)
                GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE),&EventCount);
        }
        a.x=x;
        a.y=y;
        return a;
    }
    void textalpha(bool is)
    {
        if(is)
            SetBkMode(myhdc,TRANSPARENT);
        else
            SetBkMode(myhdc,OPAQUE);
    }
    void color(int r,int g,int b)
    {
        drawcolor=RGB(r,g,b);
    }
    void cls()
    {
        COORD coordScreen = { 0, 0 };
        DWORD cCharsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD dwConSize;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hConsole, TEXT(' '),
                                   dwConSize,
                                   coordScreen,
                                   &cCharsWritten);
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        FillConsoleOutputAttribute(hConsole,
                                   csbi.wAttributes,
                                   dwConSize,
                                   coordScreen,
                                   &cCharsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
    }

    HWND getHWND()
    {
        return myconsole;
    }
    HDC getHDC()
    {
        return myhdc;
    }
    COLORREF getcolor()
    {
        return drawcolor;
    }
protected:
private:
    COLORREF drawcolor;
    HWND myconsole;
    HDC myhdc;
};




#endif // MOE_ENGGINE_H_INCLUDED
