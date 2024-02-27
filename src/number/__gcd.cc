static myint_t __gcd(myint_t x, myint_t y)
{
#if defined(STD_GCD)
  return std::__gcd(x, y);
#else
  myint_t _x, _y, z;
  if (x > y)
  {
    _x = x;
    _y = y;
  }
  else
  {
    _x = y;
    _y = x;
  }

  while (_x % _y != 0)
  {
    z = _x % _y;
    _x = _y;
    _y = z;
  }
  return _y;
#endif
}