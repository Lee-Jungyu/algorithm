#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* _heap;
    int _max;
    int _size;

    void sizeUpHeap() {
        int* tmp = new int[_max * 2];
        for(int i = 0; i < _max; i++) {
            tmp[i] = _heap[i];
        }

        int* delHeap = _heap;
        _heap = tmp;
        _max *= 2;

        delete[] delHeap;
    }

public:
    MaxHeap() {
        _max = 10;
        _heap = new int[_max];
        _size = 0;
    }

    MaxHeap(int _max) {
        this->_max = _max;
        if(_max < 2) this->_max = 2;
        _heap = new int[this->_max];
        _size = 0;
    }

    ~MaxHeap() {
        delete[] _heap;
    }

    void push(int data) {
        if(isFull()) sizeUpHeap();

        _heap[++_size] = data;

        int idx = _size;
        while(idx > 1) {
            if(_heap[idx] > _heap[idx / 2]) {
                swap(_heap[idx], _heap[idx / 2]);
            }
            else break;

            idx /= 2;
        }
    }

    void pop() {
        if(isEmpty()) {
            cout << "Empty\n";
            return;
        }

        swap(_heap[1], _heap[_size--]);
        
        int idx = 1;
        while(idx <= _size / 2) {
            int nextIdx = 1;
            if(idx * 2  == _size) nextIdx = idx * 2;
            else nextIdx = _heap[idx * 2] > _heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
            
            if(_heap[idx] < _heap[nextIdx]) swap(_heap[idx], _heap[nextIdx]);
            else break;

            idx = nextIdx;
        }
    }

    int root() {
        if(isEmpty()) {
            cout << "Empty\n";
            return -1;
        }

        return _heap[1];
    }

    int size() {
        return _size;
    }

    bool isEmpty() {
        return _size == 0;
    }

    bool isFull() {
        return _size == _max - 1;
    }
};

int main()
{
    MaxHeap maxHeap;

    for(int i = 0; i < 25; i++) {
        maxHeap.push(i);
    }

    cout << "size: " << maxHeap.size() << endl;
    
    while(!maxHeap.isEmpty()) {
        cout << "pop: " << maxHeap.root() << endl;
        maxHeap.pop();
    }
}
