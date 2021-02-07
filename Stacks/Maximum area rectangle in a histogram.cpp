/*

Maximum Rectangular Area in a Histogram 
Medium Accuracy: 47.42% Submissions: 10539 Points: 4
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 106
1 <= arr[i] <= 1012

*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long long getMaxArea(long long arr[], int n){
    
    // Your code here
    long long ans = INT_MIN;
    stack<pair<long long,long long>> st;
    for(long long i=0;i<n;i++){
        if(st.empty()){
            st.push({i,arr[i]});
            continue;
        }
        else{
            if(arr[i]>=st.top().second){
                st.push({i,arr[i]});
            }
            else{
                long long idx;
                while(!st.empty() && st.top().second>arr[i]){
                    idx = st.top().first;
                    ans = max(ans,(i-st.top().first)*st.top().second);
                    st.pop();
                }
                st.push({idx,arr[i]});
            }
        }
    }
    if(!st.empty()){
        while(!st.empty()){
            ans = max(ans,(n-st.top().first)*st.top().second);
            st.pop();
        }
    }
    return ans;
    
    
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
