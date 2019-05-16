#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 1000000000;

int main() {
    int c = 1;
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        rep(i,0,n) cin >> arr[i];

        cout << "Case " << c++ << ":" << endl;

        int m;
        cin >> m;
        rep(t,0,m) {
            int x;
            cin >> x;

            int best_sum = -INF;

            rep(i,0,n) {
                rep(j,i+1,n) {
                    int sum = arr[i] + arr[j];

                    if (abs(sum - x) < abs(best_sum - x)) {
                        best_sum = sum;
                    }
                }
            }

            cout << "Closest sum to " << x << " is " << best_sum << "." << endl;

        }
    }

    return 0;
}

