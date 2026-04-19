#include<bits/stdc++.h>
using namespace std;

char ask(int i) {
    cout << "? " << i << endl; 
    char color;
    cin >> color;
    return color;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    char color1 = ask(1);

    char colorN = ask(n);
    if (colorN == color1) {
        cout << "! " << n  << endl;
        return 0;
    }

    int L = 1, R = n;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        char colorMid = ask(mid);

        bool expectedSame = ((mid - 1) % 2 == 0);
        bool actualSame = (colorMid == color1);

        if (actualSame == expectedSame) {
            L = mid;
        } else {
            R = mid;
        }
    }

    cout << "! " << L <<endl;

    return 0;
}

