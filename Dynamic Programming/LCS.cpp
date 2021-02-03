/*


LCS  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
You are given strings 
s
 and 
t
. Find one longest string that is a subsequence of both 
s
 and 
t
.

Notes
A subsequence of a string 
x
 is the string obtained by removing zero or more characters from 
x
 and concatenating the remaining characters without changing the order.

Constraints
s
 and 
t
 are strings consisting of lowercase English letters.
1
≤
|
s
|
,
|
t
|
≤
3000
Input
Input is given from Standard Input in the following format:

s

t

Output
Print one longest string that is a subsequence of both 
s
 and 
t
. If there are multiple such strings, any of them will be accepted.

Sample Input 1 
Copy
axyb
abyxb
Sample Output 1 
Copy
axb
The answer is axb or ayb; either will be accepted.

Sample Input 2 
Copy
aa
xayaz
Sample Output 2 
Copy
aa
Sample Input 3 
Copy
a
z
Sample Output 3 
Copy
The answer is (an empty string).

Sample Input 4 
Copy
abracadabra
avadakedavra
Sample Output 4 
Copy
aaadara


*/

