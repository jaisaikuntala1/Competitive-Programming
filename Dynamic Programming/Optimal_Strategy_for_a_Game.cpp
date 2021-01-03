/*
Optimal Strategy For A Game 

You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of N coins) and N as number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
2 <= N <= 100
1 <= Ai <= 106
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

long long dp[102][102];

long long maxscore(int arr[],int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(j-i==0){
        return dp[i][j] = arr[i];
    }
    if(j-i == 1){
        return dp[i][j] = max(arr[i],arr[j]);
    }
    int op1 = arr[i] + min(maxscore(arr,i+2,j),maxscore(arr,i+1,j-1));
    int op2 = arr[j] + min(maxscore(arr,i+1,j-1),maxscore(arr,i,j-2));
    
    return dp[i][j] = max(op1,op2);
    
}
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    memset(dp,-1,sizeof dp);
    return maxscore(arr,0,n-1);
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends