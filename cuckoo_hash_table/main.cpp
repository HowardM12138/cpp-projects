#include "fns.h"

#include <iostream>

int main() {

    int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};

    int size_1 = sizeof(keys_1)/sizeof(int);

    cuckoo(keys_1, size_1);


    int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};

    int size_2 = sizeof(keys_2)/sizeof(int);

    cuckoo(keys_2, size_2);


    int keys_3[] = {34, 56, 74, 23, 53, 48, 90, 21, 36, 66, 44, 65, 89, 103, 33, 121, 77, 66, 83, 153};

    int size_3 = sizeof(keys_3)/sizeof(int);

    cuckoo(keys_3, size_3);

    return 0;
}
