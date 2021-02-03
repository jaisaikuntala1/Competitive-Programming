/*


Total Decoding Messages 
Medium Accuracy: 16.75% Submissions: 708 Points: 4
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.
 

Example 1:

Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).
Example 2:

Input: str = "27"
Output: 1
Explanation: "27" can be decoded as "BG".
 

Your Task:
You don't need to read or print anything. Your task is to complete the function CountWays() which takes the string as str as input parameter and returns the total number of ways the string can be decoded modulo 109 + 7.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(n) where n  = |str|

Constraints:
1 <= |str| <= 104

*/



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int find_ways(string str,int n,int dp[]){
    
     if(n==0||n==1){
        return 1;
    }
   if(dp[n]!=-1){
       return dp[n];
   }
    int count = 0;
    if(str[n-1]>'0'){
        count = (count + find_ways(str,n-1,dp))%1000000007;
    }
    if(str[n-2] == '1'||str[n-2]=='2' && str[n-1]<'7'){
        count = (count + find_ways(str,n-2,dp))%1000000007;
    }
    return dp[n] = count;
    
}

class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int found = str.find("00");
           
		    if(found>=0){
		        return 0;
		    }
		    if(str[0]=='0'){
		        return 0;
		    }
            int l = str.length();
           int dp[l+1];
           for(int i=0;i<=l;i++){
               dp[i] = -1;
           }

		    return find_ways(str,l,dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends