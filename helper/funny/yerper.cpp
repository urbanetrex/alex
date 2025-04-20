#include <iostream>
#include <ctime>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    srand(time(0));
    for(unsigned long long i=0; i<rand()/10000; i++){
        int result = rand()%6;
        switch (result) {
            case 0:cout<<"eyp ";break;
            case 1:cout<<"yepp ";break;
            case 2:cout<<"yerp ";break;
            case 3:cout<<"yepe ";break;
            case 4:cout<<"pye ";break;
            case 5:cout<<"Yp ";break;
        }
    }
    return 0;
}