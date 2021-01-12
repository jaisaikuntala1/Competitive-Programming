/*

FRIENDS PAIRING PROBLEM :


Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input Format
First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

Constraints
1<= n < 30

Output Format
Output t lines each line describing the answer.

Sample Input
1
3
Sample Output
4
Explanation
{1}, {2}, {3} : all single {1}, {2,3} : 2 and 3 paired but 1 is single. {1,2}, {3} : 1 and 2 are paired but 3 is single. {1,3}, {2} : 1 and 3 are paired but 2 is single. Note that {1,2} and {2,1} are considered same.




*/

//CODE :

#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int dp[n+1];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2;i<=n;i++){
			dp[i] = dp[i-1]+(i-1)*dp[i-2];
		}
		cout<<dp[n]<<endl;
	}


	return 0;
}