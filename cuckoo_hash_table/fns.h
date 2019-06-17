#ifndef FNS_H
#define FNS_H

void initHashTable();
void print_table();
int hash_function(int function, int key);
void place(int key, int to_row, int to_index, int cuckoo_count = 0);
void cuckoo(int keys[], int size);

#endif
