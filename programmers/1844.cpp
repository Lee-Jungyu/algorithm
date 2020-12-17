#include<vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> dist_map;
vector<vector<int>> maps;

struct Point {
    int x;
    int y;
};

class Queue {
    
private:
    vector<Point> data;
    int front = 0;
    int rear = 0;
    
public:
    bool isEmpty() {
        return front == rear;
    }
    
    void push(Point p) {
        data.push_back(p);
        rear++;
    }
    
    Point pop() {
        return data[front++];
    }
};

bool checkValidLocation(int tmp_x, int tmp_y, int row_size, int col_size) {
    return tmp_x >= 0 && tmp_x < row_size && tmp_y >= 0 && tmp_y < col_size;
}

bool checkVisitedLocation(int tmp_x, int tmp_y) {
    return dist_map[tmp_x][tmp_y] > 0;
}

bool checkWallLocation(int tmp_x, int tmp_y) {
    return maps[tmp_x][tmp_y] == 1;
}

int solution(vector<vector<int> > map) {
    
    Queue q;
    int row_size = map.size();
    int col_size = map[0].size();
    
    dist_map.resize(row_size, vector<int> (col_size, 0));
    maps.assign(map.begin(), map.end());
    
    Point p;
    p.x = 0;
    p.y = 0;
    
    q.push(p);
    dist_map[p.x][p.y] = 1;
    
    while(!q.isEmpty()) {
        Point curr_point = q.pop();
        
        int curr_x = curr_point.x;
        int curr_y = curr_point.y;
        int curr_cnt = dist_map[curr_x][curr_y];
        
        for(int i = 0; i < 4; i++) {
            int tmp_x = curr_x + dx[i];
            int tmp_y = curr_y + dy[i];
            int tmp_cnt = curr_cnt + 1;
            
            //check temp location is in map
            if(!checkValidLocation(tmp_x, tmp_y, row_size, col_size)) continue;
            //check temp location is wall
            if(!checkWallLocation(tmp_x, tmp_y)) continue;
            //check temp location is visited location
            if(checkVisitedLocation(tmp_x, tmp_y)) continue;
            
            Point tmp_point;
            tmp_point.x = tmp_x;
            tmp_point.y = tmp_y;
            
            q.push(tmp_point);
            dist_map[tmp_x][tmp_y] = tmp_cnt;
        }
        
    }
    
    
    if(dist_map[row_size - 1][col_size - 1] == 0) return -1;
    
    return dist_map[row_size - 1][col_size - 1];
}
