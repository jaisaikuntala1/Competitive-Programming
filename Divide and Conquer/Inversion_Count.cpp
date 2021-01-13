/*


INVERSION COUNT

You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.

Input Format
The first line consists of number of test cases t. Each test case consists of integer N followed by N space separated integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The number of inversions in array

Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3

*/



#include <bits/stdc++.h>
using namespace std;
#define int long long

int inv_cnt;

void merge(int *a,int l,int mid, int r){
    int i=l;
    int j=mid+1;
    int temp[r-l+1];
    int k = 0;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
            inv_cnt += (mid-i+1);
        }
    }
    while(i<=mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k] = a[j];
        j++;
        k++;
    }
    for(int i = l;i<=r;i++){
        a[i] = temp[i-l];
    }
}

void inversion_count(int a[],int l,int r){
    if(l<r){
        int mid = (l+r)>>1;
        inversion_count(a,l,mid);
        inversion_count(a,mid+1,r);
        merge(a,l,mid,r);
    }
    

}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        inv_cnt = 0;
        inversion_count(a,0,n-1);
        cout<<inv_cnt<<endl;
    }

}