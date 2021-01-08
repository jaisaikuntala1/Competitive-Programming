/*

Watching CPL Problem Code: WIPL



Get excited, folks, because it is time for the final match of Codechef Premier League (CPL)!

Mike and Tracy also want to watch the grand finale, but unfortunately, they could not get tickets to the match. However, Mike is not someone who gives up so easily — he has a plan to watch the match.

The field where the match is played is surrounded by a wall with height K. Outside, there are N boxes (numbered 1 through N). For each valid i, the i-th box has a height Hi.

Mike wants to take some boxes and stack them on top of each other to build two towers. The height of each tower is the sum of heights of all the boxes that form it. Of course, no box may be in both towers. The height of each tower should be at least K. Then Mike can climb on top of one tower and Tracy on top of the other, and they can watch the match uninterrupted!

While Mike is busy stacking the boxes, Tracy would like to know the smallest number of boxes required to build two towers such that each of them has height at least K, or at least that it is impossible to build such towers. Can you help Tracy?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers H1,H2,…,HN.
Output
For each test case, print a single line containing one integer — the smallest number of boxes required to build two towers, or −1 if it is impossible.

Constraints
1≤T≤5
1≤N,K≤4,000
1≤Hi≤105 for each valid i
Subtasks
Subtask #1 (30 points):

1≤N,K≤100
1≤Hi≤100 for each valid i
Subtask #2 (70 points): original constraints

Example Input
2
8 38
7 8 19 7 8 7 10 20
4 5
2 10 4 9
Example Output
7
2
Explanation
Example case 1: The first tower can be built with boxes 8+10+20=38 and the second tower with boxes 7+7+8+19=41. In this case, the box with height 7 is left unused.

Example case 2: We only need the box with height 10 for one tower and the box with height 9 for the other tower.

*/


#include <bits/stdc++.h>
using namespace std;
int calculate(int h[],int n,int k){
    int dp[n+1][16000];
    memset(dp,0,sizeof dp);
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    int sum_till_now = 0;
    for(int i=1;i<=n;i++){
        sum_till_now += h[i-1];
        for(int j=h[i-1];j<=sum_till_now;j++){
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-h[i-1]]==1){
                dp[i][j] = 1;
            }
        }
        if(sum_till_now>=(2*k)){
            for(int j=k;j<=(sum_till_now-k);j++){
                if(dp[i][j]==1){
                    return i;
                }
            }
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int h[n];
        int total_sum = 0;
        for(int i=0;i<n;i++){
            cin>>h[i];
            total_sum += h[i];
        }
        if(total_sum<(2*k)){
            cout<<-1<<endl;
            continue;
        }
        sort(h,h+n,greater<int>());
        if(n<=100 && k<=100){
            cout<<calculate(h,n,k)<<endl;
            continue;
        }
        if(h[0]>=k && h[1]>=k){
            cout<<2<<endl;
            continue;
        }
        else if(h[0]>=k && h[1]<k){
            int cal = 0;
            int flag = 0;
            for(int i=1;i<n;i++){
                cal += h[i];
                if(cal>=k){
                    int ans = i+1;
                    cout<<ans<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                int y = -1;
                cout<<y<<endl;
                continue;
            }
        }
        else{
            cout<<calculate(h,n,k)<<endl;
            continue;
        }
        
        
        

    }
}

