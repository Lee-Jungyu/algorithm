#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate90(vector<vector<int> >v) {
    vector<vector<int>> temp;
    temp.assign(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            temp[i][j] = v[v.size() - 1 - j][i];
        }
    }

    return temp;
}

bool findKeyPoint(vector<vector<int>> key, vector<vector<int>> board, int r, int c)
{
    for(int i = 0; i < key.size(); i++)
    {
        for(int j = 0; j < key.size(); j++)
        {
            board[i + r][j + c] += key[i][j];
        }
    }

    for(int i = key.size() - 1; i < board.size() - key.size() + 1; i++)
    {
        for(int j = key.size() - 1; j < board.size() - key.size() + 1; j++)
        {
            if(board[i][j] != 1) return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    vector<vector<int>> board;

    int key_size = key.size();
    int lock_size = lock.size();

    for(int i = 0; i < 2 * key_size + lock_size - 2; i++)
    {
        vector<int> v;
        for(int j = 0; j < 2 * key_size + lock_size - 2; j++)
        {
            v.push_back(0);
        }
        board.push_back(v);
    }

    for(int i = 0; i < lock_size; i++)
    {
        for(int j = 0; j < lock_size; j++)
        {
            board[i + key_size - 1][j + key_size - 1] = lock[i][j];
        }
    }

    for(int i = 0; i < board.size() - key.size() + 1; i++)
    {
        for(int j = 0; j < board.size() - key.size() + 1; j++)
        {
            if(findKeyPoint(key, board, i, j)) {
                return true;
            }
        }
    }
    

    for(int i = 0; i < 3; i++)
    {
        key = rotate90(key);
        for(int i = 0; i < board.size() - key.size() + 1; i++)
        {
            for(int j = 0; j < board.size() - key.size() + 1; j++)
            {
                if(findKeyPoint(key, board, i, j)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}
