#include<stdio.h>
int hang[12],lst[5],lst_size,fail[5],fail_size;
bool isInList(int x)
{
    int i;
    for(i=0; i<=lst_size; i++)
        if(lst[i]==x)
            return true;
    return false;
}
bool isInBase(int x)
{
    int i;
    for(i=0; i<12; i++)
        if(hang[i]==x)
            return true;
    return false;
}
int main()
{
    int i,j,chk=0;
    for(i=0; i<12; i++)
        scanf("%d",&hang[i]);
    printf("_ _ _ _ _ _ _ _ _ _ _ _\n");
    for(i=0; i<5; i++)
    {
        lst_size=i;
        scanf("%d",&lst[i]);

        for(j=0; j<12; j++)
        {
            if(isInList(hang[j]))
            {
                printf("%d ",hang[j]);
                if(i==4)
                    chk++;
            }
            else
            {
                printf("_ ");

            }
        }
        if(!isInBase(lst[i]))
        {
            fail[fail_size]=lst[i];
            fail_size++;
        }
        for(j=0; j<fail_size; j++)
            printf("%d ",fail[j]);
        printf("\n");
    }
    printf("%d",chk);
    return 0;
}
