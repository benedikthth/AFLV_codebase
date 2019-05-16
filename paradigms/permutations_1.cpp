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

    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i + 1;

    do {
        for (int i = 0; i < n; i++) {
            printf("%d ", perm[i]);
        }
        printf("\n");
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}

