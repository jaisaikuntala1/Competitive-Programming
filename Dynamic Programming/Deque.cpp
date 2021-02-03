/*

Deque  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence 
a
=
(
a
1
,
a
2
,
…
,
a
N
)
. Until 
a
 becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of 
a
. The player earns 
x
 points, where 
x
 is the removed element.
Let 
X
 and 
Y
 be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize 
X
−
Y
, while Jiro tries to minimize 
X
−
Y
.

Assuming that the two players play optimally, find the resulting value of 
X
−
Y
.

Constraints
All values in input are integers.
1
≤
N
≤
3000
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
Print the resulting value of 
X
−
Y
, assuming that the two players play optimally.

Sample Input 1 
Copy
4
10 80 90 30
Sample Output 1 
Copy
10
The game proceeds as follows when the two players play optimally (the element being removed is written bold):

Taro: (10, 80, 90, 30) → (10, 80, 90)
Jiro: (10, 80, 90) → (10, 80)
Taro: (10, 80) → (10)
Jiro: (10) → ()
Here, 
X
=
30
+
80
=
110
 and 
Y
=
90
+
10
=
100
.

Sample Input 2 
Copy
3
10 100 10
Sample Output 2 
Copy
-80
The game proceeds, for example, as follows when the two players play optimally:

Taro: (10, 100, 10) → (100, 10)
Jiro: (100, 10) → (10)
Taro: (10) → ()
Here, 
X
=
10
+
10
=
20
 and 
Y
=
100
.

Sample Input 3 
Copy
1
10
Sample Output 3 
Copy
10
Sample Input 4 
Copy
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
Sample Output 4 
Copy
4999999995
The answer may not fit into a 32-bit integer type.

Sample Input 5 
Copy
6
4 2 9 7 1 5
Sample Output 5 
Copy
2
The game proceeds, for example, as follows when the two players play optimally:

Taro: (4, 2, 9, 7, 1, 5) → (4, 2, 9, 7, 1)
Jiro: (4, 2, 9, 7, 1) → (2, 9, 7, 1)
Taro: (2, 9, 7, 1) → (2, 9, 7)
Jiro: (2, 9, 7) → (2, 9)
Taro: (2, 9) → (2)
Jiro: (2) → ()
Here, 
X
=
5
+
1
+
9
=
15
 and 
Y
=
4
+
7
+
2
=
13
.

*/
