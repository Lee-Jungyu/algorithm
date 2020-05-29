#include <stdio.h>
using namespace std;

int n;
int inorder[100001];
int postorder[100001];

void makeTree(int in_start, int in_end, int post_start, int post_end)
{
    if(in_start > in_end) return;
    int root_data = postorder[post_end];
    printf("%d ", root_data);

    int left_size = 0;
    int right_size = 0;
    for(int i = in_start; i < in_end; i++) {
        if(inorder[i] == root_data) break;
        left_size++;
    }
    right_size = post_end - post_start - left_size;

    makeTree(in_start, in_start + left_size - 1, post_start, post_start + left_size - 1);
    makeTree(in_start + left_size + 1, in_end, post_start + left_size, post_end - 1);
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int root_data = postorder[n - 1];

    makeTree(0, n - 1, 0, n - 1);
}
