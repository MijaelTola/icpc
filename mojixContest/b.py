from math import gcd

n = int(input())

a = []

a = list(map(int,input().strip().split()))[:n]

q = int(input())

 
def can(a, b, c):
    return (c % gcd(a, b) == 0)

qq = list(map(int,input().strip().split()))[:n]
 
for caso in range(0, q):
    x = qq[caso]

    flag = False
    for i in range(0, n):
        for j in range(i + 1, n):
            if can(a[i], a[j], x):
                flag = True


    if flag:
        print("YES")
    else: 
        print("NO")
