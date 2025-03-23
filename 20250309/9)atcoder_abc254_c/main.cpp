#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector< vector<int> > split(k);
    for(int i=0; i<n; i++){
        split[i % k].push_back(a[i]);
    }
    for(int i=0; i<k; i++){
        sort(split[i].begin(), split[i].end(), greater<int>());
    }
    vector<int> rebuilt;
    vector<int> current(k, 0); // Track where to pick the next element for each group

    // Rebuilding the array by picking elements from each sorted group
    for (int i = 0; i < n; i++) {
        int group = i % k;
        rebuilt.push_back(split[group][current[group]]);
        current[group]++;
    }
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    if (rebuilt == sorted_a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}