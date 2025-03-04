#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct stack
{
	char data;
	stack* next;
};

void push(stack*& first, char data)
{
	stack* p = new stack;
	p->data = data;
	p->next = NULL;
		if (first == NULL)
			first = p;
		else
		{
			stack* g = first;
			while (g && g->next != NULL)
				g = g->next;
			g->next = p;
		}
}

void exit__(ofstream &out)
{
	out << "No" << endl;
	exit(-1);
}

void pop(stack*& first)
{
	stack* temp = first;
	stack* prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev)
		prev->next = NULL; 
	else
	{
		first = NULL;
	}
	if (temp)
		delete temp;
}

char back(stack* first)
{
	stack* p = first;
	if (first)
	{
		while (p && p->next != NULL)
		{
			p = p->next;
		}
	}
	if (p)
		return p->data;
	return NULL;
}

int size(stack* first)
{
	int i = 0;
	stack* p = first;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

void clear(stack*& first)
{
	while (first)
		pop(first);
}

void skobki(stack*& first, char data, ofstream &out)
{
	stack* g = first;
	if (data == '(')
		push(first, data);
	if (data == ')')
	{
		if (first == NULL)
			exit__(out);
		else
		{
			if (back(first) == '(')
				pop(first);
		}
	}
}

void skobki2(stack*& first, char* x, ofstream &out)
{
	int n = strlen(x);
	for (int i = 0; i < n; i++)
		skobki(first, x[i], out);
}

int main()
{
	ifstream in("skobki.txt");
	ofstream out("out.txt");
	char x[100];
	if (!in)
	{
		cout << "Can't open file!" << endl;
		exit(-1);
	}
	in >> x;
	stack* list = NULL;
	skobki2(list, x, out);
	if (list)
		out << "No" << endl;
	else
		out << "Yes" << endl;
	clear(list);
	return 0;
}


