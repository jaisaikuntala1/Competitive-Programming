/*

Knapsack 1  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There are 
N
 items, numbered 
1
,
2
,
…
,
N
. For each 
i
 (
1
≤
i
≤
N
), Item 
i
 has a weight of 
w
i
 and a value of 
v
i
.

Taro has decided to choose some of the 
N
 items and carry them home in a knapsack. The capacity of the knapsack is 
W
, which means that the sum of the weights of items taken must be at most 
W
.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1
≤
N
≤
100
1
≤
W
≤
10
5
1
≤
w
i
≤
W
1
≤
v
i
≤
10
9
Input
Input is given from Standard Input in the following format:

N
 
W

w
1
 
v
1

w
2
 
v
2

:

w
N
 
v
N

Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1 
Copy
3 8
3 30
4 50
5 60
Sample Output 1 
Copy
90
Items 
1
 and 
3
 should be taken. Then, the sum of the weights is 
3
+
5
=
8
, and the sum of the values is 
30
+
60
=
90
.

Sample Input 2 
Copy
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Sample Output 2 
Copy
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 3 
Copy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3 
Copy
17
Items 
2
,
4
 and 
5
 should be taken. Then, the sum of the weights is 
5
+
6
+
3
=
14
, and the sum of the values is 
6
+
6
+
5
=
17
.

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n,W;
    cin>>n>>W;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    int dp[n+1][W+1];
    memset(dp,0,sizeof dp);
    for(int i=wt[0];i<=W;i++){
        dp[1][i] = val[0];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=wt[i-1]){
                dp[i][j] = max(dp[i][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[n][W];

    
  
 
  
}


