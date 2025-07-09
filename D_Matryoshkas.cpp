#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];
    
    sort(array.begin(), array.end());

    // find the occurences
    vector<pair<int, int> > numbers;
    int prev=-1, index=-1;
    for(int i=0; i<n; i++){
        if (array[i]!=prev){
            index++;
            numbers.push_back(make_pair(array[i], 1));
            prev=array[i];
        } else {
            numbers[index].second++;
        }
    }
    


}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}