/*

Max rectangle 
Medium Accuracy: 47.59% Submissions: 22189 Points: 4
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. 
The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes 
the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and 
not to write the full code.

*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

int getMaxArea(int arr[], int n){
    
    // Your code here
    int ans = INT_MIN;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push({i,arr[i]});
            continue;
        }
        else{
            if(arr[i]>=st.top().second){
                st.push({i,arr[i]});
            }
            else{
                int idx;
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
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || M[i][j]==0){
                continue;
            }
            else{
                M[i][j] = M[i-1][j]+1;
            }
            
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int temp[m];
        for(int j=0;j<m;j++){
            temp[j] = M[i][j];
        }
        ans = max(ans,getMaxArea(temp,m));
    }
    return ans;
    
    
}
