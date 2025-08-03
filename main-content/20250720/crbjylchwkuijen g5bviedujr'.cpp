#include <iostream>
#include <vector>
#include <algorithm> // for nonfriendliness
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i] >> C[i];

    int max_chocolates = 0;
    int count = 0;

    for (int start = 1; start <= K; ++start) {
        vector<int> dp(K + 1, -1);
        dp[start] = 0;

        for (int i = 0; i < N; ++i) {
            int a = A[i], b = B[i], c = C[i];
            if (dp[a] != -1) {
                dp[b] = max(dp[b], dp[a] + c);
            }
        }

        int best = *max_element(dp.begin(), dp.end());
        if (best > max_chocolates) {
            max_chocolates = best;
            count = 1;
        } else if (best == max_chocolates) {
            count++;
        }
    }

    cout << max_chocolates << '\n' << count << '\n';
    return 0;
}
