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

int n;
vector<int> digits;
int cnt = 0;

void generate(int k) {
    if (k > 0) {
        stringstream ss;
        iter(it,digits) ss << *it;
        long long x;
        ss >> x;

        if (x % k != 0) {
            return;
        }
    }

    if (k == n) {
        // iter(it,digits) {
        //     cout << *it;
        // }
        // cout << endl;
        cnt++;
        return;
    }

    for (int d = 0; d < 10; d++) {
        if (d == 0 && k == 0) {
            continue;
        }

        digits.push_back(d);
        generate(k+1);
        digits.pop_back();
    }
}

int main() {
    cin >> n;
    generate(0);
    cout << cnt << endl;

    return 0;
}

