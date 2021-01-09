/*

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Constraints
2 <= N <= 100,000
0 <= xi <= 1,000,000,000
2 <= C <= N

Output Format
Print one integer: the largest minimum distance.

Sample Input
5 3
1 2 8 4 9
Sample Output
3

Problem Credits - (Spoj)[http://www.spoj.com/problems/AGGRCOW/]

*/


#include <iostream>
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;


bool can_place_cows(int stalls[], int min_sep, int n, int c){
    int last_cow = stalls[0];
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(stalls[i] - last_cow >= min_sep){
            cnt++;
            last_cow = stalls[i];
        }
        if(cnt == c) return true;
    }
    return false;
}
int32_t main(){
    int n,c;
    cin>>n>>c;
    int stalls[n];
    for(int i=0;i<n;i++) cin>>stalls[i];
    sort(stalls,stalls+n);
    int ans = 0;
    int s = 0;
    int e = stalls[n-1] - stalls[0];
    while(s<=e){
        int mid = (s+e)>>1;
        bool can_place = can_place_cows(stalls,mid,n,c);
        if(can_place){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid - 1;
        }

    }
    cout<<ans;

    

}