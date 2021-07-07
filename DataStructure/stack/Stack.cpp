#include <iostream>
using namespace std;

class Stack {
private:
    int _top = -1;
    int _max;
    int* _stack;
public:
    Stack() {
        _max = 10; 
        _stack = new int[_max];
    }

    Stack(int size) {
        if(size < 1) _max = 1;

        _max = size; 
        _stack = new int[_max];
    }

    ~Stack() {
        delete[] _stack;
    }

    void push(int data) {
        if(isFull()) {
            int* tmp = new int[_max * 2];
            for(int i = 0; i < _max; i++) {
                tmp[i] = _stack[i];
            }

            int* deleteStack = _stack;
            _stack = tmp;

            delete[] deleteStack;
            _max *= 2;
        }

        _stack[++_top] = data;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Empty\n";
            return;
        }

        _top--;
    }

    int top() {
        if(isEmpty()) {
            cout << "Empty\n";
            return -1;
        }
        return _stack[_top];
    }

    int getSize() {
        return _top + 1;
    }

    bool isEmpty() {
        if(_top == -1) return true;
        else return false;
    }

    bool isFull() {
        if(_top == _max - 1) return true;
        else return false;
    }
};

int main()
{
    Stack stack;
    
    for(int i = 0; i < 15; i++) {
        stack.push(i);
        cout << "push: " << stack.top() << endl;
    }

    cout << "size: " << stack.getSize() << endl;

    while(!stack.isEmpty()) {
        cout << "pop: " << stack.top() << endl;
        stack.pop();
    }

    return 0;
}
