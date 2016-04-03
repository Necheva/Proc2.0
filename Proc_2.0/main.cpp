#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "flo.h"
#include "proc.h"
#include <locale.h>
#include "TQueue.h"
#pragma warning(disable : 4996)
#define MAX_RANDOM 100
#define PRINT_TICKS 20


int main()
{
	int ignored = 0, pass = 0;
	int pc, fc;
	TQueue q(50);
	proc p(MAX_RANDOM);
	flo f(MAX_RANDOM);
	int ticks;
	int i;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	///--------------------------------

	printf("Entet ticks\n");
	do {
		scanf("%d", &ticks);
	} while (ticks <= 0);


	printf("Entet crit proc\n");
	do {
		scanf("%d", &pc);
	} while ((pc <= 0) || (pc >= MAX_RANDOM));
	p.InsCrit(pc);


	printf("Entet crit flo\n");
	do {
		scanf("%d", &fc);
	} while ((fc <= 0) || (fc >= MAX_RANDOM));
	f.InsCrit(fc);

	///--------------------------------
	for (i = 0; i <= ticks; i++)
	{
		if (f.TaskGen())
		{
			printf(ticks < PRINT_TICKS ? "Задача поступила\n" : "");
			if (q.IsFull())
			{
				printf(ticks < PRINT_TICKS ? "Задача проигнорирована\n" : "");
				++ignored;
			}
			else
			{
				printf(ticks<PRINT_TICKS ? "Задача помещена в очередь\n" : "");
				q.Put(1);
			}
		}
		if (p.IsOcc)
		{
			printf(ticks<PRINT_TICKS ? "Процессор продолжает обрабатывать прошлую задачу\n" : "");
			if (p.TaskProc())
				printf(ticks<PRINT_TICKS ? "Процессор обработал задачу\n" : "");
		}
		else if (!q.IsEmpty())
		{
			printf(ticks<PRINT_TICKS ? "Процессор начал обработку новой задачи\n" : "");
			q.Push();
			if (p.TaskProc())
				printf(ticks<PRINT_TICKS ? "Процессор обработал задачу\n" : "");
		}
		else
		{
			printf(ticks<PRINT_TICKS ? "Процессор простаивает\n" : "");
			pass++;
		}
		printf("%d", i);
	}

	return 0;
}