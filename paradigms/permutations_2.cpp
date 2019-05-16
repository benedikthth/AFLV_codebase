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

const int n = 5;
int perm[n];
bool used[n];

void generate(int at) {
    if (at == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", perm[i]+1);
        }
        printf("\n");
    } else {
        // decide what the at-th element should be
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                perm[at] = i;
                generate(at + 1);

                // remember to undo the move:
                used[i] = false;
            }
        }
    }
}

int main() {
    memset(used, 0, sizeof(used));
    generate(0);

    return 0;
}

