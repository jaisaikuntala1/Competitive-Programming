/*


Matching  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There are 
N
 men and 
N
 women, both numbered 
1
,
2
,
…
,
N
.

For each 
i
,
j
 (
1
≤
i
,
j
≤
N
), the compatibility of Man 
i
 and Woman 
j
 is given as an integer 
a
i
,
j
. If 
a
i
,
j
=
1
, Man 
i
 and Woman 
j
 are compatible; if 
a
i
,
j
=
0
, they are not.

Taro is trying to make 
N
 pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make 
N
 pairs, modulo 
10
9
+
7
.

Constraints
All values in input are integers.
1
≤
N
≤
21
a
i
,
j
 is 
0
 or 
1
.
Input
Input is given from Standard Input in the following format:

N

a
1
,
1
 
…
 
a
1
,
N

:

a
N
,
1
 
…
 
a
N
,
N

Output
Print the number of ways in which Taro can make 
N
 pairs, modulo 
10
9
+
7
.

Sample Input 1 
Copy
3
0 1 1
1 0 1
1 1 1
Sample Output 1 
Copy
3
There are three ways to make pairs, as follows (
(
i
,
j
)
 denotes a pair of Man 
i
 and Woman 
j
):

(
1
,
2
)
,
(
2
,
1
)
,
(
3
,
3
)
(
1
,
2
)
,
(
2
,
3
)
,
(
3
,
1
)
(
1
,
3
)
,
(
2
,
1
)
,
(
3
,
2
)
Sample Input 2 
Copy
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
Sample Output 2 
Copy
1
There is one way to make pairs, as follows:

(
1
,
2
)
,
(
2
,
4
)
,
(
3
,
1
)
,
(
4
,
3
)
Sample Input 3 
Copy
1
0
Sample Output 3 
Copy
0
Sample Input 4 
Copy
21
0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1
1 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 0
0 0 1 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 1 1
0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0
1 1 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 0 0 1
0 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0
0 0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1
0 0 1 0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 1 1 1
0 0 0 0 1 1 0 0 1 1 1 0 0 0 0 1 1 0 0 0 1
0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0
0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 0 1
0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 1
1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1
0 0 0 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1
1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 1 0 1 1 0
0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 0 0 1
0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 1
0 0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 0 0 1 1 0
1 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 0
1 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0
Sample Output 4 
Copy
102515160
Be sure to print the number modulo 
10
9
+
7
.

*/