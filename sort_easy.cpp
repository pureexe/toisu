#include<stdio.h>
#include<limits.h>
void sort(int *arr,int n)
{
    int i,j,tmp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[j]>arr[i])
            {
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

void bubble_sort(int *arr,int n)
{
    int i,j,tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}
void selection_sort(int *arr,int n){
     int i,j,tmp,_min,_min_ptr;
    for(i=0; i<n-1; i++)
    {
        _min=INT_MAX;
        for(j=i; j<n; j++)
        {
            if(_min>=arr[j])
            {
                _min=arr[i];
                _min_ptr=j;
            }
        }
        tmp=arr[i];
        arr[i]=arr[_min_ptr];
        arr[_min_ptr]=tmp;
    }
}
void print_r(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int main()
{
    int i,j,a[]= {5,1,2,4,3,9,7,8,0,6};
    selection_sort(a,10);
    print_r(a,10);
}
