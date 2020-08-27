#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Tree {
public:
    int x;
    int y;
    int data;
    
    Tree* leftChild;
    Tree* rightChild;
    
    vector<int> preOrderVector;
    vector<int> postOrderVector;
    
    Tree() {
        leftChild = NULL;
        rightChild = NULL;
    }
    Tree(int data) {
        this->data = data;
        leftChild = NULL;
        rightChild = NULL;
    }
    ~Tree() {
        if(this->leftChild != NULL) {
            delete leftChild;
            leftChild = NULL;
        }
        if(this->rightChild != NULL) {
            delete rightChild;
            rightChild = NULL;
        }
    }
    
    vector<int> visitPreOrder() {
        preOrderVector.push_back(this->data);
        
        preOrder(this->leftChild);
        preOrder(this->rightChild);
        
        return preOrderVector;
    }
    
    vector<int> visitPostOrder() {
        postOrder(this->leftChild);
        postOrder(this->rightChild);
        
        postOrderVector.push_back(this->data);
        
        return postOrderVector;
    }
    
    void preOrder(Tree* currPtr) {
        if(currPtr == NULL) return;
        preOrderVector.push_back(currPtr->data);
        preOrder(currPtr->leftChild);
        preOrder(currPtr->rightChild);
    }
    
    void postOrder(Tree* currPtr) {
        if(currPtr == NULL) return;
        postOrder(currPtr->leftChild);
        postOrder(currPtr->rightChild);
        postOrderVector.push_back(currPtr->data);
    }
};

bool cmp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    else
        return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<vector<int>> nodeinfo_num(nodeinfo.size());
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo_num[i].push_back(nodeinfo[i][0]);
        nodeinfo_num[i].push_back(nodeinfo[i][1]);
        nodeinfo_num[i].push_back(i + 1);
    }
    
    sort(nodeinfo_num.begin(), nodeinfo_num.end(), cmp);
    
    Tree* root = new Tree(nodeinfo_num[0][2]);
    root->x = nodeinfo_num[0][0];
    root->y = nodeinfo_num[0][1];
    
    for(int i = 1; i < nodeinfo_num.size(); i++) {
        Tree* currParentPtr = root;
        Tree* currPtr = root;
        bool left = true;
        while(currPtr) {
            currParentPtr = currPtr;
            if(nodeinfo_num[i][0] < currPtr->x) {
                currPtr = currPtr->leftChild;
                left = true;
            }
            else {
                currPtr = currPtr->rightChild;
                left = false;
            }
        }
        
        if(left) {
            currPtr = new Tree(nodeinfo_num[i][2]);
            currPtr->x = nodeinfo_num[i][0];
            currPtr->y = nodeinfo_num[i][1];
            
            currParentPtr->leftChild = currPtr;
        }
        else {
            currPtr = new Tree(nodeinfo_num[i][2]);
            currPtr->x = nodeinfo_num[i][0];
            currPtr->y = nodeinfo_num[i][1];
            
            currParentPtr->rightChild = currPtr;
        }
    }
    
    answer.push_back(root->visitPreOrder());
    answer.push_back(root->visitPostOrder());
    
    delete root;
    
    return answer;
}
