#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h;
    cin>>w>>h;
    int k;
    cin>>k;
    vector<pair<int,int> > ranges;
    for(int i=0; i<k; i++){
        int p;
        cin>>p;
        int xmin=w+1, xmax=0;
        for(int i=0; i<p; i++){
            int x, y;
            cin>>x>>y;
            xmin=min(x, xmin);
            xmax=max(x, xmax);
        }
        ranges.push_back(make_pair(xmin, xmax));
    }
    sort(ranges.begin(), ranges.end());

    vector<pair<int,int> > merged;
    for (auto &r : ranges) {
        if (merged.empty() || r.first > merged.back().second + 1) {
            merged.push_back(r);
        } else {
            merged.back().second = max(merged.back().second, r.second);
        }
    }

    long long total_blocked = 0;
    for (auto &r : merged) {
        total_blocked += (long long)(r.second - r.first + 1);
    }

    return 0;
}