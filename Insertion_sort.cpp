#include<bits/stdc++.h>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &a) {
    int key, j;
    for (int i = 0; i < a.size(); ++i) {
        key = a[i];
        j = i - 1;
        while (i > -1 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }
}

int main() {
    int x, n;
    vector<int> a;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    insertion_sort(a);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }

    return 0;
}