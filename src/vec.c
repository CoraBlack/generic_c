#include "include/vec.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


struct Vec {
    void* data;
    size_t ele_size;
    size_t length;
    size_t capacity;
};


Vec* Generic_vec_new(void* eles, size_t ele_size, size_t ele_count) {
    Vec* vec  = malloc(sizeof(Vec));
    // Allocate double size memory for the vector data pointer
    vec->data = malloc(2 * ele_size * ele_count);
    memset(vec->data, 0, 2 * ele_size * ele_count);

    __auto_type data_size = ele_size * ele_count;
    if (eles != NULL) {
        memcpy(vec->data, eles, data_size);
    }

    // Set the vector fileds
    vec->ele_size = ele_size;
    vec->length   = ele_count;
    vec->capacity = 2 * ele_count;

    return vec;
}


void Generic_vec_free(Vec* vec) {
    if (vec == NULL) {
        return;
    }

    free(vec->data);
    free(vec);
}


size_t Generic_vec_length(Vec* vec) {
    if (vec == NULL) {
        return 0;
    }

    return vec->length;
}


void* Generic_vec_at(Vec* vec, size_t index) {
    if (vec == NULL || index >= vec->length) {
        return NULL;
    }

    return vec->data + index * vec->ele_size;
}


bool Generic_vec_set(Vec* vec, size_t index, void* ele) {
    if (vec == NULL || ele == NULL || index >= vec->length) {
        return false;
    }

    char* head = vec->data + index * vec->ele_size;
    memcpy(head, ele, vec->ele_size);
    return true;
}


bool Generic_vec_push_back(Vec* vec, void* ele) {
    if (vec == NULL || ele == NULL) {
        return false;
    }

    size_t index = vec->length; vec->length += 1;
    if (vec->capacity <= vec->length) {
        Generic_vec_resize(vec, vec->capacity * 2);
    }

    return Generic_vec_set(vec, index, ele);
}


void Generic_vec_resize(Vec* vec, size_t new_capacity) {
    if (vec == NULL) {
        return;
    }

    size_t old_capacity = vec->capacity;

    size_t new_size = new_capacity * vec->ele_size;
    void* new_arr = malloc(new_size);

    // copy old data to new one
    memset(new_arr, 0, new_size);
    memcpy(new_arr, vec->data, vec->length * vec->ele_size);

    // swap vec and free old vec
    free(vec->data);
    vec->data = new_arr;
    vec->capacity = new_capacity;
    vec->length = new_capacity < old_capacity ? vec->capacity : vec->length;

    return;
}
