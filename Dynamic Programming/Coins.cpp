/*


Coins  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
Let 
N
 be a positive odd number.

There are 
N
 coins, numbered 
1
,
2
,
…
,
N
. For each 
i
 (
1
≤
i
≤
N
), when Coin 
i
 is tossed, it comes up heads with probability 
p
i
 and tails with probability 
1
−
p
i
.

Taro has tossed all the 
N
 coins. Find the probability of having more heads than tails.

Constraints
N
 is an odd number.
1
≤
N
≤
2999
p
i
 is a real number and has two decimal places.
0
<
p
i
<
1
Input
Input is given from Standard Input in the following format:

N

p
1
 
p
2
 
…
 
p
N

Output
Print the probability of having more heads than tails. The output is considered correct when the absolute error is not greater than 
10
−
9
.

Sample Input 1 
Copy
3
0.30 0.60 0.80
Sample Output 1 
Copy
0.612
The probability of each case where we have more heads than tails is as follows:

The probability of having 
(
C
o
i
n
1
,
C
o
i
n
2
,
C
o
i
n
3
)
=
(
H
e
a
d
,
H
e
a
d
,
H
e
a
d
)
 is 
0.3
×
0.6
×
0.8
=
0.144
;
The probability of having 
(
C
o
i
n
1
,
C
o
i
n
2
,
C
o
i
n
3
)
=
(
T
a
i
l
,
H
e
a
d
,
H
e
a
d
)
 is 
0.7
×
0.6
×
0.8
=
0.336
;
The probability of having 
(
C
o
i
n
1
,
C
o
i
n
2
,
C
o
i
n
3
)
=
(
H
e
a
d
,
T
a
i
l
,
H
e
a
d
)
 is 
0.3
×
0.4
×
0.8
=
0.096
;
The probability of having 
(
C
o
i
n
1
,
C
o
i
n
2
,
C
o
i
n
3
)
=
(
H
e
a
d
,
H
e
a
d
,
T
a
i
l
)
 is 
0.3
×
0.6
×
0.2
=
0.036
.
Thus, the probability of having more heads than tails is 
0.144
+
0.336
+
0.096
+
0.036
=
0.612
.

Sample Input 2 
Copy
1
0.50
Sample Output 2 
Copy
0.5
Outputs such as 0.500, 0.500000001 and 0.499999999 are also considered correct.

Sample Input 3 
Copy
5
0.42 0.01 0.42 0.99 0.42
Sample Output 3 
Copy
0.3821815872


*/


#include <bits/stdc++.h>
using namespace std;
double dp[3001][3001];
double prob(double pro[],int heads,int tails,int idx,int n){
    if(idx==n){
        if(heads>tails){
            return 1;
        }
        return 0;
    }
    if(dp[idx][heads]>-0.5){
        return dp[idx][heads];
    }
    
    double ans = pro[idx]*prob(pro,heads+1,tails,idx+1,n);
    ans = ans+(1-pro[idx])*prob(pro,heads,tails+1,idx+1,n);
    return dp[idx][heads] = ans;

}
int main() {
    int n;
    cin>>n;
    double pro[n];
    for(int i=0;i<n;i++){
        cin>>pro[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(10)<<prob(pro,0,0,0,n);

}

