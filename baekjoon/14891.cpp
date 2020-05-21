#include <stdio.h>
using namespace std;

int gear[4][8];
int gear_top[4];
int gear_right[4];
int gear_left[4];
bool visited[4] = {false,};
int K;

void init()
{
  gear_top[0] = gear_top[1] = gear_top[2] = gear_top[3] = 0;
  gear_right[0] = gear_right[1] = gear_right[2] = 2;
  gear_left[1] = gear_left[2] = gear_left[3] = 6;
}

void rotation(int gear_no, int rot_dir)
{
  visited[gear_no] = true;


  if(gear_no == 0) {
    if(gear[gear_no][gear_right[gear_no]] != gear[gear_no + 1][gear_left[gear_no + 1]]) {
      if(!visited[gear_no + 1])
        rotation(gear_no + 1, -rot_dir);
    }
  }
  else if(gear_no == 3) {
    if(gear[gear_no][gear_left[gear_no]] != gear[gear_no - 1][gear_right[gear_no - 1]]) {
      if(!visited[gear_no - 1])
        rotation(gear_no - 1, -rot_dir);
    }
  }
  else {
    if(gear[gear_no][gear_right[gear_no]] != gear[gear_no + 1][gear_left[gear_no + 1]]) {
      if(!visited[gear_no + 1])
        rotation(gear_no + 1, -rot_dir);
    }
    if(gear[gear_no][gear_left[gear_no]] != gear[gear_no - 1][gear_right[gear_no - 1]]) {
      if(!visited[gear_no - 1])
        rotation(gear_no - 1, -rot_dir);
    }
  }
  gear_top[gear_no] = (gear_top[gear_no] - rot_dir + 8) % 8;
  gear_left[gear_no] = (gear_left[gear_no] - rot_dir + 8) % 8;
  gear_right[gear_no] = (gear_right[gear_no] - rot_dir + 8) % 8;
}

int main()
{
  init();
  for(int i = 0; i < 4; i++)
  {
    int temp;
    scanf("%d", &temp);
    for(int j = 7; j >= 0; j--)
    {
      gear[i][j] = temp % 2;
      temp /= 10;
    }
  }

  scanf("%d", &K);

  for(int i = 0; i < K; i++)
  {
    for(int j = 0; j < 4; j++) visited[j] = false;

    int gear_no;
    int rot_dir;

    scanf("%d %d", &gear_no, &rot_dir);
    rotation(gear_no - 1, rot_dir);
  }

  int result = 0;
  for(int j = 0; j < 4; j++)
  {
    result = result + (gear[j][gear_top[j]] << j);
  }
  printf("%d\n", result);
}
