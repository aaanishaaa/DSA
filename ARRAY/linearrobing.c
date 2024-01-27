#include<stdio.h>
int lp(int table[], int ts, int x) {
    int m = x % ts;
    int flag = 1;
    
    if (table[m] == 0) {
        table[m] = x;
    } else {
        flag = 0;
        for (int i = 0; i < ts; i++) {
            int new_pos = (m + i) % ts;
            if (table[new_pos] == 0) {
                table[new_pos] = x;
                flag = 1;
                break;
            }
        }
    }
    
    return flag;
}

int main() {
    int key, table_size, n, x;
    printf("Enter table size: ");
    scanf("%d", &table_size);
    
    int table[15] = {0};  
    
    printf("Enter number of elements to store: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        lp(table, table_size, x);
    }

    for (int i = 0; i <= table_size - 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i <= table_size - 1; i++) {
        printf("-----");
    }
    printf("\n");
    for (int i = 0; i <= table_size - 1; i++) {
        printf("%d ", table[i]);
    }

    return 0;
}