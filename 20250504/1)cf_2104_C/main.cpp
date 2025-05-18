#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int bob_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            bob_cnt++;
        }
    }
    
    // my lack of knowledge
    // i had enough of this
    // i will just brute force it
    // i will just brute force it
    // i will just brute force it
    // i will just brute force it
    // i will just brute force it

    // no, i will not brute force it
    // ok let's brute force it
    // no, i will not brute force it
    // ok let's brute force it
    // no, i will not brute force it
    // ok let's brute force it
    // no, i will not brute force it
    // ok let's brute force it
    // no, i will not brute force it
    // ok let's brute force it
    // no, i will not brute force it

    // there is no way to brute force it
    // i will just brute force it

    // lack of knowledge
    // i will just brute force it
    // lack of knowledge
    // i will just brute force it
    // lack of knowledge
    // i will just brute force it
    // lack of knowledge
    // i will just brute force it
    // lack of knowledge
    // i will just brute force it
    // lack of knowledge
    // i will just brute force it

    // oh oh oh
    // OOPS!!!
    // NO! THERE IS NO WAY TO BRUTE FORCE IT
    // so the solution is simple
    // since we know that the first and last cards are the most important
    // because there is an exception
    // that is, card 0 beats card n-1
    
    // there are four possible cases:
    // 1. a(0)=A, b(n-1)=A -> Alice wins
    // 2. a(0)=A, b(n-1)=B -> if bob has >= 2 cards, he wins
    // 3. a(0)=B, b(n-1)=A -> whoever has card n-2 wins
    // 4. a(0)=B, b(n-1)=B -> bob wins
    // let us go through the cases and uncomment the code
    // [rocket][go!]

    if (s[0] == 'A' && s[n-1] == 'A') {
        cout << "Alice\n";
    } else if (s[0] == 'A' && s[n-1] == 'B') {
        if (bob_cnt >= 2) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else if (s[0] == 'B' && s[n-1] == 'A') {
        if (s[n-2] == 'B') {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        cout << "Bob\n";
    }

    // did we miss anything?
    // no, we did not
    // we are done
    /* happily end with a */return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
} /* ak 100 lines with 64 lines of comments (a hail) */