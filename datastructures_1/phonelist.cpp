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

        set<string> phonebook;
        vector<string> phone_list;
        rep(i,0,n) {
            string phone_number;
            cin >> phone_number;
            phone_list.push_back(phone_number);
            phonebook.insert(phone_number);
        }

        bool consistent = true;
        rep(i,0,n) {
            string phone_number = phone_list[i];

            for (int l = 1; l < phone_number.size(); l++) {
                string phone_number_prefix = phone_number.substr(0, l);
                if (phonebook.find(phone_number_prefix) != phonebook.end()) {
                    consistent = false;
                    break;
                }
            }

            if (!consistent) {
                break;
            }
        }

        if (consistent) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}

