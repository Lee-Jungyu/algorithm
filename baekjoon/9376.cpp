#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int tc;
int h, w;
char map[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int,int> > thief_pose;
vector<pair<int, int> > door_pose;
queue<pair<int,int> > q;
int bfs_map[102][102][3];

int result = 99999;

bool check_map(int x, int y)
{
  if(x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1) return true;
  return false;
}

void bfs(int i, int j, int type)
{
  for(int a = 0; a < h + 2; a++)
  {
    for(int b = 0; b < w + 2; b++)
    {
      bfs_map[a][b][type] = 99999;
    }
  }

  q.push(make_pair(i,j));
  
  bfs_map[i][j][type] = 0;


  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int cnt = bfs_map[x][y][type];

    q.pop();
    for(int n = 0; n < 4; n++)
    {
      int xx = x + dx[n];
      int yy = y + dy[n];

      if(check_map(xx,yy) && map[xx][yy] != '*') {
        if(map[xx][yy] == '#' && bfs_map[xx][yy][type] > cnt + 1)
        {
          bfs_map[xx][yy][type] = cnt + 1;
          q.push(make_pair(xx,yy));
        }
        else if(map[xx][yy] != '#' && bfs_map[xx][yy][type] > cnt) {
          bfs_map[xx][yy][type] = cnt;
          q.push(make_pair(xx,yy));
        }
      }
    }

  }
}

int main()
{
  cin >> tc;
  while(tc--)
  {
    cin >> h >> w;

    door_pose.erase(door_pose.begin(), door_pose.end());
    thief_pose.erase(thief_pose.begin(), thief_pose.end());

    for(int i = 1; i <= h; i++)
    {
      string str;
      cin >> str;
      for(int j = 1; j <= w; j++)
      {
        map[i][j] = str[j - 1];
        if(map[i][j] == '#') door_pose.push_back(make_pair(i,j));
        if(map[i][j] == '$') thief_pose.push_back(make_pair(i,j));
        
      }
    }

    for(int i = 0; i < h + 2; i++)
    {
      map[i][0] = '.';
      map[i][w+1] = '.';
    }

    for(int j = 0; j < w + 2; j++)
    {
      map[0][j] = '.';
      map[h+1][j] = '.';
    }
    
    bfs(thief_pose[0].first, thief_pose[0].second, 0);
    bfs(thief_pose[1].first, thief_pose[1].second, 1);
    bfs(0, 0, 2);

    int min_value = 99999;
    for(int i = 0; i < door_pose.size(); i++)
    {
      int value = 0;
      for(int j = 0; j < 3; j++)
      {
        value += bfs_map[door_pose[i].first][door_pose[i].second][j];
      }
      if(value - 2 < min_value) min_value = value - 2;
    }

      if(bfs_map[0][0][0] + bfs_map[0][0][1] + bfs_map[0][0][2] == 0) min_value = 0;

    cout << min_value << endl;
  }
}
