'''Given a string s. You can perform the following operation on given string any number of time. Delete two successive elements of the string if they are same. After performing the above operation you have to return the least possible length of the string.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, a string s.
Output:
For each testcase, output in a single line answer- minimum length of string possible after performing given operations.

Constraints
1≤T≤1000
2≤lengthofstring≤105
s contains only lowercase letters.

Sample Input:
3
abccd
abbac
aaaa
Sample Output:
3
1
0
EXPLANATION:
In first case, "abd" will be final string.
in second case, "c" will be final string'''

#code
for _ in range(int(input())):
    s = list(input())
    a=[s[0]]
    for i in range(1,len(s)):
        if a and a[-1]==s[i]:
            a.pop()
        else:
            a.append(s[i])
    print(len(a))
