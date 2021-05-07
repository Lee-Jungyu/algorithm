#include <string>
#include <vector>

using namespace std;

int rotate(vector<int> query, vector<vector<int>>& arr) {
    vector<int> tmp;
    
    int startX = query[0] - 1;
    int startY = query[1] - 1;
    int endX = query[2] - 1;
    int endY = query[3] - 1;
    
    // store top side values
    for(int j = startY; j < endY; j++) {
        tmp.push_back(arr[startX][j]);
    }
    
    // store right side values
    for(int i = startX; i < endX; i++) {
        tmp.push_back(arr[i][endY]);
    }
    
    // store bottom side values
    for(int j = endY; j > startY; j--) {
        tmp.push_back(arr[endX][j]);
    }
    
    // store left side values
    for(int i = endX; i > startX; i--) {
        tmp.push_back(arr[i][startY]);
    }
    
    int min_val = 100000;
    int tmp_idx = 0;
    
    // edit top side values
    for(int j = startY + 1; j <= endY; j++) {
        if(min_val >= tmp[tmp_idx]) min_val = tmp[tmp_idx];
        arr[startX][j] = tmp[tmp_idx++];
    }
    
    // edit right side values
    for(int i = startX + 1; i <= endX; i++) {
        if(min_val >= tmp[tmp_idx]) min_val = tmp[tmp_idx];
        arr[i][endY] = tmp[tmp_idx++];
    }
    
    // edit bottom side values
    for(int j = endY - 1; j >= startY; j--) {
        if(min_val >= tmp[tmp_idx]) min_val = tmp[tmp_idx];
        arr[endX][j] = tmp[tmp_idx++];
    }
    
    // edit left side values
    for(int i = endX - 1; i >= startX; i--) {
        if(min_val >= tmp[tmp_idx]) min_val = tmp[tmp_idx];
        arr[i][startY] = tmp[tmp_idx++];
    }
    
    return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows, vector<int> (columns,0));
    
    // init 2d array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            arr[i][j] = i * columns + j + 1;
        }
    }
    
    // rotate
    for(int i = 0; i < queries.size(); i++) {
        // rotate 2d array and push the min value into answer array
        answer.push_back(rotate(queries[i], arr));
    }
    
    return answer;
}
