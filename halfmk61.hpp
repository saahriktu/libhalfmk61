#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

/*
 * USSR programmable calculator MK-61 notprogrammable subsystem only
 *                              (stack and registers + operations)
 * License: GNU GPLv3
 * Author: Artem Kurashov
 */

class halfmk61
{
public:
  halfmk61 (int);
  double getx ();
  int geterrorflag ();
  void setx (double);
  void plus ();
  void minus ();
  void divide ();
  void multiply ();
  void stackup ();		// Bx
  void stackdown ();		// O (2 arrows)
  void stackhalfup ();		// ÷^
  void swapxy ();		// x<->y
  void sinus ();
  void cosinus ();
  void squareroot ();
  void power2 ();
  void tg ();
  void onedividex ();		// 1/x
  void arcsin ();
  void arccos ();
  void arctg ();
  void powex ();		// e^x
  void lg ();			// log
  void ln ();
  void powxy ();		// x^y
  void pow10x ();		// 10^x
  void setxpi ();
  void xfloor ();		// [x]
  void ufloor ();		// {x}
  void opmax ();
  void xabs ();
  void xsign ();
  void setxrandom ();
  void xyor ();
  void xyand ();
  void xyxor ();
  void stackdump ();		// lib special! useful for debugging!
  void setregx (int);		// x=Ri
  void setxreg (int);		// Ri=x
  void setkregx (int);
  void setkxreg (int);
  void setrgrdg (int);
  double getdirectr (int);
private:
  double x1, x, y, z, t;	// stack
  double r[15];			// registers
  int rgrdg;			// r(rad)/grd(grad)/g(degree) switcher (-1/0/1)
  int errorflag;
  int shiftflag;
};
