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

const double pi = acos(-1.0);

int n, f;
double rad[10100];

bool p(double x) {
    int total = 0;
    rep(i,0,n) {
        double volume = rad[i] * rad[i] * pi;
        total += floor(volume / x);
    }

    return total >= f+1;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        cin >> n >> f;
        rep(i,0,n) cin >> rad[i];

        double lo = 0,
               hi = 1e9;
        while (hi-lo > 1e-9) {
            double mid = (lo+hi)/2;
            if (p(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        cout << setprecision(10) << fixed << lo << endl;
    }

    return 0;
}

