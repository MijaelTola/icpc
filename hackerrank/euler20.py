t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    p = 1
    f = 1
    ans = 0

    while p <= n:
        f *= p
        p += 1

    while f > 0:
        ans += f % 10
        f //= 10

    print(ans)

