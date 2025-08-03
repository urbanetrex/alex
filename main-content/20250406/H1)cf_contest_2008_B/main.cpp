#include <iostream>
#include <cmath>

using namespace std;

bool isSquare(int x) {
    int sq = sqrt(x);
    return sq * sq == x;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    //count int 0s in string s
    int cnt = 0;
    for (char c : s) {
        if (c == '0') {
            cnt++;
        }
    }
    if (isSquare(s.size()) && isSquare(cnt)){
        if (sqrt(s.size()) == sqrt(cnt) + 2){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}