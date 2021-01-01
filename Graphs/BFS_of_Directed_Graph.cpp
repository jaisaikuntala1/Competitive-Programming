/*
BFS of graph 

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Please note one can move from node i to node j only if there's an edge from i to j.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
You don't need to read input or print anything. Your task is to complete the function bfs() takes the Graph and the number of vertices as its input and returns a list containing the BFS traversal of the graph starting from the 0th vertex.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2

Explanation:
Testcase 1: 
0 is connected to 1 , 2 , 3
2 is connected to 4
so starting from 0 , bfs will be 0 1 2 3 4.
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    queue<int> q;
    int visited[N+1]={0};
    vector<int> ans;
    q.push(0);
    while(!q.empty()){
        if(g[q.front()].size()!=0){
            for(int i=0;i<g[q.front()].size();i++){
                if(visited[g[q.front()][i]]==0){
                    q.push(g[q.front()][i]);
                    visited[g[q.front()][i]] = 1;
                }
            }
        }
            ans.push_back(q.front());
            q.pop();
        
    }
    return ans;
}