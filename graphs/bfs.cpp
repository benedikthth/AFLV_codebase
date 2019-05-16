#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;



int main() {

    const int n = 5;

    vector<int> adj[n];
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(2);

    int A = 1,
        B = 2;

    vector<int> dist(n, -1),
                parent(n, -1);

    queue<int> Q;
    Q.push(A);
    dist[A] = 0;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                Q.push(v);
                dist[v] = 1 + dist[u];
                parent[v] = u;
            }
        }
    }

    printf("%d\n", dist[B]);

    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << dist[i] << endl;
    // }

    if (parent[B] != -1) {
        stack<int> path;
        path.push(B);
        while (path.top() != A) {
            int u = path.top();
            path.push(parent[u]);
        }

        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    } else {
        cout << "no path" << endl;
    }

    return 0;
}

