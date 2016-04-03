#include "TQueue.h"

TQueue::TQueue(int n)
{
	MemSize = n;
	Size = 0;
	Hi = 0;
	Li = 0;
	pMem = new int[MemSize];
	for (int i = 0; i < MemSize; i++)
		pMem[i] = 0;
}

TQueue::TQueue(const TQueue &q)
{
	MemSize = q.MemSize;
	Size = q.Size;
	Hi = q.Hi;
	Li = q.Li;
	pMem = new int[MemSize];
	for (int i = 0; i < MemSize; i++)
		pMem[i] = q.pMem[i];
}

TQueue::~TQueue()
{
	delete[]pMem;
}

int TQueue::GetNextIndex(int i)
{
	return ++i%MemSize;
}

bool TQueue::IsEmpty() const
{
	return (Size == 0);
}


bool TQueue::IsFull(void) const
{
	return (Size == MemSize);
}



void TQueue::Put(const int Val)
{
	Size++;
	Hi = GetNextIndex(Hi);
	pMem[Hi] = Val;
}


int TQueue::Peek(void)
{
	return pMem[Li];
}


int TQueue::Push(void)
{
	Size--;
	int i = Li;
	Li = GetNextIndex(Li);
	return pMem[i];
}
