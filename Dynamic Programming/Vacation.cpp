/*

Vacation  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of 
N
 days. For each 
i
 (
1
≤
i
≤
N
), Taro will choose one of the following activities and do it on the 
i
-th day:

A: Swim in the sea. Gain 
a
i
 points of happiness.
B: Catch bugs in the mountains. Gain 
b
i
 points of happiness.
C: Do homework at home. Gain 
c
i
 points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1
≤
N
≤
10
5
1
≤
a
i
,
b
i
,
c
i
≤
10
4
Input
Input is given from Standard Input in the following format:

N

a
1
 
b
1
 
c
1

a
2
 
b
2
 
c
2

:

a
N
 
b
N
 
c
N

Output
Print the maximum possible total points of happiness that Taro gains.

Sample Input 1 
Copy
3
10 40 70
20 50 80
30 60 90
Sample Output 1 
Copy
210
If Taro does activities in the order C, B, C, he will gain 
70
+
50
+
90
=
210
 points of happiness.

Sample Input 2 
Copy
1
100 10 1
Sample Output 2 
Copy
100
Sample Input 3 
Copy
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
Sample Output 3 
Copy
46
Taro should do activities in the order C, A, B, A, C, B, A.

*/

#include <bits/stdc++.h>
using namespace std;
int max_score(int n,int a[],int b[],int c[],int constraint,int idx,int dp[][4]){
    if(idx==n){
        return 0;
    }
    if(dp[idx][constraint]!=-1){
        return dp[idx][constraint];
    }
   
    int op1,op2,op3;
    op1 = op2 = op3 = 0;
    if(constraint!=1){
        op1 = a[idx]+max_score(n,a,b,c,1,idx+1,dp);
    }
    if(constraint!=2){
        op2 = b[idx]+max_score(n,a,b,c,2,idx+1,dp);
    }
    if(constraint!=3){
        op3 = c[idx]+max_score(n,a,b,c,3,idx+1,dp);
    }
    return dp[idx][constraint] = max(op1,max(op2,op3));
}
int main() {
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int dp[n+1][4];
    memset(dp,-1,sizeof dp);
    
    cout<<max_score(n,a,b,c,0,0,dp);
}

