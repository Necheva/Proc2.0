#include <stdlib.h>
#include <time.h>

class flo
{
	int MAX_RAND;

public:
	flo(int max = 100);
	int crit = 100;
	void InsCrit(int c);
	bool TaskGen();
};