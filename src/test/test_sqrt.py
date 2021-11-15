import numpy as np

def sqrt(num1):
  if num1 == 0:
    return 0
  elif num1 == 1:
    return 1

  pre = 0
  cur = 1
  t = 2
  e = 0.0000000000000001
  while (abs(cur - pre) > e):
    pre = cur;
    tt = num1 / cur;
    print("tt = num1 / cur : ", tt)
    tt += cur;
    print("tt += cur : ", tt)
    cur = tt / t;
    print("cur = tt / 2 : ", cur)
    print()
  return cur

# sqrt(2)
# tt = num1 / cur :  2.0
# tt += cur :  3.0
# cur = tt / 2 :  1.5

# tt = num1 / cur :  1.3333333333333333
# tt += cur :  2.833333333333333
# cur = tt / 2 :  1.4166666666666665

# tt = num1 / cur :  1.411764705882353
# tt += cur :  2.8284313725490193
# cur = tt / 2 :  1.4142156862745097

# tt = num1 / cur :  1.41421143847487
# tt += cur :  2.8284271247493797
# cur = tt / 2 :  1.4142135623746899

# tt = num1 / cur :  1.4142135623715002
# tt += cur :  2.82842712474619
# cur = tt / 2 :  1.414213562373095

# tt = num1 / cur :  1.4142135623730951
# tt += cur :  2.82842712474619
# cur = tt / 2 :  1.414213562373095

sqrt(3)

# tt = num1 / cur :  3.0
# tt += cur :  4.0
# cur = tt / 2 :  2.0

# tt = num1 / cur :  1.5
# tt += cur :  3.5
# cur = tt / 2 :  1.75

# tt = num1 / cur :  1.7142857142857142
# tt += cur :  3.4642857142857144
# cur = tt / 2 :  1.7321428571428572

# tt = num1 / cur :  1.7319587628865978
# tt += cur :  3.4641016200294548
# cur = tt / 2 :  1.7320508100147274

# tt = num1 / cur :  1.7320508051230272
# tt += cur :  3.4641016151377544
# cur = tt / 2 :  1.7320508075688772

# tt = num1 / cur :  1.7320508075688774
# tt += cur :  3.4641016151377544
# cur = tt / 2 :  1.7320508075688772