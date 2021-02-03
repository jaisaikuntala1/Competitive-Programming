/*


LCS  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
You are given strings 
s
 and 
t
. Find one longest string that is a subsequence of both 
s
 and 
t
.

Notes
A subsequence of a string 
x
 is the string obtained by removing zero or more characters from 
x
 and concatenating the remaining characters without changing the order.

Constraints
s
 and 
t
 are strings consisting of lowercase English letters.
1
≤
|
s
|
,
|
t
|
≤
3000
Input
Input is given from Standard Input in the following format:

s

t

Output
Print one longest string that is a subsequence of both 
s
 and 
t
. If there are multiple such strings, any of them will be accepted.

Sample Input 1 
Copy
axyb
abyxb
Sample Output 1 
Copy
axb
The answer is axb or ayb; either will be accepted.

Sample Input 2 
Copy
aa
xayaz
Sample Output 2 
Copy
aa
Sample Input 3 
Copy
a
z
Sample Output 3 
Copy
The answer is (an empty string).

Sample Input 4 
Copy
abracadabra
avadakedavra
Sample Output 4 
Copy
aaadara


*/


#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1+1][l2+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } 
    int i=l1,j=l2;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
            continue;
        }
        if(dp[i-1][j]>dp[i][j-1]){
            i--;
            continue;
        }
        j--;
        continue;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    
}

