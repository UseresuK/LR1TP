#include <iostream>
#include "headerPubl.h"
using namespace std;

float childQueuePublic::numberMath()
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