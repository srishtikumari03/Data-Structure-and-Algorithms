#include<bits/stdc++.h>
#include<climits>
using namespace std;

void merge(vector<int> &array, int start, int mid, int end) {
    vector<int> left, right;
    for (int i = 0; i < mid - start + 1; ++i) {
        left.push_back(array[start + i]);
    }

    left.push_back(INT_MAX);

    for (int i = 1; i < end - mid + 1; ++i) {
        right.push_back(array[mid + i]);
    }

    right.push_back(INT_MAX);

    int i, j;
    i = j = 0;
    for (int k = start; k <= end; ++k) {
        if (left[i] > right[j]) {
            array[k] = right[j];
            ++j;
        }

        else {
            array[k] = left[i];
            ++i;
        }
    }

    return;
}

void merge_sort(vector<int> &array, int start, int end) {
    int mid;

    if (end > start) {
        mid = (start + end)/ 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }

    else {
        return;
    }
}

int main() {
    int n, x;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        array.push_back(x);
    }

    merge_sort(array, 0, array.size() - 1);

    for (int i = 0; i < array.size(); ++i) {
        cout << array[i]  << " " ;
    }

    cout << "\n";

    return 0;
}