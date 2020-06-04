#include <string>
#include <vector>

using namespace std;

int cntArray[10001];
class Trie
{
public:
    Trie() {
        for(int i = 0; i < 27; i++)
            subTrie[i] = NULL;
    }
    Trie(char data) {
        this->data = data;

        for(int i = 0; i < 27; i++)
            subTrie[i] = NULL;
    }

    void insertNode(string str)
    {
        Trie* triePoint = this;
        
        for(int i = 0; i < str.length(); i++)
        {
            if(triePoint->subTrie[str[i] - 'a'] == NULL) {
                triePoint->subTrie[str[i] - 'a'] = new Trie(str[i]);
            }
            triePoint = triePoint->subTrie[str[i] - 'a'];
            triePoint->cnt++;
        }
        
        if(triePoint->subTrie[26] == NULL) {
            triePoint->subTrie[26] = new Trie('.');
        }
    }

    int findWordOrder(Trie* curr, int deep)
    {
        int result = 0;
        if(deep == 0) {
            if(curr->subTrie[26] != NULL) { return 1; }
            else { return 0; }
        }

        for(int i = 0; i < 26; i++)
        {
            if(curr->subTrie[i] != NULL)
                result += findWordOrder(curr->subTrie[i], deep - 1);
        }

        return result;
    }

    int findWords(string str)
    {
        int size = str.length();
        
        Trie* triePoint = this;

        for(int i = 0; i < size; i++)
        {
            if(str[i] != '?') {
                if(triePoint->subTrie[str[i] - 'a']) {
                    triePoint = triePoint->subTrie[str[i] - 'a'];
                }
                else {
                    return 0;
                }
            }
            else {
                return findWordOrder(triePoint, size - i);
            }
        }
    }


    Trie *subTrie[27];
    char data;
    int cnt = 0;
};

string getBackString(string str)
{
    string result = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    Trie *rootTrie = new Trie();
    Trie *backRootTrie = new Trie();

    for(int i = 0; i < words.size(); i++)
    {
        cntArray[words[i].length()]++;
        rootTrie->insertNode(words[i]);
        backRootTrie->insertNode(getBackString(words[i]));
    }

    for(int i = 0; i < queries.size(); i++)
    {
        if(queries[i][0] == '?' && queries[i][queries[i].length() - 1] == '?') answer.push_back(cntArray[queries[i].length()]);
        else if(queries[i][0] == '?') {
            answer.push_back(backRootTrie->findWords(getBackString(queries[i])));
        }
        else if (queries[i][0] != '?') {
            answer.push_back(rootTrie->findWords(queries[i].c_str()));
        }
    }

    return answer;
}

//정확성 100%
//효율성 60%
