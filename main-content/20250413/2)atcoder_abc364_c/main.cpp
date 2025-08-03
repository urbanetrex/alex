#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, x, y;
    cin>>n>>x>>y;
    vector<long long> a(n), b(n);
    for(long long i=0; i<n; i++)cin>>a[i];
    for(long long i=0; i<n; i++)cin>>b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    long long ans1=0, ans2=0;
    for(long long i=0, sum1=0; sum1<=x && i<n; sum1+=a[i], i++, ans1++){}
    for(long long i=0, sum2=0; sum2<=y && i<n; sum2+=b[i], i++, ans2++){}
    cout<<min(ans1, ans2)<<endl;
    return 0;
}