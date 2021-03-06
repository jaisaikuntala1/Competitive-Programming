/*


Rotten Oranges 
Medium Accuracy: 44.8% Submissions: 5253 Points: 4
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 ≤ n, m ≤ 500

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int num_1 = 0;
        int num_2 = 0;
        int num_0 = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    num_0++;
                }
                else if(grid[i][j]==1){
                    num_1++;
                }
                else{
                    num_2++;
                    q.push({i,j});
                }
            }
        }
        if(num_1==0){
            return 0;
        }
        
        int min_time = 0;
        int num_rotten = 0;
        while(1){
            bool atleast_one_changed = false;
            min_time++;
            int s = q.size();
            while(s--){
                pair<int,int> p = q.front();
                int i = p.first;
                int j = p.second;
                if(i-1>=0){
                    if(grid[i-1][j]==1){
                        grid[i-1][j] = 2;
                        q.push({i-1,j});
                        num_rotten++;
                        atleast_one_changed = true;
                        if(num_rotten==num_1){
                            
                            return min_time;
                        }
                    }
                }
                if(j+1<n){
                    if(grid[i][j+1]==1){
                        grid[i][j+1] = 2;
                        q.push({i,j+1});
                        num_rotten++;
                        atleast_one_changed = true;
                        if(num_rotten==num_1){
                            return min_time;
                        }
                    }
                    
                }
                if(i+1<m){
                     if(grid[i+1][j]==1){
                        grid[i+1][j] = 2;
                        q.push({i+1,j});
                        num_rotten++;
                        atleast_one_changed = true;
                        if(num_rotten==num_1){
                            return min_time;
                        }
                    }
                    
                }
                if(j-1>=0){
                    if(grid[i][j-1]==1){
                        grid[i][j-1] = 2;
                        q.push({i,j-1});
                        num_rotten++;
                        atleast_one_changed = true;
                        if(num_rotten==num_1){
                            return min_time;
                        }
                    }
                    
                }
                q.pop();
                
            }
            if(atleast_one_changed==false){
                return -1;
            }
        }
        
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
