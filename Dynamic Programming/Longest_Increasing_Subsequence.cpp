/*

Longest Increasing Subsequence 

Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 10000

*/


#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[])
{
   // your code here
   int arr[n+1];
   arr[0] = INT_MIN;
   for(int i=1;i<=n;i++){
       arr[i] = INT_MAX;
   }
   
   int ans = INT_MIN;
   for(int i=0;i<n;i++){
       int idx = lower_bound(arr,arr+n+1,a[i]) - arr;
       arr[idx] = a[i];
       ans = max(ans,idx);
   }
   
   return ans;
   
   
   
}
