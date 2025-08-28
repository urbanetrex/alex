#include <iostream>
//#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;

int parent[MAXN];
char letter[MAXN];
int length[MAXN];
int version[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int CnQ;
    cin >> CnQ;

    int curr_ver = 0;
    version[0] = 0; // initial version

    for (int i = 1; i <= CnQ; ++i) {
        char cmd;
        cin >> cmd;

        if (cmd == 'T') {
            char c;
            cin >> c;
            ++curr_ver;

            parent[curr_ver] = version[i - 1];  // previous version
            letter[curr_ver] = c;
            length[curr_ver] = length[parent[curr_ver]] + 1;

            version[i] = curr_ver;  // store current version

        } else if (cmd == 'U') {
            int x;
            cin >> x;
            version[i] = version[i - x - 1];  // rollback to previous version

        } else if (cmd == 'P') {
            int k;
            cin >> k;

            int v = version[i - 1];

            // walk back to the k-th character
            while (length[v] > k) {
                v = parent[v];
            }

            cout << letter[v] << '\n';

            version[i] = version[i - 1]; // version doesn't change
        }
    }

    return 0;
}
