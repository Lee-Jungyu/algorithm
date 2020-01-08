#include <iostream>
#include <string>
using namespace std;

char stack1[1000001] = { 0, };
char stack2[1000001] = { 0, };

int top1 = -1;
int top2 = -1;

void left()
{
	if(top1 != -1)
		stack2[++top2] = stack1[top1--];
}

void right()
{
	if(top2 != -1)
		stack1[++top1] = stack2[top2--];
}

void erase()
{
	if(top1 != -1)
		top1--;
}

void input(char c)
{
	stack1[++top1] = c;
}

void finish()
{
	while (top2 > -1)
	{
		stack1[++top1] = stack2[top2--];
	}
}

void result()
{
	for (int i = 0; i <= top1; i++)
	{
		cout << stack1[i];
	}
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		top1 = -1;
		top2 = -1;
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '-')
				erase();
			else if (str[i] == '<')
				left();
			else if (str[i] == '>')
				right();
			else
				input(str[i]);
		}
		finish();
		result();
		cout << endl;
	}
}


