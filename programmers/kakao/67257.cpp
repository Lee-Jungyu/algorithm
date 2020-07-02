#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

long long answer = 0;

class Node {
public:
    int num = 0;
    char op = 0;
};

int get_priority(char c, vector<int> priorities) {
    if(c == '-') return priorities[0];
    else if(c == '+') return priorities[1];
    else if(c == '*') return priorities[2];
}

void perm(int cnt, vector<int> priorities, string expression)
{
    if(cnt == priorities.size()) {
        vector<Node> n_vector;
        stack<char> c_stack;
        long long result = 0;
        int sum = 0;

        for(int i = 0; i < expression.size(); i++) {
            if(expression[i] >= '0' && expression[i] <= '9') {
                sum *= 10;
                sum += expression[i] - '0';
            }
            else {
                Node n;
                n.num = sum;
                n_vector.push_back(n);
                sum = 0;
                if(c_stack.empty()) {
                    c_stack.push(expression[i]);
                }
                else {
                    if(get_priority(c_stack.top(), priorities) >= get_priority(expression[i], priorities)) {
                        while(!c_stack.empty()) {
                            if(get_priority(c_stack.top(), priorities) < get_priority(expression[i], priorities)) break;
                            Node n2;
                            n2.op = c_stack.top();
                            n_vector.push_back(n2);
                            c_stack.pop();
                        }
                        c_stack.push(expression[i]);
                    }
                    else {
                        c_stack.push(expression[i]);
                    }
                }
            }
        }

        Node n1;
        n1.num = sum;
        n_vector.push_back(n1);

        while(!c_stack.empty()) {
            Node n;
            n.op = c_stack.top();
            n_vector.push_back(n);
            c_stack.pop();
        }

        stack<long long> n_stack;
        for(int i = 0; i < n_vector.size(); i++) {
            if(n_vector[i].op == 0) {
                n_stack.push(n_vector[i].num);
            }
            else {
                long long num1, num2;
                num2 = n_stack.top(); n_stack.pop();
                num1 = n_stack.top(); n_stack.pop();

                if(n_vector[i].op == '*') {
                    long long num3 = num1 * num2;
                    n_stack.push(num3);
                }
                else if(n_vector[i].op == '+') {
                    long long num3 = num1 + num2;
                    n_stack.push(num3);
                }
                else {
                    long long num3 = num1 - num2;
                    n_stack.push(num3);
                }
            }
        }

        if(abs(n_stack.top()) > answer) {
            answer = abs(n_stack.top());
        }
        return;
    }

    for(int i = cnt; i < priorities.size(); i++) {
        swap(priorities[i], priorities[cnt]);
        perm(cnt + 1, priorities, expression);
        swap(priorities[i], priorities[cnt]);
    }
}

long long solution(string expression) {
    answer = 0;
    vector<int> priorities = {1,2,3};

    perm(0, priorities, expression);

    return answer;
}
