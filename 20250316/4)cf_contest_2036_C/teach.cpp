#include <iostream>     // compatible

using namespace std;

bool is_1100(int i, int n, string &s) {
    if (i < 0 || i + 3 >= n) return false;
    return s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int cnt = 0;
    for (int i = 0; i + 3 < n; i++) {
        if (is_1100(i, n, s)) cnt++;
    }

    int q;
    cin >> q;
    while (q--) {
        int i; char c;
        cin >> i >> c;
        i--;
        
        for (int j = i - 3; j <= i; j++) {
            if (is_1100(j, n, s)) cnt--;
        }
        s[i] = c;
        for (int j = i - 3; j <= i; j++) {
            if (is_1100(j, n, s)) cnt++;
        }

        if (cnt > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}