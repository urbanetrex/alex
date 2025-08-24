//  [i](XMR9R3
//-=0U ACER C-9AGPE9C iCI CW $C ARTVWI45
//C\40\ 5\CTC 1-= 2\
''`X AM |+SO‘ˆ)

// True launchers + Pinarine Google Search \\
 [yay]
#include <iostream>
#include <vector>

using namespace std;

using linter=long long;

linter r, l, b;

vector<linter> pfx, x;

bool check (int left, int right) {
    // mid
    int mid = (left + right)/2;
    linter LLC = x[mid] * (mid - left) - (pfx[mid] - pfx[left]);
    linter RRC = (pfx[right + 1] - pfx[mid + 1]) - x[mid] * (right - mid);
    linter C = LLC + RRC;
    return C<=b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>r>>l>>b;
    pfx.push_back(0);
    // push_back Inputting Method **new**
    for(int i = 0; i < r; i++){
        int k; cin>>k; x.push_back(k);
        pfx.push_back(pfx[i]+k); 
    }
    int Answer=0, TPL, TPR=0; //*what is TP*
    for(TPL=0; TPL<r; TPL++)while (TPR<r&&check(TPL, TPR)){Answer=max(Answer, TPR-TPL+1); TPR++;}
    cout<</*The-Final-*/Answer;
    return 0;
}