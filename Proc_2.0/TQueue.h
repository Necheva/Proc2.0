class TQueue
{
	int Li, Hi;
	int Size;
	int *pMem;
	int MemSize;
	int GetNextIndex(int i);
public:
	TQueue(int n = 10);
	TQueue(const TQueue &q);
	~TQueue();
	bool IsEmpty(void) const;
	bool IsFull(void) const;

	void  Put(const int Val);
	int Peek(void);
	int Push(void);
};