#include "../src/include/array.h"
#include <stdio.h>

void foreach_array(Array* arr) {
    printf("Eles of arr:\n");
    for (size_t i = 0; i < Generic_array_length(arr); i++) {
        printf("%d ", *(int*)Generic_array_at(arr, i));
    }
    printf("\n");
    return;
}

int main() {
    // Empty array new and free
    Array* int_arr = Generic_array_new(NULL, sizeof(int), 10);
    Generic_array_free(int_arr);

    // Array new with c array
    Array* int_arr_with_eles = Generic_array_new((int[]){1, 2, 3, 4, 5}, sizeof(int), 5);
    foreach_array(int_arr_with_eles);

    // set and at
    Generic_array_set(int_arr_with_eles, 0, &(int){10});
    int first_num = *(int*)Generic_array_at(int_arr_with_eles, 0);
    printf("Ele in array head: %d\n", first_num);
    
    Generic_array_free(int_arr_with_eles);

    return 0;
}