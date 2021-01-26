/*
Unit Area of largest region of 1's 

Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally(horizontally, vertically, dioganally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500

*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int maxi;
int n,m;
int a[501][501];
int visited[501][501];

void dfs(int x,int y){
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i<0 || i>n-1 || j<0 || j>m-1){
                continue;
            }
            if(a[i][j] == 0){
                visited[i][j] = 1;
                continue;
            }
            if(visited[i][j] == 1){
                continue;
            }
            visited[i][j] = 1;
            maxi++;
            if(i!=x || j!=y){
                dfs(i,j);
            }
        }
    }
}

class Solution {
public:
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = INT_MIN;
        int N = grid.size();
        int M = grid[0].size();
        
    n = N;
    m = M;
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = grid[i][j];
        }
    }
   memset(visited,0,sizeof visited);
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(a[i][j] == 0){
               visited[i][j] = 1;
               continue;
           }
           if(visited[i][j]==1){
               continue;
           }
           maxi = 0;
           dfs(i,j);
           ans = max(ans,maxi);
           
       }
   }
return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends