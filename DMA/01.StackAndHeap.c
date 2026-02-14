/*
 * ====================================================================
 *  Where is my Variable ? - - - Stack Or Heap
 * ====================================================================
 *
 *
 * STACK:
 *   - Local variables (inside functions) are stored on the stack.
 *   - Memory is automatically allocated when a function is called,
 *     and automatically freed when the function returns.
 *   - Size is limited (typically a few MB). Too many local variables
 *     or deep recursion can cause a "stack overflow".
 *
 * HEAP:
 *   - Dynamically allocated memory (malloc, calloc, realloc) lives here.
 *   - You control when memory is allocated and when it is freed.
 *   - Size is limited only by available system RAM.
 *   - You must use pointers to access heap memory.
 *
 * HOW THEY ARE LINKED:
 *   A pointer variable (on the stack) holds the address of a heap block.
 *   That's how your program reaches into the heap.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ----- STACK EXAMPLE -----
    int stack_var = 42;                   // 'stack_var' lives on the stack
    int stack_array[5] = {1, 2, 3, 4, 5}; // whole array on the stack

    printf("STACK:\n");
    printf("  stack_var = %d (address %p)\n", stack_var, (void *)&stack_var);
    printf("  stack_array[0] = %d (address %p)\n", stack_array[0], (void *)&stack_array[0]);

    // ----- HEAP EXAMPLE -----
    int *heap_ptr;                         // 'heap_ptr' itself is on the stack
    heap_ptr = (int *)malloc(sizeof(int)); // allocate 1 int on the heap
    if (heap_ptr == NULL)
    {
        printf("Heap allocation failed!\n");
        return 1;
    }
    *heap_ptr = 99; // store value in heap memory

    printf("\nHEAP:\n");
    printf("  heap_ptr (stack) holds address: %p\n", (void *)heap_ptr);
    printf("  heap memory contains: %d\n", *heap_ptr);
    printf("  address of heap memory: %p\n", (void *)heap_ptr);

    // Free heap memory
    free(heap_ptr);
    heap_ptr = NULL; // avoid dangling pointer

    return 0;
}