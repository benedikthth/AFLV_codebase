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

map<int, ll> memory;

ll fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }

    if (memory.find(n) != memory.end()) {
        return memory[n];
    }

    ll res = fibonacci(n - 2) + fibonacci(n - 1);

    memory[n] = res;
    return res;
}

int main() {

    for (int i = 1; i <= 100000; i++) {
        cout << i << " " << fibonacci(i) << endl;
    }

    // cout << fibonacci(100000) << endl;

    // memory[1] = 1;
    // memory[2] = 1;

    // for (int i = 3; i <= 100000; i++) {
    //     memory[i] = memory[i-2] + memory[i-1];
    // }

    // cout << memory[100000] << endl;

    // ll memory1 = 1,
    //     memory2 = 1;

    // for (int i = 3; i <= 100000; i++) {
    //     ll memory3 = memory1 + memory2;
    //     // memory[i] = memory[i-2] + memory[i-1];
    //     memory1 = memory2;
    //     memory2 = memory3;
    // }

    // // cout << memory[100000] << endl;
    // cout << memory2 << endl;

    return 0;
}

