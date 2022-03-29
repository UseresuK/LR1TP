#include <iostream>
#include "headerProt.h"
using namespace std; 

float childQueueProtected::numberMath()
{
	Unit* buff = getTail();
	float sym = 0;
	int iter = 0;
	int start = buff->data;
	Unit* tail = getTail();

	iter = size;

	for (int i = 0; i < iter; i++)
	{
		if ((start % 2) == 0)
		{
			sym = sym + 1;
		}

		tail = tail->prev;

		if (tail == nullptr)
		{
			break;
		}
		start = tail->data;
	}

	return sym;
}
int childQueueProtected::pop() { return mainQueue::pop(); }
void childQueueProtected::push(int el) { return mainQueue::push(el); }
void childQueueProtected::print() { return mainQueue::print(); }
void childQueueProtected::merge(childQueueProtected& quePrivate) { return mainQueue::merge(quePrivate); }
void childQueueProtected::copy(childQueueProtected& quePrivate) { return mainQueue::copy(quePrivate); }
bool childQueueProtected::isEmpty() { return mainQueue::isEmpty(); }