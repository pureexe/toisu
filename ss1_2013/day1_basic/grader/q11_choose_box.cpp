#include<stdio.h>
int overmode(int a,int b,int c,int ocr)
{
    int u=0;
    if(a>50)
        u++;
    if(b>40)
        u++;
    if(c>20)
        u++;
    if(ocr<0)
        return ocr;
    return ocr*-1;
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a<=15&&b<=10&&c<=8)
        printf("1\n%d",(10*15*8)-(a*b*c));
    else if(a<=25&&b<=15&&c<=12)
        printf("2\n%d",(25*15*12)-(a*b*c));
    else if(a<=50&&b<=40&&c<=20)
        printf("3\n%d",(40*50*20)-(a*b*c));
    else
        {
            printf("Oversize product\n");
            printf("%d",(overmode(a,b,c,(a*b*c)-(40*50*20))));
        }
    return 0;
}
