#include "flo.h"

bool flo::TaskGen()
{
	return (rand() % MAX_RAND < crit);
}

void flo::InsCrit(int c)
{
	crit = c;
}

flo::flo(int max)
{
	MAX_RAND = max;
}