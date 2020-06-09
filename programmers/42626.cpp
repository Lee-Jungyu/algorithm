#include <string>
#include <vector>

using namespace std;

long long min_heap[1000001];
int heap_size = 0;

void push_heap(long long n)
{
    heap_size++;
    int idx = heap_size;
    while(idx != 1 && min_heap[idx / 2] > n) {
        min_heap[idx] = min_heap[idx / 2];
        idx /= 2;
    }
    min_heap[idx] = n;
}

void pop_heap()
{
    if(heap_size == 0) return;

    int idx = 1;
    long long n = min_heap[heap_size--];
    int next_idx = idx;
    while(idx * 2 <= heap_size) {
        if(idx * 2 == heap_size) next_idx = heap_size;
        else next_idx = min_heap[idx * 2] < min_heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;

        if(n > min_heap[next_idx]) min_heap[idx] = min_heap[next_idx];
        else break;

        idx = next_idx;
    }

    min_heap[idx] = n;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    if(K == 0) return 0;

    for(int i = 0; i < scoville.size(); i++) {
        push_heap(scoville[i]);
    }

    while(min_heap[1] < K) {
        if(heap_size == 1 && min_heap[1] < K) {
            answer = -1; 
            break;
        }

        long long s1 = min_heap[1];
        pop_heap();

        long long s2 = min_heap[1] * 2;
        pop_heap();

        push_heap(s1 + s2);

        answer++;
    }
    return answer;
}
//min heap
