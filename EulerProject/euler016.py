t = int(raw_input())
for i in range (0,t):
    n = int(raw_input())
    ans = sum(int(x) for x in str(2**n))
    print(str(ans))
