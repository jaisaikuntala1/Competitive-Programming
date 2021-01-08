'''Your are given a string S containing only lowercase letter and a array of character arr. Find whether the given string only contains characters from the given character array. Print 1 if the string contains characters from the given array only else print 0.

Note: string contains characters in lower case only.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains- a string S of lowercase letter a integer n denoting length of character array arr next line contains n space separated characters.
Output:
For each testcase, Print 1 if the string contains characters from the given array only else print 0.

Constraints
1≤T≤1000
0≤n≤105
Sample Input:
 3
    abcd
    4
    a b c d
    aabbbcccdddd
    4
    a b c d
    acd
    3
    a b d
Sample Output:
    1
    1
    0
'''
#STRING AND CHARACTERS
t=int(input())
for _ in range(t):
    S=set(input().strip())
    n=int(input().strip())
    a=set(input().strip().split(" "))
    g=True
    for i in S:
        if(i not in a):
            g=False
    if(g):
        print(1)
    else:
        print(0)
