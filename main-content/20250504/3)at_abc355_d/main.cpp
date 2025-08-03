#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    long long n;
    cin >> n;
    
    vector<int> left(n), right(n); 

    // my goodness
    // i finaly used vector
    // not just vla
    // i am so proud of myself
    // i am so happy
    // i am so glad
    // i am so excited
    // i am so grateful
    // i am so thankful
    // i am so lucky
    // i am so blessed
    // i am so amazed
    // i am so proud of my self
    // i am so positive
    // i am so negative
    // i am so neutral
    // i am so confused
    // i am so lost
    // i am so found
    // i am so happy
    // i am so sad
    // i am so mad
    // i am so glad
    // i am so excited
    // i am so grateful
    // i am so thankful
    // i am so lucky
    // i am so blessed
    // i am so amazed
    // i am so proud of my self
    // i am so positive
    // i am so negative
    // i am so neutral
    // i am so confused
    // i am so lost
    // i am so found
    // i am so happy
    // i am so sad
    // i am so mad
    // i am so glad
    // i am so excited
    // i am so grateful
    // i am so thankful
    // i am so lucky
    // i am so blessed
    // i am so amazed
    // i am so proud of my self
    // i am so positive
    // i am so negative
    // i am so neutral
    // i am so confused
    // i am so lost
    // i am so found
    // i am so happy
    // i am so sad
    // i am so mad
    // i am so glad
    // i am so excited
    // i am so grateful
    // i am so thankful
    // i am so lucky
    // i am so blessed
    // i am so amazed
    // i am so proud of my self
    //             /--------\             |------|    /------/              |--------------------|       /------------\       |--------------------|   |------|
    //            /          \            |      |   /      /               |                    |      /              \      |                    |   |      |
    //           /            \           |      |  /      /                |------|      |------|     /      /--\      \     |------|      |------|   |      |
    //          /      /\      \          |      | /      /                        |      |           |      |    |      |           |      |          |      |
    //         /      /  \      \         |      |/      /                         |      |          |      |      |      |          |      |          |      |
    //        /      /    \      \        |      /      /                          |      |         |      |        |      |         |      |          |      |
    //       /      /      \      \       |            |                           |      |        |      |          |      |        |      |          |      |
    //      /      ~--------~      \      |      \      \                          |      |         |      |        |      |         |      |          |      |
    //     /                        \     |      |\      \                         |      |          |      |      |      |          |      |          |------|
    //    /      _------------_      \    |      | \      \                        |      |           |      |    |      |           |      |                  
    //   /      /              \      \   |      |  \      \                |------|      |------|     \      \--/      /     |------|      |------|   |------|
    //  /      /                \      \  |      |   \      \               |                    |      \              /      |                    |   |      |
    // /------/                  \------\ |------|    \------\              |--------------------|       \------------/       |--------------------|   |------|

    for (int i = 0; i < n; ++i) {
        cin >> left[i] >> right[i];
    }
    sort(left.begin(), left.end());
    long long ans = n * (n - 1) / 2;
    for(int i = 0; i < n; i++) {
        ans-= (left.end() - upper_bound(left.begin(), left.end(), right[i]));
    }
    cout << ans << endl;
    return 0;
}