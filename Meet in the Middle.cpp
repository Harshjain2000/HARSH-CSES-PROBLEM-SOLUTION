#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void generate_sums(const vector<long long>& arr, vector<long long>& sums) {
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++) {
        long long current_sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                current_sum += arr[j];
            }
        }
        sums.push_back(current_sum);
    }
}

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<long long> left, right;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) left.push_back(v[i]);
        else right.push_back(v[i]);
    }

    vector<long long> left_sums, right_sums;
    generate_sums(left, left_sums);
    generate_sums(right, right_sums);

    sort(left_sums.begin(), left_sums.end());

    long long count = 0;
    for (long long s : right_sums) {
        auto range = equal_range(left_sums.begin(), left_sums.end(), x - s);
        count += distance(range.first, range.second);
    }
    cout << count << endl;

    return 0;
}
