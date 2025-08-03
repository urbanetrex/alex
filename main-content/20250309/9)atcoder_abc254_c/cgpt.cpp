#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    
    // Reading the input array
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector< vector<int> > split(k);  // Use '> >' here instead of '>>'

    // Splitting the array into k groups based on positions mod k
    for (int i = 0; i < n; i++) {
        split[i % k].push_back(a[i]);
    }

    // Sorting each group
    for (int i = 0; i < k; i++) {
        sort(split[i].begin(), split[i].end());
    }

    vector<int> rebuilt;
    vector<int> indices(k, 0); // Keeps track of current index for each group

    // Rebuilding the array by picking elements from each sorted group
    for (int i = 0; i < n; i++) {
        int group = i % k;
        rebuilt.push_back(split[group][indices[group]]);
        indices[group]++;
    }

    // Sorting the original array to check against
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    // Comparing rebuilt array with the sorted original
    if (rebuilt == sorted_a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
