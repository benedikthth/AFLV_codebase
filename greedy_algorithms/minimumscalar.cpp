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
    int ts;
    cin >> ts;

    rep(t,0,ts) {
        int n;
        cin >> n;

        vector<ll> v1(n), v2(n);
        rep(i,0,n) cin >> v1[i];
        rep(i,0,n) cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());

        ll sm = 0;
        rep(i,0,n) {
            sm += v1[i] * v2[i];
        }

        cout << "Case #" << (t+1) << ": " << sm << endl;
    }

    return 0;
}

