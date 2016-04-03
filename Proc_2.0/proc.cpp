#include "proc.h"
#include <stdio.h>

proc::proc(int max)
{
	MAX_RAND = max;
}

void proc::InsCrit(int c)
{
	crit = c;
}

bool proc::TaskProc()
{
	int result = rand() % MAX_RAND;
	if (result < crit)
	{
		tasknumber++;
		IsOcc = 0;
	}
	else
		IsOcc = 1;
	return (result < crit);
}

int proc::GetNum()
{
	return tasknumber;
}
