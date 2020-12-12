#include <vector>
#include <string>
#define MIN_VALUE 0x80000000
using namespace std;

bool visited[100];
int order[100];

vector<int> operand_vector;
vector<string> operator_vector;

int getResult(int operator_cnt) {
    vector<int> parent_vector(operand_vector.size());
    vector<int> calculate_vector;
    calculate_vector.assign(operand_vector.begin(), operand_vector.end());
    
    for(int i = 0; i < parent_vector.size(); i++)
        parent_vector[i] = i;
    
    for(int i = 0; i < operator_cnt; i++) {
        int idx = order[i];
        if(operator_vector[idx] == "+") {
            
            //find parent
            int parent_idx = idx;
            while(parent_vector[parent_idx] != parent_idx) {
                parent_idx = parent_vector[parent_idx];
            }
            
            calculate_vector[parent_idx] += calculate_vector[idx + 1];
            calculate_vector[idx + 1] = 0;
            parent_vector[idx + 1] = idx;
        }
        else {
            int parent_idx = idx;
            while(parent_vector[parent_idx] != parent_idx) {
                parent_idx = parent_vector[parent_idx];
            }
            
            calculate_vector[parent_idx] -= calculate_vector[idx + 1];
            calculate_vector[idx + 1] = 0;
            parent_vector[idx + 1] = idx;
        }
    }
    
    return calculate_vector[0];
}

int setOrder(int operator_cnt, int visited_cnt, int arr_idx) {
    visited_cnt++;
    int result = MIN_VALUE;
    
    if(operator_cnt == visited_cnt) {
        result = getResult(operator_cnt);
        return result;
    }
    
    for(int i = 0; i < operator_cnt; i++) {
        if(!visited[i]) {
            visited[i] = true;
            order[visited_cnt] = i;
            int tmp = setOrder(operator_cnt, visited_cnt, i);
            result = result > tmp ? result : tmp;
            visited[i] = false;
        }
    }
    
    return result;
}

int str2int(string str) {
    int sum = 0;
    for(int i = 0; i < str.length(); i++) {
        sum *= 10;
        sum += str[i] - '0';
    }
    
    return sum;
}

int solution(vector<string> arr)
{
    int operand_cnt = arr.size() / 2 + 1;
    int operator_cnt = arr.size() / 2;
    int answer = MIN_VALUE;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == "+" || arr[i] == "-") operator_vector.push_back(arr[i]);
        else operand_vector.push_back(str2int(arr[i]));
    }
    
    for(int i = 0; i < operator_cnt; i++) {
        visited[i] = true;
        order[0] = i;
        int tmp = setOrder(operator_cnt, 0, i);
        answer = answer > tmp ? answer : tmp; 
        visited[i] = false;
    }
    
    return answer;
}

//정확성 100%
//
