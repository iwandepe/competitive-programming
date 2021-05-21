/**
 * Find largest minimum distance
 * with binary search
 * 
 * 20 Jan 2021
 * 
 * */

#include<bits/stdc++.h>
using namespace std;

bool isValidDistance(int arr[], int dis, int n, int c){
    int last=arr[0], count=1;
    for (int i=1; i<n; i++){
        if(arr[i]-last>=dis){
            count++, last = arr[i];
            if (count==c)
                return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int l=arr[0], r=arr[n-1]-l, mid;
        while(r-l>1){
            mid = (l+r)/2;
            if (isValidDistance(arr, mid, n, c))
                l=mid;
            else
                r=mid;
        }
        cout<<l<<endl;
    }
    return 0;
}