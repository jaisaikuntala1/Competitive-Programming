/*


Independent Set  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There is a tree with 
N
 vertices, numbered 
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
−
1
), the 
i
-th edge connects Vertex 
x
i
 and 
y
i
.

Taro has decided to paint each vertex in white or black. Here, it is not allowed to paint two adjacent vertices both in black.

Find the number of ways in which the vertices can be painted, modulo 
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
10
5
1
≤
x
i
,
y
i
≤
N
The given graph is a tree.
Input
Input is given from Standard Input in the following format:

N

x
1
 
y
1

x
2
 
y
2

:

x
N
−
1
 
y
N
−
1

Output
Print the number of ways in which the vertices can be painted, modulo 
10
9
+
7
.

Sample Input 1 

3
1 2
2 3
Sample Output 1 

5
There are five ways to paint the vertices, as follows:



Sample Input 2 

4
1 2
1 3
1 4
Sample Output 2 

9
There are nine ways to paint the vertices, as follows:



Sample Input 3 

1
Sample Output 3 

2
Sample Input 4 

10
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
Sample Output 4 

157


*/