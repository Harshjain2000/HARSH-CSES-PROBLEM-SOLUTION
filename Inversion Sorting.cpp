#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long query(int i, int j) {
    cout << i << " " << j << endl;
    long long res;
    cin >> res;
    if (res == 0) exit(0); 
    return res;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) query(1,1);

    long long total_inv = query(1, 1);

    vector<long long> pref_inv(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        long long cur_inv = query(1, i);
        pref_inv[i] = (i * (i - 1LL) / 2 + total_inv - cur_inv) / 2;
        total_inv = query(1, i);
    }

    vector<int> p(n + 1);
    vector<int> available;
    for (int i = 1; i <= n; ++i) available.push_back(i);

    for (int i = n; i >= 1; --i) {
        int count_greater = pref_inv[i] - pref_inv[i - 1];
        int val_idx = i - count_greater - 1;
        p[i] = available[val_idx];
        available.erase(available.begin() + val_idx);
    }

    vector<int> current_p(p.begin() + 1, p.end());
    for (int target = 1; target < n; ++target) {
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (current_p[i] == target) {
                pos = i + 1;
                break;
            }
        }
        if (pos != target) {
            query(target, pos);
            reverse(current_p.begin() + target - 1, current_p.begin() + pos);
        }
    }

    return 0;
}

