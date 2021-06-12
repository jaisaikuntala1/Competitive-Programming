#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;


int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            //int cnt=0;
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
