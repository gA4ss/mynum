import math

def exp(x, eps=0.000000000001):
  y = x
  n = 2

  while(1):
    p = y
    print("x**n = {}\n".format(x**n))
    print("factorial(n) = {}\n".format(math.factorial(n)))
    print("x**n / math.factorial(n) = {}\n".format(x**n / math.factorial(n)))
    y = y + (x**n / math.factorial(n))
    print("y = {}\n".format(y))
    n = n + 1
    if (abs(y - p) <= eps):
      break;
  y = y + 1
  return y

a = exp(1.4484941211906903)
print(a)

