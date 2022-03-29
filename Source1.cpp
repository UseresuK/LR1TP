#include <iostream>
#include "header.h"
using namespace std;

mainQueue::mainQueue()
{
	size = 0;
	tail = nullptr;
}

mainQueue::~mainQueue() 
{
	while (size > 0)
	{
		Unit* temp = tail; 
		tail = temp->prev; 
		delete temp; 
		size--; 
	}
}

Unit* mainQueue::getTail()
{
	return tail;
}

int mainQueue::pop()
{
	setlocale(LC_ALL, "Rus");
	Unit* tmp = tail;
	int deldata = 0;

	if (tmp->prev == nullptr) 
	{
		deldata = tmp->data;
		delete tail; 
		tail = nullptr; 
		size--; 
	}
	else
	{	
		while (tmp->prev->prev != nullptr) 
		{
			tmp = tmp->prev;
		}
		deldata = tmp->prev->data;
		delete tmp->prev;
		tmp->prev = nullptr;
		size--;
	}
	return deldata;
}

void mainQueue::push(int el)
{
	Unit* new_unit = new Unit; 
	new_unit->prev = tail; 
	tail = new_unit; 
	tail->data = el; 
	size++;
}

void mainQueue::print()
{
	Unit* tmp = tail;

	while (tmp->prev != nullptr)
	{
		cout << tmp->data << " --> ";
		tmp = tmp->prev;
	}
	cout << tmp->data << endl; //вывели последний элемент
}

void mainQueue::copy(mainQueue& queue) //метод копирования очереди
{
	int* buff = new int[queue.size]; //создаем буферный массив
	Unit* el_queue = queue.tail; //создаем переменную очереди

	for (int i = queue.size - 1; i >= 0; i--)
	{
		buff[i] = el_queue->data; 
		el_queue = el_queue->prev; 
	}

	for (int i = 0; i < queue.size; i++)
	{
		this->push(buff[i]);
	}

	delete[] buff;
	
}

void mainQueue::merge(mainQueue& quePrivate)
{
	int* buff1 = new int[quePrivate.size];
	Unit* el_queue1 = quePrivate.tail;

	for (int i = quePrivate.size - 1; i >= 0; i--)
	{
		buff1[i] = el_queue1->data;
		el_queue1 = el_queue1->prev;
	}

	for (int i = 0; i < quePrivate.size; i++)
	{
		this->push(buff1[i]);
	}
	delete[] buff1;
	cout << "The merge has been successfully completed!" << endl;
}

bool mainQueue::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
