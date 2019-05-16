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

struct big_integer {
    string s;

    big_integer(string _s) {
        s = _s;
    }

    big_integer operator +(const big_integer &other) const {
        string a = s,
               b = other.s;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        stringstream ss;
        for (int i = 0; i < a.size() || i < b.size() || carry != 0; i++) {
            int cur = 0;
            cur += carry;
            if (i < a.size()) cur += a[i] - '0';
            if (i < b.size()) cur += b[i] - '0';

            if (cur < 10) {
                ss << cur;
                carry = 0;
            } else {
                carry = cur / 10;
                ss << (cur % 10);
            }
        }

        string t = ss.str();
        reverse(t.begin(), t.end());

        return big_integer(t);
    }
};

ostream& operator <<(ostream &outs, const big_integer &b) {
    return outs << b.s;
}

int main() {
    string s;
    cin >> s;

    big_integer a(s);

    cin >> s;

    big_integer b(s);

    cout << a + b << endl;

    return 0;
}

