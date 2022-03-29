#include <iostream>
#include "headerPriv.h"
using namespace std;

float childQueuePrivate::numberMath()
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
int childQueuePrivate::pop() { return mainQueue::pop(); }
void childQueuePrivate::push(int el) { return mainQueue::push(el); }
void childQueuePrivate::print() { return mainQueue::print(); }
void childQueuePrivate::merge(childQueuePrivate& quePrivate) { return mainQueue::merge(quePrivate); }
void childQueuePrivate::copy(childQueuePrivate& quePrivate) { return mainQueue::copy(quePrivate); }
bool childQueuePrivate::isEmpty() { return mainQueue::isEmpty(); }