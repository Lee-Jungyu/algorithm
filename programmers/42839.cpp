#include <string>
#include <vector>

using namespace std;

bool visited[7] = {false, };
bool visited_num[10000000] = {false,};
bool not_prime_number[10000000] = {false,};
int result = 0;

void dfs(int size, int cnt, int num, string numbers, int sum)
{
    sum *= 10;
    sum += num;
    
    if(cnt == size) {
        if(visited_num[sum]) return;
        
        visited_num[sum] = true;
        if(!not_prime_number[sum]) result++;
        return;
    }
    
    for(int j = 0; j < numbers.length(); j++)
    {
        if(!visited[j])
        {
            visited[j] = true;
            int _num = numbers[j] - '0';
            dfs(size, cnt + 1, _num, numbers, sum);
            visited[j] = false;
        }
    }
}

void make_prime_number()
{
    not_prime_number[0] = not_prime_number[1] = true;
    for(int i = 2; i < 10000000 ; i++) {
        if(not_prime_number[i]) continue;
        for(int j = 2 * i; j < 10000000; j += i) {
            not_prime_number[j] = true;
        }
    }
}

int solution(string numbers) {
    
    make_prime_number();
    for(int i = 1; i <= numbers.length(); i++) {
        for(int  j = 0; j < numbers.length(); j++) {
            visited[j] = true;
            int num = numbers[j] - '0';
            dfs(i, 1, num, numbers, 0);
            visited[j] = false;
        }
    }
    
    return result;
}
