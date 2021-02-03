/*

Find whether path exist 
Medium Accuracy: 39.42% Submissions: 4721 Points: 4
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value true if there is a path otherwise returns false.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 

Constraints:
1 ≤ n ≤ 500

*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool visited[502][502];

int find_out(vector<vector<int>>& grid, int m, int n, int x, int y, bool visited[][502]){
    if(visited[x][y]){
        return 0;
    }
    visited[x][y] = true;
    if(grid[x][y]==2){
        return 1;
    }
    if(grid[x][y]==0){
        return 0;
    }
    int op1,op2,op3,op4;
    op1 = op2 = op3 = op4 = 0;
    if(x-1>=0){
        op1 = find_out(grid,m,n,x-1,y,visited);
    }
    if(y-1>=0){
        op2 = find_out(grid,m,n,x,y-1,visited);
    }
    if(x+1<n){
        op3 = find_out(grid,m,n,x+1,y,visited);
    }
    if(y+1<m){
        op4 = find_out(grid,m,n,x,y+1,visited);
    }
    return op1|op2|op3|op4;
    
}


class Solution {
public:
    bool is_Possible(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int x,y;
        int set = 0;
        for(int i = 0;i<m;i++){
            if(set == 1){
                break;
            }
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                    set = 1;
                    break;
                }
            }
        }
    
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                visited[i][j] = false;
            }
        }
        int ans = find_out(grid,m,n,x,y,visited);
        if(ans == 1){
            return true;
        }
        return false;
        
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends