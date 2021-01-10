/*

SUPERMARKET DILEMMA Problem Code: CIN002SolvedSubmit (Practice)

 
Supermarket Dilemma Chef is going to local supermarket but there appears a problem with chef as he is confused about 
which Supermarket he can choose to go as he is not able to decide whether he can park his car in that particular 
supermarket’s parking lot or not! There are N parking slots in each supermarket which are marked from 1,2,3,4…N. 
Chef will go to that supermarket in which he gets to know that there is exactly 1 empty parking slot having number K 
that exactly divides the total number of slots (N) available in that supermarket. The 1st and Nth parking slots are 
always occupied by the staff of every supermarket. Rest parking slots are empty as Chef is arriving early morning to 
the supermarket. Now Chef needs your help in determining whether he can park his car in a supermarket or not! 
Input The first line contains the single integer N showing how many supermarkets are there for the chef to choose. 
The next N lines contain a number ‘ai’ which represents the total parking slots available in ith supermarket. 
Output You need to output "YES" (without the quotes), if a supermarket can be reached by Chef, and "NO" (without the 
quotes), if it can't. Constraints 1<=N<=10^5 1<=ai<=10^12 Sample Input : 2 4 5 Sample Output : YES NO


*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp;
void primesieve(){
    int p[1000000]={0};
    mp[4] = 1;
    for(int i=3;i<=1000000;i+=2){
        p[i] = 1;
    }
    for(int i=3;i<=1000000;i+=2){
        if(p[i]){
            mp[i*i] = 1;
            for(int j=i*i;j<=1000000;j+=2*i){
                p[j] = 0;
            }
        }
    }
}

int32_t main(){
    int n;cin>>n;
    int a;
    primesieve();
    while(n--){
        cin>>a;

        if(mp[a]){
            cout<<"YES"<<" ";
        }
        else{
            cout<<"NO"<<" ";
        }
    }
}