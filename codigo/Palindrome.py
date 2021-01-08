'''You are given a string S containing only lowercase characters. You can rearrange the string and you have to print minimum number of characters needed(can be 0) to make it palindrome.

Input:
First line contain an interger T denoting number of testcases.
First line of each testcase contains integer N, size of string.
Second line of each testcase contains string S.
Output:
For each test case, print a single line containing one integer ― the minimum number of characters needed(can be 0) to make it palindrome.

Constraints
1≤T≤1000
1≤N≤105
Sample Input:
3
1
a
9
abbbcbddd
6
abcdef
Sample Output:
 0
 2
 5
EXPLANATION:
Example case 1: a is already a palindrome.
Example case 2: abbddcddbba is palindrome by adding 2 more characters.
Example case 3: abdefcfedba is palindrome by adding 5 more characters.'''
#code
from collections import Counter
for _ in range(int(input())):
    lens = int(input())
    inps = input().strip()
    need = 0
    cinps = Counter(inps)
    hasOne = False
    for i in cinps:
        if cinps[i]%2 == 1:
            if hasOne == False:
                hasOne = True
                continue
            else:
                need += 1
    print(need)




