/*
Subset Sum Problem 

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        int y = sum/2;
        bool dp[N+1][y+1];
        for(int i=0;i<=N;i++){
            dp[i][0] = true;
        }
        for(int j=1;j<=y;j++){
            dp[0][j] = false;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=y;j++){
            
                if(j>=arr[i-1]){
                    dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
          
                
                  
                
            }
        }
        if(dp[N][y]==true){
            return 1;
        }
        else{
            return 0;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends