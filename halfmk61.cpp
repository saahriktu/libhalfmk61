#include "halfmk61.hpp"

/*
 * USSR programmable calculator MK-61 notprogrammable subsystem only
 *				(stack and registers + operations)
 * License: GNU GPLv3
 * Author: Artem Kurashov
 */

halfmk61::halfmk61 (int rgrdgv)
{
  rgrdg = rgrdgv;
  errorflag = 0;
  shiftflag = 0;
  srand (time (0));
  x1 = 0;
  x = 0;
  y = 0;
  z = 0;
  t = 0;
}

double
halfmk61::getx ()
{
  return x;
}

void
halfmk61::setx (double nx)
{
  if (shiftflag)
    {
      t = z;
      z = y;
      y = x;
    }
  x = nx;
  shiftflag = 0;
}

void
halfmk61::plus ()
{
  x1 = x;
  x += y;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::minus ()
{
  x1 = x;
  x = y - x;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::divide ()
{
  x1 = x;
  x = y / x;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::multiply ()
{
  x1 = x;
  x *= y;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::stackup ()
{
  t = z;
  z = y;
  y = x;
  x = x1;
  shiftflag = 1;
}

void
halfmk61::stackdown ()
{
  x1 = x;
  x = y;
  y = z;
  z = t;
  t = x1;
  shiftflag = 1;
}

void
halfmk61::swapxy ()
{
  x1 = x;
  x = y;
  y = x1;
  shiftflag = 1;
}

void
halfmk61::sinus ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = sin (x);
      break;
    case 0:
      x = sin (x * 3.1415926 / 200);
      break;
    case 1:
      x = sin (x * 3.1415926 / 180);
    }
  shiftflag = 1;
}

void
halfmk61::cosinus ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = cos (x);
      break;
    case 0:
      x = cos (x * 3.1415926 / 200);
      break;
    case 1:
      x = cos (x * 3.1415926 / 180);
    }
  shiftflag = 1;
}

void
halfmk61::squareroot ()
{
  x1 = x;
  x = sqrt (x);
  shiftflag = 1;
}

void
halfmk61::power2 ()
{
  x1 = x;
  x = pow (x, 2);
  shiftflag = 1;
}

void
halfmk61::stackdump ()
{
  std::
    cout << "x1: " << x1 << ", x: " << x << ", y: " << y << ", z: " << z <<
    ", t: " << t << "\n";
}

void
halfmk61::stackhalfup ()
{
  t = z;
  z = y;
  y = x;
  shiftflag = 0;
}

void
halfmk61::setregx (int ri)
{
  t = z;
  z = y;
  y = x;
  x = r[ri];
  shiftflag = 1;
}

void
halfmk61::setxreg (int ri)
{
  r[ri] = x;
  shiftflag = 1;
}

void
halfmk61::setkregx (int ri)
{
  t = z;
  z = y;
  y = x;
  x = r[(int) floor (r[ri])];
  shiftflag = 1;
}

void
halfmk61::setkxreg (int ri)
{
  r[(int) floor (r[ri])] = x;
  shiftflag = 1;
}

void
halfmk61::tg ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = tan (x);
      break;
    case 0:
      x = tan (x * 3.1415926 / 200);
      break;
    case 1:
      x = tan (x * 3.1415926 / 180);
    }
  shiftflag = 1;
}

void
halfmk61::onedividex ()
{
  x1 = x;
  x = 1 / x;
  shiftflag = 1;
}

void
halfmk61::arcsin ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = asin (x);
      break;
    case 0:
      x = asin (x) * 200 / 3.1415926;
      break;
    case 1:
      x = asin (x) * 180 / 3.1415926;
    }
  shiftflag = 1;
}

void
halfmk61::arccos ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = acos (x);
      break;
    case 0:
      x = acos (x) * 200 / 3.1415926;
      break;
    case 1:
      x = acos (x) * 180 / 3.1415926;
    }
  shiftflag = 1;
}

void
halfmk61::arctg ()
{
  x1 = x;
  switch (rgrdg)
    {
    case -1:
      x = atan (x);
      break;
    case 0:
      x = atan (x) * 200 / 3.1415926;
      break;
    case 1:
      x = atan (x) * 180 / 3.1415926;
    }
  shiftflag = 1;
}

void
halfmk61::powex ()
{
  x1 = x;
  x = pow (2.718281828, x);
  shiftflag = 1;
}

void
halfmk61::lg ()
{
  x1 = x;
  x = log (x);
  shiftflag = 1;
}

void
halfmk61::ln ()
{
  x1 = x;
  x = log10 (x);
  shiftflag = 1;
}

void
halfmk61::powxy ()
{
  x1 = x;
  x = pow (y, x);
  shiftflag = 1;
  if (x == 0 && y == 0)
    errorflag = 1;		// calculator compatible
}

void
halfmk61::pow10x ()
{
  x1 = x;
  x = pow (10, x);
  shiftflag = 1;
}

void
halfmk61::setxpi ()
{
  x = 3.1415926;
  shiftflag = 1;
}

void
halfmk61::xfloor ()
{
  x1 = x;
  x = floor (x);
  shiftflag = 1;
}

void
halfmk61::ufloor ()
{
  x1 = x;
  x = x - floor (x);
  shiftflag = 1;
}

void
halfmk61::xabs ()
{
  x1 = x;
  x = abs (x);
  shiftflag = 1;
}

void
halfmk61::xsign ()
{
  if (x < 0)
    x = -1;
  else if (x > 0)
    x = 1;
  shiftflag = 1;
}

void
halfmk61::setxrandom ()
{
  x = (rand () / (RAND_MAX + 1.0));
  shiftflag = 1;
}

void
halfmk61::xyor ()
{
  x1 = x;
  x = (int) x | (int) y;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::xyand ()
{
  x1 = x;
  x = (int) x & (int) y;
  y = z;
  z = t;
  shiftflag = 1;
}

void
halfmk61::xyxor ()
{
  x1 = x;
  x = (int) x ^ (int) y;
  y = z;
  z = t;
  shiftflag = 1;
}

int
halfmk61::geterrorflag ()
{
  return errorflag;
}

void
halfmk61::opmax ()
{
  x1 = x;
  if (x == 0 || y == 0)
    x = 0;			// mk-61 bug
  else if (y > x)
    x = y;
  y = z;
  z = t;
  shiftflag = 1;
}

double
halfmk61::getdirectr (int nx)
{
  return r[nx];
}
