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
    int n, t;
    cin >> n >> t;

    int a, b, c, t0;
    cin >> a >> b >> c >> t0;

    vector<int> problem;
    problem.push_back(t0);

    while (problem.size() < n) {
        problem.push_back(((ll)a * problem.back() + b) % c + 1);
    }


    sort(problem.begin(), problem.end());

    int at = 0;
    int cnt = 0;
    ll penalty = 0;
    iter(it,problem) {
        if (at + *it > t) {
            break;
        }

        cnt++;
        at += *it;
        penalty += at;
    }

    cout << cnt << " " << penalty % 1000000007 << endl;

    return 0;
}

