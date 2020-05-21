#include<stdio.h>
using namespace std;

int N, M;
bool road[1001][1001] = {{false,},};
int map[1001][1001] = {{0,},};
int value_map[1001][1001] = {{0,}};
const int q_size = 10000000;
int q[q_size][2];
int front = 0;
int rear = 0;

int bfs(int source, int destination)
{
  q[front % q_size][0] = source;
  q[front % q_size][1] = 0;
  front++;

  while(front != rear) {
    int src = q[rear % q_size][0];
    int val = q[rear % q_size][1];
    rear++;

    for(int i = 1; i <= N; i++)
    {
      if(!road[src][i]) continue;

      if(value_map[source][i] == 0) {
        value_map[source][i] = val + map[src][i];

        q[front % q_size][0] = i;
        q[front % q_size][1] = value_map[source][i];
        front++;
      }
      else if(value_map[source][i] > val + map[src][i]) {
        value_map[source][i] = val + map[src][i];

        q[front % q_size][0] = i;
        q[front % q_size][1] = value_map[source][i];
        front++;
      }
    }

  }
  return value_map[source][destination];
}

int main()
{
  int source, destination;

  scanf("%d", &N);
  scanf("%d", &M);

  for(int i = 0; i < M; i++)
  {
    int tmp_source, tmp_destination, tmp_value;
    scanf("%d %d %d", &tmp_source, &tmp_destination, &tmp_value);
    
    if(map[tmp_source][tmp_destination] > tmp_value || !road[tmp_source][tmp_destination])
      map[tmp_source][tmp_destination] = tmp_value;
    
    road[tmp_source][tmp_destination] = true;
  }

  scanf("%d %d", &source, &destination);

  int result;
  result = bfs(source, destination);
  printf("%d\n", result);
}
