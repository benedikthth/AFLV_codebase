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

const int n = 5;
vector<int> adj[n];
vector<bool> visited(n, false);
vector<int> order;

void topsort(int u) {
    if (visited[u]) {
        return;
    }

    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }

    order.push_back(u);
}


int main() {

    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[2].push_back(3);

    for (int u = 0; u < n; u++) {
        topsort(u);
    }

    iter(it,order) {
        cout << *it << endl;
    }

    return 0;
}

