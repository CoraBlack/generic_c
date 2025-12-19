#pragma once

#include <stddef.h>
#include <stdbool.h>

/**
 * Dynamic array for any type.
 */
typedef struct Vec Vec;

/**
 * @brief Create a new vector.
 * @param eles      The array of elements.
 * @param ele_size  The size of element in array.
 * @param ele_count The number of elements.
 * @return A new vector pointer.
 */
Vec* Generic_vec_new(void* eles, size_t ele_size, size_t ele_count);

/**
 * @brief Free a vector pointer object.
 * @param vec The vector pointer.
 */
void Generic_vec_free(Vec* vec);

/**
 * @brief Get the length of vector.
 * @param vec The vector pointer.
 * @return The length of vector.
 */
size_t Generic_vec_length(Vec* vec);

/**
 * @brief Get the element at index.
 * @param vec The vector pointer.
 * @param index The index of element.
 * @return The element pointer.
 */
void* Generic_vec_at(Vec* vec, size_t index);

/**
 * @brief Set the element at index.
 * @param vec The vector pointer.
 * @param index The index of element.
 * @param ele The element pointer.
 * @return True if set successfully.
 */
bool Generic_vec_set(Vec* vec, size_t index, void* ele);

/**
 * @brief Append an element to vector.
 * @param vec The vector pointer.
 * @param ele The element pointer.
 * @return True if append successfully.
 */
bool Generic_vec_push_back(Vec* vec, void* ele);

/**
 * @brief Resize the vector.
 * @param vec The vector pointer.
 * @param new_size The new size of vector.
 */
void Generic_vec_resize(Vec* vec, size_t new_size);
