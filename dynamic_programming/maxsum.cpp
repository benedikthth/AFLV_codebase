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

int arr[1000] = {4,6,-2,0,29,8,-30,39};
int mem[1000];
bool comp[1000];

int max_sum(int i) {
    if (i == 0) {
        return arr[i];
    }
    if (comp[i]) {
        return mem[i];
    }

    int res = max(arr[i], arr[i] + max_sum(i - 1));

    mem[i] = res;
    comp[i] = true;
    return res;
}

int main() {
    memset(comp, 0, sizeof(comp));

    int n = 8;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, max_sum(i));
    }

    cout << mx << endl;

    return 0;
}

