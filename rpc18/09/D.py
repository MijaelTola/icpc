n = input()
str_arr = raw_input().split(' ') 
v = [int(num) for num in str_arr]

p = 2
a = True

for x in v:
    p -= x
    if p < 0:
        a = False
    p *= 2

if a:
    print(int((p / 2) % 1000000007))
else:
    print('error')



