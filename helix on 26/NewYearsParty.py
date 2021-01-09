'''To celebrate the new year, a group of friends thought of buying n liters of cola.

However, cola is available in bottles 0.5, 1, and 2 liters in volume. In the shop, there are exactly 0.5-liters bottles, b 1-liter bottles, and c 2-liters ones. They have enough money to buy any amount of cola. They have enough money to buy any amount of cola bottles. But they are confused as to how to buy bottles. Your task is to count the number of all the possible ways to buy exactly n liters of cola.

All the bottles are considered indistinguishable, i.e. two variants of buying are different from each other only if they differ in the number of bottles of at least one kind.

Input Format

The first line contains four integers n, a, b, c.

Constraints

1 ≤ n ≤ 10000

0 ≤ a, b, c ≤ 5000

Output Format

Print the unique number. If it is impossible to buy exactly n liters of cola, print 0.

Sample Input 0

10 5 5 5
Sample Output 0

9
Sample Input 1

3 0 0 2
Sample Output 1

0
'''
# Enter your code here. Read input from STDIN. Print output to STDOUT
n,a,b,c=list(map(int,input().split()))
cnt=0
for i in range(b+1):
    for j in range(c+1):
        k=n-i-2*j
        if k>=0 and a>=k*2:
            cnt+=1
print(cnt)


    
