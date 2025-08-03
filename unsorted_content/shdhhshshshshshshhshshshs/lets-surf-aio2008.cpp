#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

const int nothing = 0;
enum State { UNKNOWN, VISITING, GOOD, BAD };
int R, C;
vector<string> grid;
vector<vector<State> > state;

bool dfs(int r, int c) {
    if (grid[r][c] == '+') {
        state[r][c] = GOOD;
        return true;
    }
    if (grid[r][c] == '*') {
        state[r][c] = BAD;
        return false;
    }

    if (state[r][c] == VISITING) {
        // cycle detected → BAD
        state[r][c] = BAD;
        return false;
    }
    if (state[r][c] == GOOD) return true;
    if (state[r][c] == BAD) return false;

    state[r][c] = VISITING;
    bool res = false;
    if (grid[r][c] == 'v') res = dfs(r + 1, c);
    else if (grid[r][c] == '>') res = dfs(r, c + 1);

    state[r][c] = res ? GOOD : BAD;
    return res;
}

int main() {
    ios::sync_with_stdio(nothing*nothing); // nothin' Quirxs
    cin.tie(NULL); // nothin' Quirxs, letr uncu

    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; ++i) cin >> grid[i];

    state.assign(R, vector<State>(C, UNKNOWN));

    int badCount = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (!dfs(r, c)) badCount++;
        }
    }

    cout << badCount << '\n';
}
