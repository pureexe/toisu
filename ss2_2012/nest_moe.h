#ifndef MOE_ENGINE_H_INCLUDED
#define MOE_ENGINE_H_INCLUDED

#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<string>
using namespace std;
class Moe
{
public:
    ////////////////////////////////////////
    class Text
    {
    public:
        void out(string word,int x,int y);
        void color(int r,int g,int b);
        void background(int r,int g,int b);
        void showbackground();
        void hidebackground();
        Text();
        ~Text();
        HWND myconsole;
        HDC myhdc;
    protected:
    private:
    };
    /////////////////////////////////////
    class Cursor
    {
    public:
        Cursor();
        ~Cursor();
    protected:
    private:
    };
    ////////////////////////////////////
    class Mouse
    {
    public:
        Mouse();
        ~Mouse();
    protected:
    private:
    };
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    Text text;
    Moe();
    ~Moe();
    void SetHWND(HWND mycon);
    void picture(string )
    HWND myconsole;
    HDC myhdc;
protected:
private:

};

/////////////////////////////////////////////////////////
/// Class Moe
////////////////////////////////////////////////////////

Moe::Moe()
{
    SetHWND(GetConsoleWindow());
};
void Moe::SetHWND(HWND mycon)
{
    myconsole=mycon;
    myhdc=GetDC(mycon);
    text.myconsole=myconsole;
    text.myhdc=myhdc;

}
void Moe::void picture(string location,int x,int y,int width,int high)
{
    HDC hdc = CreateCompatibleDC(NULL);
    HBITMAP cross = (HBITMAP)LoadImage(NULL,location.c_str(),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    SelectObject(hdc,cross);
    HWND myconsole = GetConsoleWindow();
    HDC hdc_x = GetDC(myconsole);
    BitBlt(hdc_x,x,y,width,high,hdc,0,0,SRCCOPY);
};
Moe::~Moe()
{
    ReleaseDC(myconsole,myhdc);
}

///////////////////////////////////////////
/// Class Text
///////////////////////////////////////////
Moe::Text::Text() {};
Moe::Text::~Text() {};
void Moe::Text::out(string word,int x,int y)
{
    TextOut(myhdc,x,y,word.c_str(),word.length());
}
void Moe::Text::color(int r,int g,int b)
{
    SetTextColor(myhdc,RGB(r,g,b));
}
void Moe::Text::background(int r,int g,int b)
{
    SetBkColor(myhdc,RGB(r,g,b));
}
void Moe::Text::hidebackground()
{
    SetBkMode(myhdc,TRANSPARENT);
}
void Moe::Text::showbackground()
{
    SetBkMode(myhdc,OPAQUE);
}
#endif // MOE_ENGINE_H_INCLUDED
