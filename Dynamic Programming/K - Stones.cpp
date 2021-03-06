/*
K - Stones  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100 points

Problem Statement
There is a set 
A
=
{
a
1
,
a
2
,
…
,
a
N
}
 consisting of 
N
 positive integers. Taro and Jiro will play the following game against each other.

Initially, we have a pile consisting of 
K
 stones. The two players perform the following operation alternately, starting from Taro:

Choose an element 
x
 in 
A
, and remove exactly 
x
 stones from the pile.
A player loses when he becomes unable to play. Assuming that both players play optimally, determine the winner.

Constraints
All values in input are integers.
1
≤
N
≤
100
1
≤
K
≤
10
5
1
≤
a
1
<
a
2
<
⋯
<
a
N
≤
K
Input
Input is given from Standard Input in the following format:

N
 
K

a
1
 
a
2
 
…
 
a
N

Output
If Taro will win, print First; if Jiro will win, print Second.

Sample Input 1 

2 4
2 3
Sample Output 1 

First
If Taro removes three stones, Jiro cannot make a move. Thus, Taro wins.

Sample Input 2 

2 5
2 3
Sample Output 2 

Second
Whatever Taro does in his operation, Jiro wins, as follows:

If Taro removes two stones, Jiro can remove three stones to make Taro unable to make a move.
If Taro removes three stones, Jiro can remove two stones to make Taro unable to make a move.
Sample Input 3 

2 7
2 3
Sample Output 3 

First
Taro should remove two stones. Then, whatever Jiro does in his operation, Taro wins, as follows:

If Jiro removes two stones, Taro can remove three stones to make Jiro unable to make a move.
If Jiro removes three stones, Taro can remove two stones to make Jiro unable to make a move.
Sample Input 4 

3 20
1 2 3
Sample Output 4 

Second
Sample Input 5 

3 21
1 2 3
Sample Output 5 

First
Sample Input 6 

1 100000
1
Sample Output 6 

Second

*/


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) {cin>>a[i];}
    int dp[k+1]={0};
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(a[j-1]<=i){
                if(dp[i-a[j-1]] == 0){
                    dp[i] = 1;
                }
            }
        }
    }
    if(dp[k]==1){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
}
