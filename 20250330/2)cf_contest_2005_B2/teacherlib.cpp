#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> teachers(m);
    for (int &x : teachers) cin >> x;
    sort(teachers.begin(), teachers.end());

    while (q--) {
        int x;
        cin >> x;
        int j = lower_bound(teachers.begin(), teachers.end(), x) - teachers.begin();
        if (j == m) { // david is on the right of the last teacher
            cout << n - teachers[j - 1] << '\n';
        } else if (j == 0) { // david is on the left of the first teacher
            cout << teachers[j] - 1 << '\n';
        } else { // david is between two teachers
            cout << (teachers[j] - teachers[j - 1]) / 2 << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}