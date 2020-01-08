#include <iostream>
using namespace std;

char infix[101];
char postfix[101];
char os[101];
int otop = -1;
char nos[101];
int  notop = -1;

void input()
{
	scanf("%s", infix);
}

void push(char c, char o)
{
	if (c == 'o' || c == 'O') {
		os[++otop] = o;
	}
	else {
		nos[++notop] = o;
	}
}

char pop(char c) 
{
	if (c == 'o') {
		otop--;
		return os[otop + 1];
	}
	else {
		notop--;
		return nos[notop + 1];
	}
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	return false;
}

int isp(char c)
{

	int i1;
	switch (c)
	{
	case '(':
		i1 = 1;
		break;
	case '*':
	case '/':
		i1 = 5;
		break;
	case '+':
	case '-':
		i1 = 2;
		break;
	case ')':
		i1 = 10;
		break;
	}

	return i1;
}

int icp(char c)
{

	int i1;
	switch (c)
	{
	case '(':
		i1 = 10;
		break;
	case '*':
	case '/':
		i1 = 5;
		break;
	case '+':
	case '-':
		i1 = 2;
		break;
	case ')':
		i1 = 1;
		break;
	}

	return i1;
}

void solve()
{
	int pFlag = 0;
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (isOperator(infix[i])) {
			if (infix[i] == ')') {
				while (true) {
					if (os[otop] == '(') {
						otop--;
						break;
					}

					postfix[pFlag++] = os[otop--];
				}
			}
			else {
				if (otop != -1) {
					if (icp(infix[i]) <= isp(os[otop]))
					{
						while (icp(infix[i]) <= isp(os[otop])) {
							postfix[pFlag++] = os[otop--];
							if (otop == -1) break;
						}
					}
				}
				push('o', infix[i]);
			}
		}
		else {
			postfix[pFlag++] = infix[i];
		}
	}

	while (otop > -1)
	{
		postfix[pFlag++] = os[otop--];
	}
}

void output()
{
	printf("%s\n", postfix);
}

int main()
{
	input();
	solve();
	output();
}
