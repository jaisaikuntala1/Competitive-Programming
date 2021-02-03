/*

Grid 1  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There is a grid with 
H
 horizontal rows and 
W
 vertical columns. Let 
(
i
,
j
)
 denote the square at the 
i
-th row from the top and the 
j
-th column from the left.

For each 
i
 and 
j
 (
1
≤
i
≤
H
, 
1
≤
j
≤
W
), Square 
(
i
,
j
)
 is described by a character 
a
i
,
j
. If 
a
i
,
j
 is ., Square 
(
i
,
j
)
 is an empty square; if 
a
i
,
j
 is #, Square 
(
i
,
j
)
 is a wall square. It is guaranteed that Squares 
(
1
,
1
)
 and 
(
H
,
W
)
 are empty squares.

Taro will start from Square 
(
1
,
1
)
 and reach 
(
H
,
W
)
 by repeatedly moving right or down to an adjacent empty square.

Find the number of Taro's paths from Square 
(
1
,
1
)
 to 
(
H
,
W
)
. As the answer can be extremely large, find the count modulo 
10
9
+
7
.

Constraints
H
 and 
W
 are integers.
2
≤
H
,
W
≤
1000
a
i
,
j
 is . or #.
Squares 
(
1
,
1
)
 and 
(
H
,
W
)
 are empty squares.
Input
Input is given from Standard Input in the following format:

H
 
W

a
1
,
1
…
a
1
,
W

:

a
H
,
1
…
a
H
,
W

Output
Print the number of Taro's paths from Square 
(
1
,
1
)
 to 
(
H
,
W
)
, modulo 
10
9
+
7
.

Sample Input 1 

3 4
...#
.#..
....
Sample Output 1 

3
There are three paths as follows:



Sample Input 2 

5 2
..
#.
..
.#
..
Sample Output 2 

0
There may be no paths.

Sample Input 3 

5 5
..#..
.....
#...#
.....
..#..
Sample Output 3 

24
Sample Input 4 

20 20
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
Sample Output 4 

345263555
Be sure to print the count modulo 
10
9
+
7


*/


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
int32_t main() {
    int m,n;
    cin>>m>>n;
    char a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int dp[m][n];
    memset(dp,0,sizeof dp);
    int i = 0;
    for(i = 0;i<m;i++){
        if(a[i][0]=='#'){
            break;
        }
        dp[i][0] = 1;
    }
    for(int j = i;j<m;j++){
        dp[j][0] = 0;
    }
    i=0;
    for(i=0;i<n;i++){
        if(a[0][i]=='#'){
            break;
        }
        dp[0][i] = 1;
    }
    for(int j=i;j<n;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(a[i][j]=='#') {continue;}
            else{
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[m-1][n-1];
}
