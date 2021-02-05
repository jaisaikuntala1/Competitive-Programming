

/*

Slimes  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There are 
N
 slimes lining up in a row. Initially, the 
i
-th slime from the left has a size of 
a
i
.

Taro is trying to combine all the slimes into a larger slime. He will perform the following operation repeatedly until there is only one slime:

Choose two adjacent slimes, and combine them into a new slime. The new slime has a size of 
x
+
y
, where 
x
 and 
y
 are the sizes of the slimes before combining them. Here, a cost of 
x
+
y
 is incurred. The positional relationship of the slimes does not change while combining slimes.
Find the minimum possible total cost incurred.

Constraints
All values in input are integers.
2
≤
N
≤
400
1
≤
a
i
≤
10
9
Input
Input is given from Standard Input in the following format:

N

a
1
 
a
2
 
…
 
a
N

Output
Print the minimum possible total cost incurred.

Sample Input 1 
Copy
4
10 20 30 40
Sample Output 1 
Copy
190
Taro should do as follows (slimes being combined are shown in bold):

(10, 20, 30, 40) → (30, 30, 40)
(30, 30, 40) → (60, 40)
(60, 40) → (100)
Sample Input 2 
Copy
5
10 10 10 10 10
Sample Output 2 
Copy
120
Taro should do, for example, as follows:

(10, 10, 10, 10, 10) → (20, 10, 10, 10)
(20, 10, 10, 10) → (20, 20, 10)
(20, 20, 10) → (20, 30)
(20, 30) → (50)
Sample Input 3 
Copy
3
1000000000 1000000000 1000000000
Sample Output 3 
Copy
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 4 
Copy
6
7 6 8 6 1 1
Sample Output 4 
Copy
68
Taro should do, for example, as follows:

(7, 6, 8, 6, 1, 1) → (7, 6, 8, 6, 2)
(7, 6, 8, 6, 2) → (7, 6, 8, 8)
(7, 6, 8, 8) → (13, 8, 8)
(13, 8, 8) → (13, 16)
(13, 16) → (29)

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;
    cin>>n;
    int a[n+1];
    int csum[n+1];
    a[0] = csum[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        csum[i] = csum[i-1]+a[i];
    }
    int dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    for(int col=2;col<=n;col++){
        int row = 1;
        int temp = col;
        while(row<=n && temp<=n){
            dp[row][temp] = 99999999999999;
            for(int k=row;k<temp;k++){
                dp[row][temp] = min(dp[row][temp],dp[row][k]+dp[k+1][temp]+csum[temp]-csum[row-1]);
            }
            row++;
            temp++;
        }
    }
    cout<<dp[1][n];
}
