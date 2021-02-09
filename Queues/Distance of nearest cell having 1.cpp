/*

Distance of nearest cell having 1 
Medium Accuracy: 30.06% Submissions: 4947 Points: 4
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 ≤ n, m ≤ 500

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





class Solution {
public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    queue<pair<int,int>> q;
	    int r = grid.size();
	    int c = grid[0].size();
	    
	    bool visited[r][c];
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            visited[i][j] = false;
	        }
	    }
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                visited[i][j] = true;
	            }
	        }
	    }
	    vector<vector<int>> cost(r,vector<int> (c,INT_MAX));
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                cost[i][j] = 0;
	            }
	        }
	    }
	    while(!q.empty()){
	        pair<int,int> p = q.front();
	        int i = p.first;
	        int j = p.second;
	        if(i-1>=0){
	            if(grid[i-1][j]!=1){
	                cost[i-1][j] = min(cost[i-1][j],1+cost[i][j]);
	                if(!visited[i-1][j]){
	                    q.push({i-1,j});
	                    visited[i-1][j] = true;
	                }
	            }
	            
	        }
	        if(i+1<r){
	            if(grid[i+1][j]!=1){
	                cost[i+1][j] = min(cost[i+1][j],1+cost[i][j]);
	                if(!visited[i+1][j]){
	                    q.push({i+1,j});
	                    visited[i+1][j] = true;
	                }
	            }
	        }
	        if(j-1>=0){
	            if(grid[i][j-1]!=1){
	                cost[i][j-1] = min(cost[i][j-1],1+cost[i][j]);
	                if(!visited[i][j-1]){
	                    q.push({i,j-1});
	                    visited[i][j-1] = true;
	                }
	            }
	        }
	        if(j+1<c){
	            if(grid[i][j+1]!=1){
	                cost[i][j+1] = min(cost[i][j+1],1+cost[i][j]);
	                if(!visited[i][j+1]){
	                    q.push({i,j+1});
	                    visited[i][j+1] = true;
	                }
	            }
	        }
	        
	      q.pop();  
	    }
	 return cost;   
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends