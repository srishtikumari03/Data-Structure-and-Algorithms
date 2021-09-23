#include<bits/stdc++.h>
#include<climits>
using namespace std;

tuple<int, int, int> max_crossing_subarray(vector<int> a, int low, int mid, int high) {
    int left_sum, right_sum, max_left, max_right;
    left_sum = right_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i > low - 1; i = i - 1) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    for (int i = mid + 1; i < high + 1; ++i) {
        sum += a[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, (right_sum + left_sum));
}

tuple<int, int, int> find_max_subarray(vector<int> a, int low, int high) {
    tuple<int, int, int> left, right, cross;

    if (low == high) {
        return make_tuple(low, low, a[low]);
    }

    else {
        int mid = (low + high) / 2;
        left = find_max_subarray(a, low, mid);
        right = find_max_subarray(a, mid + 1, high);
        cross = max_crossing_subarray(a, low, mid, high);
    }

    if (get<2>(left) <= get<2>(right) && get<2>(cross) <= get<2>(right)) {
        return right;
    }

    else if (get<2>(right) <= get<2>(left) && get<2>(cross) <= get<2>(left)) {
        return left;
    }

    else {
        return cross;
    }
}

int main () {
    int n, x;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    tuple<int, int, int> ans = find_max_subarray(a, 0, a.size() - 1);
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";

    return 0;
}