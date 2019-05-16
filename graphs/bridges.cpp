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

const int n = 8;
vector<int> adj[n];
vector<int> low(n), num(n, -1);
int curnum = 0;

vector<pair<int, int> > bridges;

void find_bridges(int u, int p) {
    low[u] = num[u] = curnum++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        if (num[v] == -1) {
            find_bridges(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }

        if (low[v] > num[u]) {
            bridges.push_back(make_pair(u, v));
        }
    }
}

int main() {

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(6);
    adj[1].push_back(0);
    adj[1].push_back(6);
    adj[2].push_back(0);
    adj[2].push_back(6);
    adj[3].push_back(7);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(3);
    adj[6].push_back(7);
    adj[6].push_back(2);
    adj[6].push_back(0);
    adj[6].push_back(1);
    adj[7].push_back(6);
    adj[7].push_back(3);

    for (int u = 0; u < n; u++) {
        if (num[u] == -1) {
            find_bridges(u, -1);
        }
    }

    iter(it,bridges) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

