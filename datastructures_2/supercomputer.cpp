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
    int n, q;
    cin >> n >> q;

    int k = (int)sqrt(n);
    vector<int> arr(n);
    vector<int> buckets((n-1)/k+1);

    rep(t,0,q) {
        string op;
        cin >> op;

        if (op == "F") {
            int i;
            cin >> i;
            i--;

            if (arr[i] == 1) {
                arr[i] = 0;
                buckets[i/k]--;
            } else {
                arr[i] = 1;
                buckets[i/k]++;
            }

        } else if (op == "C") {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int cnt = 0;
            for (int b = 0; b < buckets.size(); b++) {
                int x = b * k,
                    y = x + k - 1;

                if (l <= x && y <= r) {
                    cnt += buckets[b];
                } else if (r < x || y < l) {
                } else {
                    for (int i = max(l, x); i <= min(r, y); i++) {
                        if (arr[i] == 1) {
                            cnt++;
                        }
                    }
                }
            }

            cout << cnt << endl;
        }
    }

    return 0;
}

