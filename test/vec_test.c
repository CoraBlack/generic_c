#include "../src/include/generic_c.h"
#include <stdio.h>

void print_int_vec(Vec* vec) {
    for (int i = 0; i < (int)Generic_vec_length(vec); i++) {
        printf("%d\n", *(int*)Generic_vec_at(vec, i));
    }
}


int main(void) {
    // Intialize vec
    __auto_type vec = Generic_vec_new((int[]){1, 2, 3, 4}, 4, sizeof(int));
    printf("Print vec eles:\n");
    print_int_vec(vec);

    // vec set
    for (int i = 0; i < 4; i++) {
        int ele = *(int*)Generic_vec_at(vec, i) + 1;
        Generic_vec_set(vec, i, &ele);
    }
    printf("Print vec after set:\n");
    print_int_vec(vec);

    // vec resize
    Generic_vec_resize(vec, Generic_vec_length(vec) - 1);
    printf("Print vec after resize: %zu\n", Generic_vec_length(vec));

    // vec push_back
    printf("Vec push_back 5 ele\n");
    for (int i = 0; i < 5; i++) {
        int ele = i + 5;
        Generic_vec_push_back(vec, &ele);
    }
    printf("Print vec after push_back:%zu\n", Generic_vec_length(vec));
    print_int_vec(vec);

    return 0;
}