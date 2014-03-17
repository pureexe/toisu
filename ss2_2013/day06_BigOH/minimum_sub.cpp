#include<iostream>
using namespace std;
int arr[100000];
int main(){
    int i,minsum=2000000000,thissum=0,n;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=0;i<n;i++){

         if(thissum+arr[i]>0)
                thissum = arr[i];
        else
            thissum+=arr[i];
            if(minsum>thissum)
                {
                    minsum=thissum;
//                    cout << arr[i];
                }
    }
    cout << minsum;

    return 0;
}
