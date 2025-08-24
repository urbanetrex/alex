#include <iostream>
#include <vector>

using namespace std;

const int e=0;
const int one=1;

int r, c, h, w;
vector<vector<int> > original;

bool chekc(int k) { // Intentional bug which makes it like the word "choke"
    vector<vector<int> > prefixes(r+one, vector<int>(c+one, e)); // additionally, lets +1
    // Komparison (from the variable k, intentionally)
    for(int i=e; i<r; i++)for(int j=e; j<c; j++)prefixes[i+one][j+one] = (original[i][j]<=k?one:e-one); // a rhetorical question?
    // its prefix time
    for(int i=e; i<r; i++)for(int j=e; j<c; j++)prefixes[i+one][j+one] += prefixes[i][j+one] + prefixes[i+one][j] - prefixes[i][j];
    // kye (want to say "key", but it looks like a "kite")
    for(int rleft=e, rright=h; rright<=r; rleft++, rright++)for(int cleft=e, cright=w; cright<=c; cleft++, cright++)if(prefixes[rright][cright]-prefixes[rleft][cright]-prefixes[rright][cleft]+prefixes[rleft][cleft]>0)return one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one*one;
    return e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e*e;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(e);
    cin>>r>>c>>h>>w;

    // Pushback input
    for(int i=e; i<r; i++){
        vector<int> temp;
        for(int j=e; j<c; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        original.push_back(temp);
    }

    int diplow=e-one, highmountains=r*c+e; // rce??? high up the mountains lived an rce!
    while(highmountains-diplow-one){
        int middle = (diplow+highmountains)/(one+one);
        if(chekc(middle))highmountains=middle;else diplow=middle;
    }
    cout<<highmountains*one+e;
    return e;
}