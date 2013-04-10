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
#include<cstdlib>
#include<sstream>
using namespace std;

class Moe
{
public:
    Moe(){
        myconsole=GetConsoleWindow();
        myhdc=GetDC(myconsole);
    };
    ~Moe(){
        ReleaseDC(myconsole,myhdc);
    };
    string intstr(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    void textbackground(int r,int g,int b){
        SetBkColor(myhdc,RGB(r,g,b));
    }
    void textcolor(int r,int g,int b){
        SetTextColor(myhdc,RGB(r,g,b));
    }
    void text(string word,int x,int y){
        TextOut(myhdc,x,y,word.c_str(),word.length());
    }

    void picture(string location,int x,int y,int width,int high){
        HDC hdc = CreateCompatibleDC(NULL);
        HBITMAP cross = (HBITMAP)LoadImage(NULL,location.c_str(),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        SelectObject(hdc,cross);
        HWND myconsole = GetConsoleWindow();
        HDC hdc_x = GetDC(myconsole);
        BitBlt(hdc_x,x,y,width,high,hdc,0,0,SRCCOPY);
    };
    void title(string word){
        SetConsoleTitle(word.c_str());
    }
    void high(int cols,int lines){
        string word="mode con:cols=";
        word.append(intstr(cols));
        word.append(" lines=");
        word.append(intstr(lines));
        system(word.c_str());
    }

    void textalpha(bool is){
        if(is)
            SetBkMode(myhdc,TRANSPARENT);
        else
            SetBkMode(myhdc,OPAQUE);
    }
    HWND getHWND(){
        return myconsole;
    }
    HDC getHDC(){
        return myhdc;
    }
protected:
private:
    HWND myconsole;
    HDC myhdc;
};




#endif // MOE_ENGGINE_H_INCLUDED
