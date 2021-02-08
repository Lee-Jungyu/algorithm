#include <iostream>
using namespace std;

int parent[1000001];

int find_parent(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find_parent(parent[a]);
}

bool check_set(int a, int b) {
    if(find_parent(a) == find_parent(b)) return true;
    return false;
}

void union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a != b)
        parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;

        if(o) {
            bool check = check_set(a, b);
            if(check) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if(a == b) continue;
            union_set(a, b);
        }
    }
}
