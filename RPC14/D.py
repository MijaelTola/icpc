def rev(a_string):
    return a_string[::-1]
a,b = raw_input().split()
c,d = raw_input().split()

a = int(a)
b = int(b)
c = int(c)
d = int(d)
sol = ""

while(True):
    if a == 1 and b == 0 and c == 0 and d == 1: break
    if a-b >= 1 and c-d >= 0:
        a = a-b; c = c-d
        sol = sol + "0"
    else:
        b = b-a
        d = d-c
        sol = sol + "1"

sol = rev(sol)
print sol
