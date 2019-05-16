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

struct flow_network {

    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge*> back(n, (edge*)0);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};

map<string,int> tshirt_num;
vector<string> tshirt_sizes = {
    "XS", "S", "M", "L", "XL", "XXL"
};

int main() {
    for (int i = 0; i < tshirt_sizes.size(); i++) {
        tshirt_num[tshirt_sizes[i]] = i;
    }


    int ts;
    cin >> ts;

    rep(t,0,ts) {
        int m, n;
        cin >> m >> n;

        int SOURCE = 0,
            SINK = 1,
            VOLUNTEER = 2,
            TSHIRT = VOLUNTEER + n,
            CNT = TSHIRT + 6;

        flow_network G(CNT);

        rep(i,0,n) {
            G.add_edge(SOURCE, VOLUNTEER + i, 1);
        }
        rep(i,0,6) {
            G.add_edge(TSHIRT + i, SINK, m / 6);
        }

        rep(i,0,n) {
            string a, b;
            cin >> a >> b;

            G.add_edge(VOLUNTEER + i, TSHIRT + tshirt_num[a], 1);
            G.add_edge(VOLUNTEER + i, TSHIRT + tshirt_num[b], 1);
        }

        if (G.max_flow(SOURCE, SINK) == n) {
            cout << "YES" << endl;

            rep(i,0,n) {
                for (int j = 0; j < G.adj[VOLUNTEER + i].size(); j++) {
                    if (G.adj[VOLUNTEER + i][j]->forward && G.adj[VOLUNTEER + i][j]->rev->cap == 1) {
                        cout << i+1 << " " << tshirt_sizes[G.adj[VOLUNTEER + i][j]->v - TSHIRT] << endl;
                    }
                }
            }

        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

