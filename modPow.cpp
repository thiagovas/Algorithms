#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

/* Cálcula o modulo n da potencia a^e, ou seja, (a^e)%n */
int modPow(int a, int e, int n)
{
	int p = 1;
	while(e != 0)
	{
		if(e % 2 != 0) p = (a*p)%n;
		e >>= 1;
		a = (a*a) % n;
	}
	return p;
}
