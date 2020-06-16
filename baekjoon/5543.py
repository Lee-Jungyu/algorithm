sd = int(input())
jd = int(input())
hd = int(input())
coke = int(input())
soda = int(input())

bg = min(sd, jd, hd)
dr = min(coke, soda)

print(bg + dr - 50)
