#include <stdlib.h>
#include <time.h>

class proc
{
	int MAX_RAND;
	int crit = 100;
	int tasknumber = 0;
public:
	proc(int max = 100);
	void InsCrit(int c);
	bool TaskProc();
	int GetNum();
	bool IsOcc = 0;

};

