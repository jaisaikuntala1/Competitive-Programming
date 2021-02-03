/*
Longest Path  

Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There is a directed graph 
G
 with 
N
 vertices and 
M
 edges. The vertices are numbered 
1
,
2
,
…
,
N
, and for each 
i
 (
1
≤
i
≤
M
), the 
i
-th directed edge goes from Vertex 
x
i
 to 
y
i
. 
G
 does not contain directed cycles.

Find the length of the longest directed path in 
G
. Here, the length of a directed path is the number of edges in it.

Constraints
All values in input are integers.
2
≤
N
≤
10
5
1
≤
M
≤
10
5
1
≤
x
i
,
y
i
≤
N
All pairs 
(
x
i
,
y
i
)
 are distinct.
G
 does not contain directed cycles.
Input
Input is given from Standard Input in the following format:

N
 
M

x
1
 
y
1

x
2
 
y
2

:

x
M
 
y
M

Output
Print the length of the longest directed path in 
G
.

Sample Input 1 

4 5
1 2
1 3
3 2
2 4
3 4
Sample Output 1 

3
The red directed path in the following figure is the longest:



Sample Input 2 
Copy
6 3
2 3
4 5
5 6
Sample Output 2 

2
The red directed path in the following figure is the longest:



Sample Input 3 
Copy
5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3
Sample Output 3 

3
The red directed path in the following figure is one of the longest:




*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v[100005];
int dp[100005];

int path(int i){
    if(v[i].size()==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int max_len = 0;
    for(auto x:v[i]){
        max_len = max(max_len,1+path(x));
    }
    return dp[i] = max_len;

}
int32_t main() {
    int n,m;
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        v[a].push_back(b);

    }
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }
    int ans = INT_MIN;
    for(int i = 1;i<=n;i++){
        ans = max(ans,path(i));
    }
    cout<<ans;
}
