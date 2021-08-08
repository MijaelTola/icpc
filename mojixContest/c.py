
def g(x):
    if x == -1 or x == 0:
        return 1
    return x * g(x - 2)


n = int(input())

p = 0

id = -1

while p < 100:
    if g(p) == n:
        id = p
    p += 1

if id != -1:
    print(id)
else:
    print("NOT_FOUND")
        
