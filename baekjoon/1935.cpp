#include <iostream>
using namespace std;

int N;
char postfix[101];
double variable[26] = { 0, };
double result = 0;
double nos[101];
int notop = -1;

void input()
{
	scanf("%d", &N);
	scanf("%s", postfix);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &variable[i]);
	}
	
}

void push(double f)
{
	nos[++notop] = f;
}

void pop()
{
	notop--;
}

bool isOperator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}

double calculate(char c, double f1, double f2)
{
	double r = 0;
	switch (c) {
	case '+':
		r = f1 + f2;
		break;
	case '-':
		r = f1 - f2;
		break;
	case '*':
		r = f1 * f2;
		break;
	case '/':
		r = f1 / f2;
		break;
	}

	return r;
}

double translate(char c)
{
	return variable[c - 'A'];
}

void solve()
{
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperator(postfix[i])) {
			double f2 = nos[notop]; pop();
			double f1 = nos[notop]; pop();

			push(calculate(postfix[i], f1, f2));
		}

		else {
			double f = translate(postfix[i]);
			push(f);
		}
	}

	result = nos[notop];
	pop();
}

void output()
{
	printf("%.2lf\n", result);
}

int main()
{
	input();
	solve();
	output();
}
