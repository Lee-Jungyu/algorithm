#include <iostream>
using namespace std;

int N; //map size
int K; //apple cnt
int L; //change direction cnt

int map[101][101]; //0space 1snake 2apple
int direction; //0up 1down 2left 3right
int snake_length; //snake length
int direction_change[101][2]; //direction change array
int snake_head[2]; //snake head
int totalTime = 0;
int q[10000][2];
int front, rear;
bool gameover;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void push(int x, int y)
{
	snake_head[0] = x;
	snake_head[1] = y;
	map[x][y] = 1;
	q[rear % 10000][0] = x;
	q[rear % 10000][1] = y;
	rear++;
}

void pop()
{
	front++;
}

void init()
{
	direction = 3;
	snake_length = 1;
	snake_head[0] = 1;
	snake_head[1] = 1;
	front = rear = 0;
	push(1, 1);
	gameover = false;
}

void input()
{
	scanf("%d", &N);
	scanf("%d", &K);

	int r, c;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &r, &c);
		map[r][c] = 2;
	}

	int X;
	char C;

	scanf("%d", &L);

	for (int i = 0; i < L; i++)
	{
		scanf("%d \n%c", &X, &C);
		if (C == 'D') {
			if (direction == 0) {
				direction = 3;
			}
			else if (direction == 1) {
				direction = 2;
			}
			else if (direction == 2){
				direction = 0;
			}
			else {
				direction = 1;
			}
		}
		else {
			if (direction == 0) {
				direction = 2;
			}
			else if (direction == 1) {
				direction = 3;
			}
			else if (direction == 2) {
				direction = 1;
			}
			else {
				direction = 0;
			}
		}

		direction_change[i][0] = X;
		direction_change[i][1] = direction;
	}
}

bool checkBorder(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N) {
		return true;
	}
	else return false;
}

void move(int time, int dir)
{
	// if time=0 -> continue for the end
	int i = 1;
	if (time) {
		for (i = 1; i <= time; i++)
		{
			if (checkBorder(snake_head[0] + dx[dir], snake_head[1] + dy[dir]))
			{
				if (map[snake_head[0] + dx[dir]][snake_head[1] + dy[dir]] == 2) {
					push(snake_head[0] + dx[dir], snake_head[1] + dy[dir]);
				}
				else if (map[snake_head[0] + dx[dir]][snake_head[1] + dy[dir]] == 0) {
					push(snake_head[0] + dx[dir], snake_head[1] + dy[dir]);
					map[q[front % 10000][0]][q[front % 10000][1]] = 0;
					pop();
				}
				else {
					gameover = true;
					totalTime += i;
					return;
				}
			}
			else {
				gameover = true;
				totalTime += i;
				return;
			}
		}
	}
	else {
		while (true) 
		{
			if (checkBorder(snake_head[0] + dx[dir], snake_head[1] + dy[dir]))
			{
				if (map[snake_head[0] + dx[dir]][snake_head[1] + dy[dir]] == 2) {
					push(snake_head[0] + dx[dir], snake_head[1] + dy[dir]);
				}
				else if (map[snake_head[0] + dx[dir]][snake_head[1] + dy[dir]] == 0) {
					push(snake_head[0] + dx[dir], snake_head[1] + dy[dir]);
					map[q[front % 10000][0]][q[front % 10000][1]] = 0;
					pop();
				}
				else {
					gameover = true;
					totalTime += i;
					return;
				}
			}
			else {
				gameover = true;
				totalTime += i;
				return;
			}
			i++;
		}
	}
}

void game()
{
	move(direction_change[0][0], 3);
	for (int i = 0; i < L - 1; i++)
	{
		totalTime = direction_change[i][0];
		move(direction_change[i + 1][0] - direction_change[i][0], direction_change[i][1]);
		if (gameover) return;
	}
	totalTime = direction_change[L - 1][0];
	move(0, direction_change[L - 1][1]);
}

void output()
{
	printf("%d\n", totalTime);
}

int main()
{
	init();
	input();
	game();
	output();
}
