#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
void solve() {
    int n, k;
    cin>>n>>k;

    unordered_map<int, int> prices;
    for (int i = 0; i < k; i++) {
        int brand, price;
        cin >> brand >> price;
        prices[brand] += price;
    }
    
    priority_queue<int> pq;
    for(auto &[brand, totalPrice] : prices) {
        pq.push(totalPrice);
    }

    int sum = 0;
    for (int i = 0; i < n && !pq.empty(); i++) {
        sum += pq.top(); 
        pq.pop();        
    }

    cout << sum << endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}