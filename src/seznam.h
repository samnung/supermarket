#ifndef SEZNAM_H
#define SEZNAM_H

#include "define.h"
class seznam
{
	double sa[13];
public:
	explicit		seznam();
	double			value(int a);
	long double	vypocet(long double PV, double r, int t, double popl = 0);

};

#endif // SEZNAM_H
