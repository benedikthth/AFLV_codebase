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

// bool p(double x) {
//     return x*x >= 13.37;
// }

double f(double x) {
    return 10*x + 5;
}

bool p(double x) {
    return f(x) >= 0.0;
}

int main() {

    double EPS = 1e-10,
           lo = -1000.0,
           hi = 1000.0;
    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2.0;
        if (p(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%0.10lf\n", lo);

    return 0;
}

