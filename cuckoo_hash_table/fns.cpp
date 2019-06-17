#include "fns.h"
#include <iostream>
#include <limits>
#include <cmath>

const int rows = 2;
const int MAXN = 11;
int hash_table[rows][MAXN];

void init_hash_table() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < MAXN; j++) {
            hash_table[i][j] = std::numeric_limits<int>::quiet_NaN();
        }
    }
}

int hash_function(int function, int key) {
    if (function == 0) {
        return key%MAXN;
    } else if (function == 1) {
        return (key/MAXN)%MAXN;
    }
}

void place(int key, int to_row, int to_index, int cuckoo_count) {
    if (cuckoo_count == MAXN) {
        std::cout << key << " unpositioned\n";
        std::cout << "Cycle present. REHASH.\n";
    } else if (hash_table[to_row][to_index] == std::numeric_limits<int>::quiet_NaN()) {
        hash_table[to_row][to_index] = key;
    } else {
        int new_key = hash_table[to_row][to_index];
        hash_table[to_row][to_index] = key;
        if (to_row == 0) {
            to_index = hash_function(1, new_key);
            to_row = 1;
        } else if (to_row == 1) {
            to_index = hash_function(0, new_key);
            to_row = 0;
        }
        place (new_key, to_row, to_index, cuckoo_count+1);
    }
}

void cuckoo(int keys[], int size) {
    init_hash_table();

    for (int i = 0; i < size; i++) {
        int to_row = 0;
        int to_index = hash_function(to_row, keys[i]);
        place(keys[i], to_row, to_index);
    }
    print_table();
}

void print_table() {
    std::cout << "Final hash tables:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (hash_table[i][j] == std::numeric_limits<int>::quiet_NaN()) std::cout << "-";
            else std::cout << hash_table[i][j];
            std::cout << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
