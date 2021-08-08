def invr():
    return(map(int,input().split()))
def sqrt(x):
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
#LEER N y K

n,k = input().split()
n = int(n)
k = int(k)
#n,k = 2, 6

p10 = 10**(k+k)
res = sqrt(n * p10)
res = int(res)
resS = str(res)
#print(res)
l = len(resS)
resF = ""
for i in range(l-k,l):
    resF=  resF +resS[i]
resF="." + resF
resI = ""
for i in range(0,l-k):
    resI=  resI + resS[i]
print(resI+resF)


