n = int(input())

i = 0

mx = 0
while i < n:
    x = int(input())

    if x > mx:
        mx = x
    i += 1

print(mx)
