#include<cstdio>
#include<climits>
#include<queue>
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
        queue<int> A;
        queue<int> B;
        int i;
        for(i=0; i<mid-low+1; i++)
            A.push(arr[low+i]);
        for(i=0; i<high-mid; i++)
            B.push(arr[mid+i+1]);
        for(i=low; i<=high; i++)
        {
            if(A.size()==0)
            {
                arr[i]=B.front();
                B.pop();
            }
            else if(B.size()==0)
            {
                arr[i]=A.front();
                A.pop();
            }
            else
            {
                if(A.front()<=B.front())
                {
                    arr[i]=A.front();
                    A.pop();
                }
                else
                {
                    arr[i]=B.front();
                    B.pop();
                }

            }
        }
    }
}
int main()
{
    int arr[]= {8,3,1,4,5,2,6,7,2};
    merge_sort(arr,0,9);
    print_r(arr,9);
}
