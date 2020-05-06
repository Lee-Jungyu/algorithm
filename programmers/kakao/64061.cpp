#include <string>
#include <vector>

using namespace std;
int s[10001];
int top = 0;

void push(int n)
{
    s[top++] = n;
}

void pop()
{
    top--;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i = 0; i < moves.size(); i++)
    {
        int num = moves.at(i);
        
        for(int j = 0; j < board.size(); j++) {
            if(board[j][num - 1]) {
                int selectedItem = board[j][num - 1];
                if(top == 0) {
                    push(selectedItem);
                }
                else {
                    if(s[top - 1] != selectedItem) {
                        push(selectedItem);
                    }
                    else {
                        pop();
                        answer += 2;
                    }
                }
                board[j][num - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}
