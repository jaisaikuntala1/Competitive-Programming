/*

nCr 

Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..


Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)


Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800

*/


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define mod 1000000007
// User function Template for C++

long long int fact(long long int n){
    long long int vec[n+1];
    vec[0] = 1;
    for(int i=1;i<=n;i++){
        vec[i] = i*vec[i-1];
        vec[i]%=mod;
    }
    return vec[n];
}

long long int power(long long int x,long long int y){
    if(y==0){
        return 1;
    }
    long long int ans;
    if(y%2==0){
        ans = power(x,y/2);
        ans = (ans*ans)%mod;
        return ans;
    }
    else{
        return (x*power(x,y-1))%mod;
    }
    
}
long long int mod_inv(long long int n){
    return power(n,mod-2);
}

long long int fact_inv(long long int n){
    long long int vec[n+1];
    vec[0] = 1;
    for(long long int i=1;i<=n;i++){
        vec[i] = (mod_inv(i)*vec[i-1])%mod;
    }
    return vec[n];
}

int solve(long long int n,long long int r){
    long long int ans = 1;
    ans = (ans*fact(n))%mod;
    ans = (ans*fact_inv(r))%mod;
    ans = (ans*fact_inv(n-r))%mod;
    return ans;
}

class Solution{
public:
    long long int nCr(long long int n, long long int r){
        // code here
        if(r>n){
            return 0;
        }
        return solve(n,r);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends