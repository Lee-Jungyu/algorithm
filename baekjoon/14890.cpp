#include <stdio.h>

using namespace std;

int N, L;
int map[100][100];

bool checkRow(int idx)
{
  bool visited[100] = {false,};
  int curr = map[idx][0];
  int len = 0;
  int dir = 0;
  for(int i = 0; i < N; i++)
  {
    if(map[idx][i] == curr) {
      if(len != 0) return false;
      continue;
    }
    if(map[idx][i] >= curr + 2 || map[idx][i] <= curr - 2) return false;
    if((map[idx][i] == curr - 1 || map[idx][i] == curr + 1)) {
      if(map[idx][i] == curr - 1) {
        if(dir == 1) return false;
        if(dir == 0) dir = -1;
        if(dir == -1) {
          if(visited[i]) return false;
          visited[i] = true;
          len++;

          if(len == L) {
            curr = map[idx][i];
            len = 0;
            dir = 0;
          }
        }
      }
      else {
        if(dir == -1) return false;
        if(dir == 0) dir = 1;
        if(dir == 1) {
          if(i < L) return false;
          for(int j = i - 1; j >= 0; j--) {
            if(visited[j]) return false;
            visited[j] = true;
            if(map[idx][j] != curr) return false;
            len++;
            if(len == L) {
              curr = map[idx][i];
              len = 0;
              dir = 0;
              break;
            }
          }
        }
      }
    }
  }

  if(len != 0) return false;

  return true;
}

bool checkCol(int idx)
{
  bool visited[100] = {false,};
  int curr = map[0][idx];
  int len = 0;
  int dir = 0;
  for(int i = 0; i < N; i++)
  {
    if(map[i][idx] == curr) {
      if(len != 0) return false;
      continue;
    }
    if(map[i][idx] >= curr + 2 || map[i][idx] <= curr - 2) return false;
    if((map[i][idx] == curr - 1 || map[i][idx] == curr + 1)) {
      if(map[i][idx] == curr - 1) {
        if(visited[i]) return false;
        visited[i] = true;
        if(dir == 1) return false;
        if(dir == 0) dir = -1;
        if(dir == -1) {
          len++;
          if(len == L) {
            curr = map[i][idx];
            len = 0;
            dir = 0;
          }
        }
      }
      else {
        if(dir == -1) return false;
        if(dir == 0) dir = 1;
        if(dir == 1) {
          if(i < L) return false;
          for(int j = i - 1; j >= 0; j--) {
            if(visited[j]) return false;
            visited[j] = true;
            if(map[j][idx] != curr) return false;

            len++;
            if(len == L) {
              curr = map[i][idx];
              len = 0;
              dir = 0;
              break;
            }
          }
        }
      }
    }
  }
  if(len != 0) return false;

  return true;
}

int main()
{
  int result = 0;
  scanf("%d %d", &N, &L);
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      scanf("%d", &map[i][j]);
    }
  }

  for(int i = 0; i < N; i++)
  {
    if(checkRow(i)) {
      result++;
    }
    if(checkCol(i)) {
      result++;
    }
  }

  printf("%d", result);
}
