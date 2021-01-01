/*

Edit Distance 
Medium Accuracy: 32.22% Submissions: 6683 Points: 4
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation required to make both strings equal. 

 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
 

Constraints:
1 <= Length of both strings <= 100
Both the strings are in lowercase.

*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    // Code here
		    
		   int dp[s.length()+1][t.length()+1];
		   for(int i=0;i<=s.length();i++){
		       for(int j=0;j<=t.length();j++){
		           if(i==0){
		               dp[i][j] = j;
		           }
		           else if(j==0){
		               dp[i][j] = i;
		           }
		           else if(s[i-1]==t[j-1]){
		               dp[i][j] = dp[i-1][j-1];
 		           }
 		           else{
 		               dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
 		           }
		       }
		   }
		   return dp[s.length()][t.length()];
		    
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends