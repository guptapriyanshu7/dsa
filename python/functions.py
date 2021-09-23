import math

def degToRad(deg):
  rad = deg * (math.pi / 180)
  return rad

print(math.sin(degToRad(30)))

a = 5
print(a)

def add(x, y):
  return (x + y)

a = int(input('Enter the value of a:'))
b = int(input('Enter the value of b:'))

sum = add(a, b)
print(sum)

def interest(p, t = 2, r = 0.10):
  return p * t * r

print(interest(6100, 1))
print(interest(5000, r = 0.05))
print(interest(5000, 3, 0.12))
print(interest(t = 4, p = 5000))

def change(p, q = 30):
  p = p + q
  q = p - q
  print(p, '#', q)
  return(p)

a = 150 
b = 100
a = change(a, b)
print(a, '#', b)
b = change(b)

def fun(s):
  k=len(s)
  m=''
  for i in range (0,k):
    if(s[i].isupper()):
      m=m+s[i].lower()
    elif(s[i].isalpha()):
      m=m+s[i].upper()
    else:
      m=m+'bb'
  print(m)

fun('@gmail.com')

def sum1(x, y):        
  return x + y
a = 2
b = 3
c = sum(a, b)
print(c)

x = 5
def add1(a):
  b = a + 1
  return b
y = int(input('Enter y:'))
z = y + add1(x)
print(z)

print('\u7765')