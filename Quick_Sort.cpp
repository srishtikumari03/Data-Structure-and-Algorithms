#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& array, int start, int end);
void print_array(vector<int>& array);

void quicksort(vector<int>& array, int start, int end) {
    int index = partition(array, start, end);

    if (index <= start) {
        return;
    }

    else {
        quicksort(array, start, index - 1);
        quicksort(array, index, end);
    }
}

int partition(vector<int>& array, int start, int end) {
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; ++j){
        if (pivot >= array[j]) {
            i = i + 1;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    return (i + 1);
}

void print_array(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i){
        cout << array[i] << "\n";
    }

    return;
}

int main() {
    vector<int> array{4, 5, 2, 8, 8, 10, 1, 2, 3, 6};
    quicksort(array, 0, array.size() - 1);
    print_array(array);

    return 0;
}