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
vector<bool> incomp(n, false);
int curnum = 0;

vi numcomp(n, -1);
vector<vi> component(n);
int components = 0;

stack<int> comp;

void scc(int u) {

    comp.push(u);
    incomp[u] = true;

    low[u] = num[u] = curnum++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            scc(v);
            low[u] = min(low[u], low[v]);
        } else if (incomp[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]) {
        while (true) {
            int cur = comp.top();
            comp.pop();
            incomp[cur] = false;

            numcomp[cur] = components;
            component[components].push_back(cur);

            if (cur == u) {
                break;
            }
        }

        components++;
    }
}

int main() {

    adj[0].push_back(2);
    adj[0].push_back(1);
    adj[2].push_back(6);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[6].push_back(1);
    adj[6].push_back(0);
    adj[7].push_back(6);
    adj[7].push_back(3);

    for (int i = 0; i < n; i++) {
        if (num[i] == -1) {
            scc(i);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << "vertex " << i << " is in component " << numcomp[i] << endl;
    // }

    // for (int i = 0; i < components; i++) {
    //     cout << "component " << i << ": ";
    //     for (int j = 0; j < component[i].size(); j++) {
    //         cout << component[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < components; i++) {
        bool tourist_safe = true;
        for (int j = 0; j < component[i].size(); j++) {
            int u = component[i][j];
            for (int k = 0; k < adj[u].size(); k++) {
                int v = adj[u][k];
                if (numcomp[v] != i) {
                    tourist_safe = false;
                    break;
                }
            }
            if (!tourist_safe) {
                break;
            }
        }

        if (tourist_safe) {
            for (int j = 0; j < component[i].size(); j++) {
                int u = component[i][j];
                cout << u << endl;
            }
        }
    }

    return 0;
}

