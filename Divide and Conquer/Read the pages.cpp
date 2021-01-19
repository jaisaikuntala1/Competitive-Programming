/*

READ THE PAGES

You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.

Input Format
First line contains integers, N and M, denoting the number of books and number of students respectively. Next line contains N integers, denoting the number of pages in N books.

Constraints
1<=N<=10^5 1<=M<=N 1<=Pi<=10^9

Output Format
Print a single integer, denoting the answer.

Sample Input
4 2
10 20 30 40
Sample Output
60

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check_if(int *pages, int max_sum, int n,int students){
    int num_students = 1;
    int pages_read = 0;
    for(int i=0;i<n;i++){
        if(pages_read+pages[i]>max_sum){
            num_students++;
            pages_read = pages[i];
            if(num_students>students) return false;
        }
        else{
            pages_read += pages[i];
        }
    }
    return true;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int pages[n];
    int max_num = INT_MIN;
    int csum = 0;
    for(int i=0;i<n;i++) {
        cin>>pages[i];
        max_num = max(max_num,pages[i]);
        csum += pages[i];
        }
    sort(pages,pages+n);
    int ans = 0;
    int s = max_num;
    int e = csum;
    while(s<=e){
        int mid = (s+e)>>1;
        bool possib = check_if(pages,mid,n,m);
        if(possib){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }

    }
    cout<<ans;

    

}