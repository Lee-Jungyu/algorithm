#include <string>
using namespace std;

int map[11][11][2];
int curr_x, curr_y;
int solution(string dirs) {
    int answer = 0;
    curr_x = curr_y = 5;
    
    for(int i = 0; i < dirs.length(); i++) {
        if(dirs[i] == 'U') {
            //up
            if(curr_x == 0) continue;
            if(map[curr_x - 1][curr_y][0] == 0) {
                map[curr_x - 1][curr_y][0] = 1;
                answer++;
            }
            curr_x--;
        }
        else if(dirs[i] == 'D') {
            //down
            if(curr_x == 10) continue;
            if(map[curr_x][curr_y][0] == 0) {
                map[curr_x][curr_y][0] = 1;
                answer++;
            }
            curr_x++;
        }
        else if(dirs[i] == 'R') {
            //right
            if(curr_y == 10) continue;
            if(map[curr_x][curr_y][1] == 0) {
                map[curr_x][curr_y][1] = 1;
                answer++;
            }
            curr_y++;
        }
        else {
            //left
            if(curr_y == 0) continue;
            if(map[curr_x][curr_y - 1][1] == 0) {
                map[curr_x][curr_y - 1][1] = 1;
                answer++;
            }
            curr_y--;
        }
    }
    return answer;
}
