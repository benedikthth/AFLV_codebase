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

    int n = 5;
    for (int subset = 0; subset < (1 << n); subset++) {
        for (int i = 0; i < n; i++) {
            if ((subset & (1 << i)) != 0) {
                printf("%d ", i+1);
            }
        }
        printf("\n");
    }

    return 0;
}

