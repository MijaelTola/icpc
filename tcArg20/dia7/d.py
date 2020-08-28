a,b = input().split(' ')
a = int(a)
b = int(b)
c = a**b

sum = 0

while c > 0:
    sum = sum + c % 10
    c = int(c / 10)

c = sum

while c >= 10:
    p = c;
    sum = 0
    while p > 0:
        sum = sum + p % 10
        p = int(p / 10)
    c = sum

        
print(c)

