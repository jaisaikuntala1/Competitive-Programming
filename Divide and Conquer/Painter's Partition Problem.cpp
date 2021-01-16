/*

PAINTER'S PARTITION PROBLEM :

Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10
1 <= N <= 10
1<= Length of each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check_if(int boards[], int k,int n,int max_time){
    int num_painters = 1;
    int tt = 0;
    for(int i=0;i<n;i++){
        if(tt+boards[i]>max_time){
            num_painters++;
            tt = boards[i];
            if(num_painters > k) return false;
        }
        else{
            tt += boards[i];
        }
    }
    return true;
}
int32_t main(){
    int k,n;
    cin>>k>>n;
    int boards[n];
    int min_time = INT_MIN;
	int csum = 0;
    for(int i=0;i<n;i++) {
        cin>>boards[i];
        min_time = max(min_time,boards[i]);
		csum += boards[i];
        }
    int s = min_time;
    int e = csum;
    int ans = 0;
    while(s<=e){
        int mid = (s+e)>>1;
        if(check_if(boards,k,n,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    cout<<ans;
 

}