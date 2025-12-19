#include "include/array.h"
#include <stdlib.h>
#include <string.h>

struct Array {
    void* data;
    size_t length;
    size_t ele_size;
};


Array* Generic_array_new(void* eles, size_t ele_size, size_t ele_count) {
    Array* array = malloc(sizeof(Array));
    array->data  = malloc(ele_size * ele_count);

    if (eles == NULL){
        memset(array->data, 0, ele_count * ele_size);
    } else {
        memcpy(array->data, eles, ele_size * ele_count);
    }

    array->length   = ele_count;
    array->ele_size = ele_size;

    return array;
}


void Generic_array_free(Array* arr) {
    if (arr == NULL) return;

    free(arr->data);
    free(arr);
}


size_t Generic_array_length(Array* arr) {
    if (arr == NULL) return 0;
    return arr->length;
}


void* Generic_array_at (Array* arr, size_t index) {
    if (arr == NULL ||  index >= arr->length) return NULL;

    return arr->data + index * arr->ele_size;
}


bool Generic_array_set(Array* arr, size_t index, void* ele) {
    if (arr == NULL || ele == NULL || index >= arr->length) return false;

    char* index_ptr = arr->data + index * arr->ele_size;
    memcpy(index_ptr, ele, arr->ele_size);

    return true;
}
