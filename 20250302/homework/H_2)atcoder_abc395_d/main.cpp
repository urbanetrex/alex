#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    size_t n, q;
    cin>>n>>q;
    vector< vector<size_t> > nests(n+1); // Initialize nests as a vector of vectors with size n
    vector<size_t> pigeons(n+1); // Initialize pigeons vector with size n
    for(size_t i = 1; i <= n; i++) {
        pigeons[i] = i; // Pigeon i is initially in nest i
        nests[i].push_back(i); // Add pigeon i to nest i
    }
    

    // A for loop run q times
    for(size_t i=0; i<q; i++){
        size_t op;
        cin>>op;
        switch(op){
            case 1:
                // Input size_tegers a and b
                // Then take pigeon a to nest b
                {
                    size_t a, b;
                    cin >> a >> b;

                    size_t old_nest = pigeons[a]; // Find the old nest of pigeon a

                    // Find pigeon a in its old nest and remove it
                    auto &old_nest_vec = nests[old_nest];
                    auto it = find(old_nest_vec.begin(), old_nest_vec.end(), a);
                    if (it != old_nest_vec.end()) { 
                        old_nest_vec.erase(it); // Remove pigeon a from the old nest
                    }

                    // Move pigeon a to nest b
                    nests[b].push_back(a);
                    pigeons[a] = b;
                }
                break;
            case 2:
                // Input size_tegers a and b
                // Then move all pigeons in nest a to nest b, and move all pigeons in nest b to nest a
                {
                    size_t a, b;
                    cin>>a>>b;
                    swap(nests[a], nests[b]);
                    for(size_t i=0; i<nests[a].size(); i++){
                        pigeons[nests[a][i]] = a;
                    }
                    for(size_t i=0; i<nests[b].size(); i++){
                        pigeons[nests[b][i]] = b;
                    }
                }
                break;
            case 3:
                // Input size_teger a
                // Pigeon a reports its nest
                {
                    size_t a;
                    cin>>a;
                    cout<<pigeons[a]<<endl;
                }
                break;
        }
    }
    return 0;
}