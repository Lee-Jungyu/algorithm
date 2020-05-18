#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[8] = {false, };
vector<vector<int>> result;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

void dfs(int size, int cnt, int idx, vector<vector<string>> relation, vector<int> v)
{
    v.push_back(idx);
    
    if(size == cnt) {
        for(int i = 0; i < relation.size(); i++)
        {
            for(int j = i + 1; j < relation.size(); j++)
            {
                int flag = 0;
                for(int k = 0; k < v.size(); k++)
                {
                    string str1 = relation[i][v[k]];
                    string str2 = relation[j][v[k]];
                    
                    if(str1 == str2) {
                        flag++;
                    }
                }
                if(flag == v.size()) {
                    return;
                }
            }
        }
        
        result.push_back(v);
        return;
    }
    
    for(int i = idx; i < relation[0].size(); i++)
    {
        if(!visited[i]) {
            visited[i] = true;
            dfs(size, cnt + 1, i, relation, v);
            visited[i] = false;
        }
    }
}

int solution(vector<vector<string>> relation) {
    
    vector<int> v;
    
    for(int i = 1; i <= relation[0].size(); i++)
    {
        for(int j = 0; j <= relation[0].size() - i; j++)
        {
            visited[j] = true;
            dfs(i, 1, j, relation, v);
            visited[j] = false;
        }
    }
    
    
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = i + 1; j < result.size(); j++)
        {
            int flag = 0;
            for(int k = 0; k < result[i].size(); k++)
            {
                for(int l = 0; l < result[j].size(); l++)
                {
                    int i1 = result[i][k];
                    int i2 = result[j][l];
                    
                    if(i1 == i2) {
                        flag++;
                        break;
                    }
                }
            }
            
            if(flag == result[i].size()) {
                result.erase(result.begin() + j);
                j--;
            }
        }
    }
    
    return result.size();
}
