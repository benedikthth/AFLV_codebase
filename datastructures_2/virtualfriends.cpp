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

struct union_find {
    vector<int> parent, count;
    union_find(int n) {
        parent = vector<int>(n);
        count = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y) {
        int xroot = find(x),
            yroot = find(y);
        if (xroot == yroot) {
            return;
        }
        parent[xroot] = yroot;
        count[yroot] += count[xroot];
    }

    int size_of_component(int x) {
        return count[find(x)];
    }
};

int main() {
    int ts;
    cin >> ts;

    rep(t,0,ts) {
        int f;
        cin >> f;

        union_find uf(2*f);
        map<string,int> id;

        rep(i,0,f) {
            string a, b;
            cin >> a >> b;

            if (id.find(a) == id.end()) {
                id.insert(make_pair(a, id.size()));
            }
            if (id.find(b) == id.end()) {
                id.insert(make_pair(b, id.size()));
            }

            uf.unite(id[a], id[b]);

            cout << uf.size_of_component(id[a]) << endl;
        }

    }

    return 0;
}

