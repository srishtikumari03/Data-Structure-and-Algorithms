#include<bits/stdc++.h>
#include<climits>
using namespace std;

class hash_maps {
    public:
    int* hash_map;

    hash_maps() {
        hash_map = (int*)malloc(sizeof(int)*10);
        for (int i = 0; i < 10; i++) {
        *(hash_map + i) = INT_MIN;
        }
    }

    void insert(int key) {
        int ans = 0;

        for (int i = 0; i < 10; i++) {
            int slot = (((key % 10) + i) % 10) - 1;

            if (*(hash_map + slot) == INT_MIN) {
                *(hash_map + slot) = key;
                ans = 1;
                break;
            }
        }

        if (ans == 0) {
            cout << "Hash map overflow" << "\n";
        }

        return;
    }      

    void delete_key(int key) {

        for (int i = 0; i < 10; i++) {
            int slot = (((key % 10) + i) % 10) - 1;

            if (*(hash_map + slot) == key) {
                *(hash_map + slot) = INT_MIN;
                break;
            }

            else if (*(hash_map + slot) == INT_MIN) {
                break;
            }
        }
        return;
    }   

    void print_map() {
        for (int i = 0; i < 10; i++) {
            if (*(hash_map + i) != INT_MIN) {
                cout << *(hash_map + i) << "\n";
            }

            else {
                cout << "NIL" << "\n";
            } 
        }
        return;
    }

    void search(int key) {
        int ans = 0;

        for (int i = 0; i < 10; i++) {
            int slot = (((key % 10) + i) % 10) - 1;

            if (*(hash_map + slot) == key) {
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
};

//main function
int main() {
    hash_maps my_map = hash_maps();

    my_map.insert(2);
    my_map.insert(12);
    my_map.insert(4);
    my_map.insert(62);
    my_map.insert(24);
    // my_map.print_map();

    my_map.delete_key(4);
    my_map.print_map();

    // my_map.search(62);
    // my_map.search(5);

    return 0;
}