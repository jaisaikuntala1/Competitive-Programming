/*

Stock buy and sell 
Medium Accuracy: 39.53% Submissions: 33416 Points: 4
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
(0 3) (4 6)
Explanation:
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
(3 4)
Explanation:
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.

Your Task:
The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs. If there is No Profit, return an empty list.


Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)


Constraints:
2 <= N <= 103
0 <= Ai <= 104


*/


//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

int buy(vector<int> A,int n,int start){
    if(n==1){
        return -1;
    }
    int i = start;
    while(i<n-1 && A[i]>=A[i+1]){
        i++;
    }
    if(i==n-1){
        return -1;
    }
    return i;
}

int sell(vector<int> A,int n,int start){
    if(start>n-1){
        return -1;
    }
    int i = start;
    while(i<n-1 && A[i]<=A[i+1]){
        i++;
    }
    
    return i;
}

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
       int i = buy(A,n,0);
        if(i==-1){
            vector<vector<int>> ans;
            return ans;
        }
        int j = sell(A,n,i+1);
        if(j==-1){
            vector<vector<int>> ans2;
            return ans2;
        }
        vector<int> buyy;
        vector<int> selll;
        while(i!=-1 && j!=-1){
            buyy.push_back(i);
           
            selll.push_back(j);
          
            i = buy(A,n,j+1);
            j = sell(A,n,i+1);
            
        }
    
        int l = min(buyy.size(),selll.size());
        vector<vector<int>> ans(l,vector<int> (2,0));
        for(int i=0;i<l;i++){
            ans[i][0] = buyy[i];
            ans[i][1] = selll[i];
        }
  
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            for (int i=0; i<ans.size(); ++i){
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            }
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends