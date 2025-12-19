#pragma once

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Save and boundary checking array for any type. 
 */
typedef struct Array Array;

/**
 * @brief Create a new array.
 * @param eles The elements to insert into the array.
 * @param ele_size The size of each element.
 * @param ele_count The number of elements.
 * @return The created array pointer.
 */
Array* Generic_array_new(void* eles, size_t ele_size, size_t ele_count);

/**
 * @brief Free the array.
 * @param arr The array to free.
 */
void Generic_array_free(Array* arr);

/**
 * @brief Get the length of the array.
 * @param arr The array to get the length of.
 * @return The length of the array.
 */
size_t Generic_array_length(Array* arr);

/**
 * @brief Get the element at the given index.
 * @param arr The array to get the element from.
 * @param index The index of the element.
 * @return The element at the given index.
 */
void* Generic_array_at (Array* arr, size_t index);

/**
 * @brief Set the element at the given index.
 * @param arr The array to set the element in.
 * @param index The index of the element.
 * @param ele The element to set.
 * @return True if the element was set, false otherwise.
 */
bool Generic_array_set(Array* arr, size_t index, void* ele);
