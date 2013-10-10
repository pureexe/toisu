#include<cstdio>
#include<climits>
#define MAX_ARR 16
using namespace std;
void print_r(int *arr,int n)
{
    int i;
    printf("Array:[ ");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("]\n");
}
void merge_sort(int *arr,int low,int high)
{
    int mid=(low+high)/2;
    if(low<high)
    {

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //////////////////////////////////
        int arr1[MAX_ARR],arr2[MAX_ARR];
        int i,j,k;
        for(i=0; i<mid-low+1; i++)
            arr1[i]=arr[low+i];
        for(j=0; j<high-mid; j++)
            arr2[j]=arr[mid+j+1];
        arr1[i]=INT_MAX;
        arr2[j]=INT_MAX;
        i=0;
        j=0;
        for(k=low; k<=high; k++)
        {
            if(arr1[i]<=arr2[j])
                arr[k]=arr1[i++];
            else
                arr[k]=arr2[j++];
        }
    }
}
int main()
{
    int arr[]= {8,3,1,4,5,2,6,7};
    merge_sort(arr,0,7);
    print_r(arr,8);
}
