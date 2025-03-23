#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the number of clocks
    int clocks[n];  // Array to store the clock times
    
    for(int i = 0; i < n; i++) {
        cin >> clocks[i];  // Read each clock's time
    }

    for(int i = 0; i < n; i++) {
        // Calculate the max distance and multiply by 2 for the check
        if (clocks[i] <= (max(i, n - i - 1) * 2)) {
            cout << "NO" << endl;  // If any clock doesn't have enough time, it's a "NO"
            return;
        }
    }

    cout << "YES" << endl;  // If all clocks are safe, it's a "YES"
}

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {
        solve();  // Solve each test case
    }

    return 0;
}
