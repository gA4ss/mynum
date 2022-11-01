import numpy as np

def sin(x):
  res = 0
  denominator = 1
  numerator = 1
  item = 0
  for taylor_expansion in range(1,5):
    numerator = x**denominator
    item = numerator / np.math.factorial(denominator)
    if taylor_expansion % 2 == 0:
      res = res - item
    else:
      res = res + item
    print("taylor_expansion = ", taylor_expansion,
          " numerator = ", numerator,
          " denominator = ", denominator,
          " item = ", item,
          " res = ", res)
    denominator = denominator + 2
  return res

def cos(x):
  res = 1
  denominator = 0
  numerator = 1
  item = 0
  for taylor_expansion in range(1,5):
    if taylor_expansion != 1:
      numerator = x**denominator
      item = numerator / np.math.factorial(denominator)
      if taylor_expansion % 2 == 0:
        res = res - item
      else:
        res = res + item
    print("taylor_expansion = ", taylor_expansion,
          " numerator = ", numerator,
          " denominator = ", denominator,
          " item = ", item,
          " res = ", res)
    denominator = denominator + 2
  return res

def bernoulli_numbers(x):
  k = x
  b = 0
  if x == 0:
    return 1

  if ((x > 1) and (x % 2 == 1)):
    return 0
  numerator = 0
  denominator = 0
  item = 0

  while k != 0:
    k -= 1
    numerator = np.math.factorial(x) * bernoulli_numbers(k)
    denominator = np.math.factorial(x - k) * np.math.factorial(k) * (x - k + 1)
    item = numerator / denominator
    b += (item * -1)
  return b

for i in range(0, 10):
  b = bernoulli_numbers(i)
  print(i, ") ", b)

def arctan_2(x):
  res = 0
  n = 1
  item = 0
  for i in range(1, 25):
    item = 1 / (n * x**n) # div("1", mul(n, pow(x, n)));
    if i % 2 == 0:
      res += item
    else:
      res -= item
    n += 2

  half_pi = np.pi/2;
  if x <= -1:
     half_pi = half_pi * -1
  res = half_pi + res
  return res

# x = 0.5235987666666667
# x = 1.7320508075688774
# y = arctan_2(x)
# print("y = ", y)

"""
sin(pi/6)
taylor_expansion =  1  numerator =  0.5235987666666667  denominator =  1  item =  0.5235987666666667  res =  0.5235987666666667
taylor_expansion =  2  numerator =  0.1435475698776374  denominator =  3  item =  0.023924594979606233  res =  0.49967417168706046
taylor_expansion =  3  numerator =  0.039354379974873614  denominator =  5  item =  0.0003279531664572801  res =  0.5000021248535177
taylor_expansion =  4  numerator =  0.010789226348637816  denominator =  7  item =  2.140719513618614e-06  res =  0.4999999841340041
"""
