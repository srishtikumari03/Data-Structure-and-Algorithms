#include<bits/stdc++.h>
#include<climits>
using namespace std;

 //function prototypes
void search(int* map, int key);
int* insert(int* map, int key);
int* delete_key(int* map, int key);
void print_map(int* map);

 //function definations
void search(int* map, int key) {
    int ans = 0;

    for (int i = 0; i < 10; i++) {
        int slot = (((key % 10) + i) % 10) - 1;

        if (*(map + slot) == key) {
            ans = 1;
            cout << "Key present in the hash map" << "\n";
            break;
        }
    }

    if (ans == 0) {
        cout << "Key is not present in the hash map" << "\n";
    }

    return;
}

int* insert(int* map, int key) {
    int ans = 0;

    for (int i = 0; i < 10; i++) {
        int slot = (((key % 10) + i) % 10) - 1;

        if (*(map + slot) == INT_MIN) {
            *(map + slot) = key;
            ans = 1;
            break;
        }
    }

    if (ans == 0) {
        cout << "Hash map overflow" << "\n";
    }

    return map;
}

int* delete_key(int* map, int key) {

    for (int i = 0; i < 10; i++) {
        int slot = (((key % 10) + i) % 10) - 1;

        if (*(map + slot) == key) {
            *(map + slot) = INT_MIN;
            break;
        }

        else if (*(map + slot) == INT_MIN) {
            break;
        }
    }

    return map;
}

void print_map(int* map) {
    for (int i = 0; i < 10; i++) {
        if (*(map + i) != INT_MIN) {
            cout << *(map + i) << "\n";
        }

        else {
            cout << "NIL" << "\n";
        } 
    }

    return;
}

//main function
int main() {
    int* map = (int*)malloc(sizeof(int) * 10);
    
    //initialisation
    for (int i = 0; i < 10; i++) {
        *(map + i) = INT_MIN;
    }

    map = insert(map, 2);
    map = insert(map, 12);
    map = insert(map, 4);
    map = insert(map, 62);
    map = insert(map, 24);
    //print_map(map);

    map = delete_key(map, 4);
    //print_map(map);

    //search(map, 62);
    //search(map, 5);

    return 0;
}