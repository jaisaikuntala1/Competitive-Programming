'''n people are taking music lessons. Initially, everyone is standing together in a line from left to right. Each person has musical power ai. There are at least one boy and a girl in the line. The following process is repeated:

1) Boy and girl standing next to each other, having a minimal absolute difference in musical powers come forward and start to sing. If there are multiple possibilities then the one from the left starts to sing.

2) After '1', The line closes and fill the vacant place again so the line remains continuous.

Your task is to find out what pairs and in what order will start dancing.

Input Format

The first line contains an integer n.

The next line contains n characters B or G without spaces. (B -> Boys, G->Girls)

The third line contains n space-separated integers a*i*. People are specified from left to right in the order in which they lined up.

Constraints

1  ≤  n  ≤  2 * 10^5

1  ≤  a*i*  ≤   10^7

Output Format

Print the resulting number of couples k.

Then print t lines containing two numbers the numbers of people forming the couple. The people are numbered with integers from 1 to n from left to right. When a couple leaves to sing you shouldn't renumber the people. The numbers in one couple should be sorted in the increasing order. Print the couples in the order in which they leave to dance.

Sample Input 0

4
BGBG
4 2 4 3
Sample Output 0

2
3 4
1 2
Sample Input 1

4
BBGG
4 6 1 5
Sample Output 1

2
2 3
1 4
Sample Input 2

4
BGBB
1 1 2 3
Sample Output 2

1
1 2
'''

import heapq as hq
n=int(input())
s=input()
a=list(map(int,input().split()))
pre=[i-1 for i in range(n)]
nxt=[i+1 for i in range(n)]
free=[1 for i in range(n)]
line=[(abs(a[i]-a[i+1]),i,i+1) for i in range(n-1) if s[i]!=s[i+1]]
#print(line)
hq.heapify(line)
ans=[]
#print(line) 
while line:
    t,ppre,pnxt=hq.heappop(line)
    
    #print(line,t,ppre,pnxt)
    if free[ppre] and free[pnxt]:
        ans.append(str(ppre+1)+' '+str(pnxt+1))
        free[ppre],free[pnxt]=0,0
        if ppre==0 or pnxt==n-1:
            continue
        preppre,nxtpnxt=pre[ppre],nxt[pnxt]
        nxt[preppre],pre[nxtpnxt]=nxtpnxt,preppre
        if s[preppre]!=s[nxtpnxt]:
            hq.heappush(line,(abs(a[preppre]-a[nxtpnxt]),preppre,nxtpnxt))
        
print(len(ans))
print('\n'.join(ans))
