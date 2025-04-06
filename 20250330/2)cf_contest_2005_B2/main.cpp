#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> teachers(m); //SYMBOLCHANGE type-int[]->vector<int> symbol-tc->teachers
        for (int i = 0; i < m; i++) {
            cin >> teachers[i];
        }
        sort(teachers.begin(), teachers.end());
        for (int i = 0; i < q; i++) {
            int dq;
            cin >> dq;
            if(teachers[0]>dq){
                int right = teachers[0];
                cout<<right-1<<'\n';
            } else if (teachers[m-1]<dq){
                int left = teachers[m-1];
                cout<<dq-left<<'\n';
            } else {
                int change = 0;
                for(int j = 0; j < m; j++) {
                    if (teachers[j] >= dq) {
                        change = j;
                        break;
                    }
                }
                int left = teachers[change - 1];
                int right = teachers[change];
                cout<<(right - left)/2<<'\n';
            }
        }

    }
}