#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
// const int INF = 2147483647;

int INF = 100000;
int d[10] = {1,5,10,50,100,500,1000,2000,5000};
// int d[10] = {7,8,9};
int mem[10][10000];
bool take[10][10000];

int opt(int i, int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == -1) return INF;

    if (mem[i][x] != -1) return mem[i][x];


    int a = 1 + opt(i, x - d[i]),
        b = opt(i - 1, x);

    int res = INF;
    res = min(res, a);
    res = min(res, b);

    if (a < b) {
        take[i][x] = true;
    } else {
        take[i][x] = false;
    }

    mem[i][x] = res;
    return res;
}

void reconstruct(int i, int x) {
    if (x < 0) {
        cout << "impossible" << endl;
        return;
    }
    if (x == 0) {
        return;
    }
    if (i == -1) {
        cout << "impossible" << endl;
        return;
    }

    // int a = 1 + opt(i, x - d[i]),
    //     b = opt(i - 1, x);

    if (take[i][x]) {
        cout << d[i] << endl;
        reconstruct(i, x - d[i]);
    } else {
        reconstruct(i - 1, x);
    }
}

int main() {
    memset(mem, -1, sizeof(mem));

    // cout << opt(8, 1337) << endl;
    // cout << "min change: " << opt(2, 15) << endl;
    // reconstruct(2, 15);
    cout << "min change: " << opt(8, 1337) << endl;
    reconstruct(8, 1337);

    return 0;
}

