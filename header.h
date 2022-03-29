#pragma once

typedef struct Unit 
{
	int data = 0; 
	Unit* prev = 0; 
} Unit;

class mainQueue{

private:
	Unit* tail = 0; 

protected:
	int size; 
	

public:

	mainQueue(); 
	~mainQueue(); 
	Unit* getTail(); 
	int pop(); 
	void push(int el); 
	void print(); 
	void merge(mainQueue& quePrivate); 
	void copy(mainQueue& queue); 
	bool isEmpty(); 

};
