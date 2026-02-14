# Dynamic Memory Allocation

## 1. Memory Architecture: Stack vs. Heap

Understanding dynamic allocation requires distinguishing between the two primary memory zones used during program execution.

### **The Stack (Static/Automatic Memory)**
* **Structure:** A LIFO (Last-In, First-Out) structure. Highly organized and sequential.
* **Allocation:** **Automatic**. Memory is reserved when a function is called and released when it returns.
* **Lifetime:** **Scope-bound**. Variables exist only within their defining block or function.
* **Limitations:**
    * **Fixed Size:** Memory requirements must be known at compile time.
    * **Size Limit:** Finite space; exceeding it causes a **Stack Overflow**.

### **The Heap (Dynamic/Free Store)**
* **Structure:** An unstructured, large pool of free memory.
* **Allocation:** **Manual**. The programmer explicitly requests blocks of specific sizes.
* **Lifetime:** **Persistent**. Data remains allocated until explicitly freed, spanning across function calls.
* **Key Feature:** Allows for variable-sized data structures (arrays, linked lists) whose size is determined at runtime.

---

## 2. The Core Functions (`<stdlib.h>`)

These functions manage the **Heap**.

### **1. `malloc` (Memory Allocation)**
* **Logic:** Requests a contiguous block of memory of a specific size (in bytes).
* **Behavior:**
    * Returns a `void*` pointer to the first byte of the allocated block.
    * **Does NOT clear memory.** The block contains **garbage values** (random residual data).
    * Returns `NULL` if the system cannot satisfy the request (e.g., out of RAM).

### **2. `calloc` (Contiguous Allocation)**
* **Logic:** Requests a block for an array of $N$ elements, each of size $X$.
* **Behavior:**
    * Allocates the total required memory ($N \times X$).
    * **Initializes memory to ZERO.** Every bit is set to 0.
    * Slightly slower than `malloc` due to the zero-initialization overhead but safer for preventing logic errors from garbage data.

### **3. `realloc` (Re-Allocation)**
* **Logic:** Resizes an existing memory block to a new size (larger or smaller).
* **Behavior:**
    * **Expansion (In-place):** If adjacent memory is free, it simply extends the current block.
    * **Expansion (Relocation):** If adjacent memory is occupied, it allocates a **new** block elsewhere, **copies** the existing data, and frees the old block automatically.
    * **Shrinking:** Truncates the block, releasing the tail end back to the heap.
    * **Note:** The pointer address may change during this operation.

### **4. `free` (De-allocation)**
* **Logic:** Returns a previously allocated block back to the system.
* **Behavior:**
    * Marks the memory address as "available" in the heap manager.
    * Does not clear the data, just the reservation.
* **Critical Concepts:**
    * **Memory Leak:** Failing to `free` memory causes it to remain occupied until the program terminates, consuming RAM indefinitely.
    * **Dangling Pointer:** A pointer that references a memory location after it has been freed. Accessing this causes undefined behavior (crashes).

---

## 3. Quick Comparison

| Feature | `malloc` | `calloc` | `realloc` |
| :--- | :--- | :--- | :--- |
| **Purpose** | Raw allocation | Array allocation | Resizing |
| **Initialization** | **Garbage** (Random) | **Zero** (Clean) | **Preserves Data** (New space is garbage) |
| **Parameters** | Total Size (bytes) | Count & Element Size | Old Pointer & New Size |
| **Performance** | Fastest | Slower (Zeroing overhead) | Variable (Copying overhead) |