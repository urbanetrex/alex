#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

inline string random_string(vector<string> list, bool initrand=false){
    if(initrand) {
        srand(time(0));
    }
    return list[rand()%list.size()];
}

int main(){
    // Declare the vector with an explicit constructor
    vector<vector<string>> alpha;

    // Manually create vector<string> and then push into alpha
    alpha.push_back(vector<string>{"ALPHABET", "ASCII", "ATCODER"});
    alpha.push_back(vector<string>{"BAGLESS", "BAG", "BUG"});
    alpha.push_back(vector<string>{"CODEFORCES", "CONTESTS", "CHATGPT"});
    alpha.push_back(vector<string>{"DOG", "DOT", "DOME"});
    alpha.push_back(vector<string>{"ELEPHANT", "ELECTRIC", "ELEVATOR"});
    alpha.push_back(vector<string>{"FIRE", "FLAME", "FLOOD"});
    alpha.push_back(vector<string>{"GIRAFFE", "GLOW", "GLASS"});
    alpha.push_back(vector<string>{"HOUSE", "HOME", "HORIZON"});
    alpha.push_back(vector<string>{"ICE", "INSTRUMENT", "INTERFACE"});
    alpha.push_back(vector<string>{"JUMP", "JACK", "JOURNEY"});
    alpha.push_back(vector<string>{"KITE", "KING", "KITCHEN"});
    alpha.push_back(vector<string>{"LEETCODE", "LADDER", "LEMON"});
    alpha.push_back(vector<string>{"MOUSE", "MONEY", "MOTOR"});
    alpha.push_back(vector<string>{"NIGHT", "NEON", "NOTE"});
    alpha.push_back(vector<string>{"OPEN", "ORANGE", "OCEAN"});
    alpha.push_back(vector<string>{"PANDA", "PENCIL", "POT"});
    alpha.push_back(vector<string>{"QUEEN", "QUIET", "QUESTION"});
    alpha.push_back(vector<string>{"RAIN", "ROCKET", "ROAD"});
    alpha.push_back(vector<string>{"SCHOOL", "SOUND", "SNOW"});
    alpha.push_back(vector<string>{"TIGER", "TASK", "TROUBLE"});
    alpha.push_back(vector<string>{"UNIVERSE", "UNDER", "UTILITY"});
    alpha.push_back(vector<string>{"VAN", "VEST", "VIRUS"});
    alpha.push_back(vector<string>{"WATER", "WAVE", "WIND"});
    alpha.push_back(vector<string>{"XENON", "X-RAY", "XMAS"});
    alpha.push_back(vector<string>{"YELLOW", "YOUNG", "YOGA"});
    alpha.push_back(vector<string>{"ZEBRA", "ZERO", "ZONE"});

    srand(time(0));
    int n;
    cin >> n;
    int start = rand() % 26;
    string str = random_string(alpha[start]);
    start = str[str.size() - 1] - 65;
    cout << str << endl;

    while (n) {
        str = random_string(alpha[start]);
        start = str[str.size() - 1] - 65;
        cout << '@' << str.substr(1, str.size() - 1);
        n--;
    }

    cout << endl;
    return 0;
}
