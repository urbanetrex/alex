#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the number of clocks
    bool canReset = true; // Assume the clocks can be reset unless proven otherwise

    for (int i = 0; i < n; i++) {
        int time;
        cin >> time; // Read the time for each clock

        // Calculate the threshold (based on the position of the clock)
        int threshold = max(i, n - i - 1) * 2;

        // If time is less than or equal to the threshold, it's not safe
        if (time <= threshold) {
            canReset = false; // Unsafe condition found
            break; // Exit the loop as we found the answer
        }
    }

    // Output the result based on whether we found any unsafe clock
    if (canReset) {
        cout << "YES" << endl; // All clocks can be safely reset
    } else {
        cout << "NO" << endl; // At least one clock cannot be reset safely
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
