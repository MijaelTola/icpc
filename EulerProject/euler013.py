# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as mt
n = raw_input()
n = int(n)

ans = 0
while n > 0:
    x = raw_input()
    x = int(x)
    ans += x
    n -= 1

nd = int(mt.log10(ans)+1)
nd -= 10
#print(mt.pow(10,nd))
print(int(ans/(mt.pow(10,nd))))
