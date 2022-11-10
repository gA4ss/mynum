import math

def sin(x, eps=0.000000005):
  y = 0.0
  p = 0.0
  numerator = 0.0
  denominator = 1.0
  i = 1
  while(1):
    p = y
    print("p = {}".format(p))
    numerator = math.pow(x, denominator)
    print("numerator = {}".format(numerator))
    item = numerator / math.factorial(denominator)
    print("item = {}".format(item))
    if (i % 2 == 0):
      y = y - item
    else:
      y = y + item
    print("y = {}".format(y))
    denominator += 2.0
    print("denominator = {}".format(denominator))
    i += 1
    if (abs(y - p) < eps):
      break
  return y

def R(d):
  return (math.pi / 180.0) * d

y = sin(R(60))
print(y)