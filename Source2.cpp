#include <iostream>
#include "header.h"
#include "headerPubl.h"
#include "headerPriv.h"
#include "headerProt.h"

using namespace std;

/*Вариант 7 - Вычисление количества четных элементов*/

template <class T>
void chosen_class(T* queue, int numQueue) {
	int c;
	bool flag = true;
	int value; 
	int index = 0; 
	int count = 1; 
	int chosen_q; 

	while (flag)
	{
		cout << "1 >> Add an element" << endl;
		cout << "2 >> Take an element" << endl;
		cout << "3 >> Print queue" << endl;
		cout << "4 >> Calculating the number of even elements" << endl;
		cout << "5 >> Сopy of the queue" << endl;
		cout << "6 >> Merged queues" << endl;
		cout << "7 >> Choosing another queue" << endl;
		cout << "0 >> Back to queue selection" << endl;
		cout << ">> ";
		cin >> c;

		switch (c)
		{
		case 1:
			system("cls");
			cout << "Input value: ";
			cin >> value;
			queue[index].push(value);
			cout << "The element has been added to the queue.\n " << endl;
			break;
		case 2: 
			if (queue[index].isEmpty())
			{
				cout << "The queue is empty " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = queue[index].pop();
				cout << "value from the queue: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: 
			if (queue[index].isEmpty())
			{
				cout << "The queue is empty " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				queue[index].print();
				cout << "\n";
			}
			break;
		case 4: 
			if (queue[index].isEmpty())
			{
				cout << "The queue is empty " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				cout << "Number of even elements: " << queue[index].numberMath() << endl;
				cout << "\n";
			}
			break;
		case 5:

			if (queue[index].isEmpty())
			{
				cout << "The queue is empty" << endl;
				system("pause");
				break;
			}

			else
			{
				cout  << "Enter the queue number where you want to insert the copied queue:" << endl;
				cin >> chosen_q;
				if (1 == numQueue || chosen_q == index)
				{

					cout << "Number of queues = 1 \n" << endl;
					system("pause");
					break;
				}

				system("cls");
				queue[chosen_q].copy(queue[index]);
				cout << "The queue has been copied successfully. Now there are two equal queues.\n" << endl;

			}
			break;
		case 6: 
			if (numQueue == 1)
			{
				cout << "There is only one queue.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Which queue to merge with?" << endl;
				cin >> chosen_q;

				if ((chosen_q < 0) || (chosen_q >= numQueue) || (chosen_q == index))
				{
					cout << "Invalid value!\n" << endl;
					system("pause");
					break;
				}

				if (queue[chosen_q].isEmpty())
				{
					cout << "The queue is empty\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				queue[index].merge(queue[chosen_q]);
				cout << "\n";
			}
			break;
		case 7: 
			system("cls");
			cout << "You are currently use queue №." << index << endl;
			cout << "Enter the queue number from 0 to " << numQueue - 1 << ") , which one do you want to switch to: ";
			cin >> chosen_q;

			if ((chosen_q < 0) || (chosen_q >= numQueue) || (chosen_q == index))
			{
				cout << "Invalid value or the number of queues exceeded!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				count++;
				system("cls");
				cout << "You are switch to queue№" << index << endl;
				cout << "\n";
			}
			break;
		case 0:
			cout << "\n";
			flag = false;
			break;
		}
	}
}

int main()
{
	
	int numQueue; 
	int c;
	bool flag = true;

	childQueuePrivate* quePrivate = NULL;
	childQueueProtected* queProtected = NULL;
	childQueuePublic* quePublic = NULL;

	
	do
	{
		cout << "Enter the number of queues: ";
		cin >> numQueue;
	} while (numQueue <= 0 && cout << "Incorrect number of queues entered, enter again.\n" );
	system("cls");

	cout << "Choose which class you will work with: " << endl;

	while (flag)
	{
		cout << "1 >> Private" << endl;
		cout << "2 >> Protected" << endl;
		cout << "3 >> Public" << endl;
		cout << "0 >> Exit" << endl;
		cout << ">> ";
		cin >> c;

		switch (c)
		{
		case 1:
			quePrivate = new childQueuePrivate[numQueue];
			system("cls");
			chosen_class(quePrivate, numQueue);
			delete[] quePrivate;
			break;
		case 2:
			queProtected = new childQueueProtected[numQueue];
			system("cls");
			chosen_class(queProtected, numQueue);
			delete[] queProtected;
			break;
		case 3:
			quePublic = new childQueuePublic[numQueue];
			system("cls");
			chosen_class(quePublic, numQueue);
			delete[] quePublic;
			break;
		case 0:
			flag = false;
			break;
		default:
			system("cls");
			cout << "Invalid input!" << endl;
			break;
		}
	}

	return 0;
}
