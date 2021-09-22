a = int(input())
b = int(input())
c = int(input())
d = int(input())

p = (a + b + c + d) / 2

s = (a + b) * ((p - a) * (p - b) * (p - a - c) * (p - a - d))**(1/2) / abs(a - b)

print("AREA:", s)
