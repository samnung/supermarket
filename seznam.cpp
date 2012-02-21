#include <math.h>
#include "seznam.h"

seznam::seznam()
{
	sa[0] = 1.64;
	sa[1] = 2.13;
	sa[2] = 2.69;
	sa[3] = 2.69;
	sa[4] = 2.75;
	sa[5] = 2.70;
	sa[6] = 5.88;
	sa[7] = 4.07;
	sa[8] = 6.02;
	sa[9] = 7.98;
	sa[10] = 5.54;
	sa[11] = 6.72;
	sa[12] = 9.80;
}
double seznam::value(int a)
{
    return sa[a];
}
long double seznam::vypocet(long double PV, double r, int t, double popl)
{
	return (((1 - popl) * PV) * (pow(1 + r, t)));
}


