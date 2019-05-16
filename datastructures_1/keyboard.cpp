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
    string line;
    while (getline(cin, line)) {

        list<char> text;
        list<char>::iterator it = text.end();

        for (int i = 0; i < line.size(); i++) {
            char c = line[i];

            if (c == '[') {
                it = text.begin();
            } else if (c == ']') {
                it = text.end();
            } else {

                text.insert(it, c);

            }
        }

        for (it = text.begin(); it != text.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}

