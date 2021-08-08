
v = []

n = input()
n = int(n)

i = 0
while i < n:
    x = input()
    x = int(x)
    v.append(x)
    i = i + 1

ans = v[0]
ans = int(ans)

p = 1

while p < n: 
    ans = (ans * int(v[p])) - (ans - 1) - (int(v[p]) - 1)
    p = p + 1;

print(ans)
