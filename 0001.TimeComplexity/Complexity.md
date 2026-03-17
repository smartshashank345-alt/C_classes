### 🕔Time and Space Complexity 
Time and space complexity help us evaluate how efficiently an algorithm runs as input size grows. Time complexity estimates how long an algorithm takes, while space complexity measures the memory it uses. Both are expressed in **Big O notation**, focusing on the worst-case scenario.

##### 👌 Key Definitions

* **Time Complexity**: How the number of steps in an algorithm increases with input size $n$.
* **Space Complexity**: How much memory (RAM) the algorithm uses during execution, including input and temporary storage.
* **Auxiliary Space**: Memory used excluding input (e.g., temporary arrays).
* **Total Space**: Input storage + auxiliary space.

##### ✅**Amortized Time Complexity**

Sometimes, an operation in an algorithm is **usually fast**, but **occasionally slow**.

💡 Instead of just looking at the slow cases, **amortized analysis** asks:

> What’s the **average time per operation** if we do this operation many times?

###### 🧵 List Append in Python

```python
my_list = []
for i in range(1000):
    my_list.append(i)
```

* **Most of the time**, `append()` adds the item in constant time → `O(1)`
* But **sometimes**, Python has to **resize the list** (make a bigger one and copy elements) → this takes more time, maybe `O(n)`

📊 Still, over many appends, the **average time per append stays low** — like constant time.


> *Hence we say: Appending to a list is O(1) amortized time*


##### 🎯 Key Idea:
Amortized time =
**(Total cost of all operations)** ÷ **(Number of operations)**

##### 🏆 Real-life Analogy
Imagine you buy a bus pass for ₹1000 and ride the bus 100 times.

* Some rides might be very short.
* Some rides might be long.
* But on **average**, you paid ₹10 per ride.

💡 **Amortized cost per ride = ₹10**

##### Common Time Complexities
| Complexity    | Description   | Example                          |
| ------------- | ------------- | -------------------------------- |
| $O(1)$        | Constant time | Accessing an array element       |
| $O(\log n)$   | Logarithmic   | Binary search                    |
| $O(n)$        | Linear        | Looping through a list           |
| $O(n \log n)$ | Linearithmic  | Merge sort                       |
| $O(n^2)$      | Quadratic     | Nested loops (e.g., bubble sort) |
| $O(2^n)$      | Exponential   | Naive recursive Fibonacci        |
| $O(n!)$       | Factorial     | Brute-force permutations         |

##### Common Space Complexities

| Complexity | Description     | Example                        |
| ---------- | --------------- | ------------------------------ |
| $O(1)$     | Constant space  | Iterative sum                  |
| $O(n)$     | Linear space    | Copying input to another array |
| $O(n^2)$   | Quadratic space | 2D matrix storage              |

### Time Complexity

1. Identify loops and recursions.
2. Count operations as functions of $n$.
3. Drop lower-order terms and constants.

**Example**:

```python
for i in range(n):
    for j in range(n):
        print(i, j)
```

* Runs $n^2$ times → **$O(n^2)$**

### Space Complexity
1. Count memory used by variables and data structures.
2. Include recursion stack if applicable.

**Example**:

```python
def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total
```

* Uses one variable → **$O(1)$**

## Key Rules

* Focus on **worst-case** for reliability.
* **Ignore constants** and lower-order terms.
* Nested loops multiply: 2 loops over $n$ → $O(n^2)$
* Recursion → solve using **recurrence relations** or **Master’s Theorem**.
####
> Constant time complexity ($O(1)$) means the execution time or memory usage doesn't change with input size.
#### Operations/Statements with $O(1)$ Complexity

1. **Arithmetic Operations**: Addition, subtraction, multiplication, division, modulo, etc., e.g., `x + y`, `a * b`.
######
2. **Variable Assignments**: Assigning a value to a variable, e.g., `x = 5`.
######
3. **Accessing Array/List Elements by Index**: Retrieving an element using its index, e.g., `arr[3]`.
######
4. **Accessing/Setting Dictionary Key-Value Pairs**: Getting or setting a value by key, e.g., `d['key']`, `d['key'] = value` (average case, assuming good hash function).
######
5. **Boolean Operations**: Logical operations like `and`, `or`, `not`, e.g., `x and y`.
######
6. **Comparison Operations**: Equality, inequality, greater/less than, e.g., `x == y`, `a < b`.
######
7. **Pushing/Popping from Stack (List as Stack)**: Appending or popping from the end of a list, e.g., `lst.append(x)`, `lst.pop()` (amortized $O(1)$).
######
8. **Bitwise Operations**: Operations like `&`, `|`, `^`, `<<`, `>>`, e.g., `x & y`.
######
9. **Returning a Value**: Using `return` in a function, e.g., `return x`.

**Note**: Some operations, like dictionary lookups, are $O(1)$ on average but can be $O(n)$ in rare worst-case scenarios (e.g., hash collisions). For this response, we focus on average-case $O(1)$.

Code examples:
#####  Arithmetic Operation

```python
def add_numbers(a, b):
    result = a + b  # O(1) - Addition is a single operation
    return result

# Test
print(add_numbers(5, 3))  # Output: 8
```

**Why $O(1)$**: The addition operation (`a + b`) is a single CPU instruction, independent of input size. The function takes the same time whether the numbers are small or large.

##### Array Element Access

```python
def get_element(arr, index):
    return arr[index]  # O(1) - Direct memory access by index

# Test
arr = [10, 20, 30, 40, 50]
print(get_element(arr, 2))  # Output: 30
```

**Why $O(1)$**: Accessing an element by index in a Python list (array) involves direct memory addressing, which takes constant time regardless of the list’s length.

##### Dictionary Lookup

```python
def get_value(dictionary, key):
    return dictionary[key]  # O(1) average case - Hash table lookup

# Test
d = {'name': 'Alice', 'age': 25, 'city': 'New York'}
print(get_value(d, 'age'))  # Output: 25
```

**Why $O(1)$**: Python dictionaries use hash tables, where the key is hashed to find the corresponding value in constant time (average case). Worst-case is $O(n)$ due to collisions, but this is rare with good hashing.

#####  Variable Assignment and Comparison

```python
def check_equal(a, b):
    x = a  # O(1) - Assignment
    return x == b  # O(1) - Comparison

# Test
print(check_equal(10, 10))  # Output: True
```

**Why $O(1)$**: Assigning a value to a variable (`x = a`) and comparing two values (`x == b`) are single operations, unaffected by input size.

##### Stack Push and Pop (List as Stack)

```python
def stack_operations():
    stack = []
    stack.append(42)  # O(1) - Append to end of list
    value = stack.pop()  # O(1) - Pop from end of list
    return value

# Test
print(stack_operations())  # Output: 42
```

**Why $O(1)$**: Appending to the end of a Python list (`append`) and removing the last element (`pop`) are amortized constant time operations, as Python’s dynamic array resizes infrequently.

##### Bitwise Operation

```python
def bitwise_and(a, b):
    return a & b  # O(1) - Bitwise AND operation

# Test
print(bitwise_and(5, 3))  # Output: 1 (5 = 101, 3 = 011, 101 & 011 = 001)
```

**Why $O(1)$**: Bitwise operations like AND (`&`) are performed in a single CPU cycle on fixed-size integers, regardless of the values.

##### Boolean Operation

```python
def check_conditions(x, y):
    return x > 0 and y < 10  # O(1) - Boolean operation

# Test
print(check_conditions(5, 8))  # Output: True
```

**Why $O(1)$**: Boolean operations (`and`) and comparisons (`x > 0`, `y < 10`) are single operations, executed in constant time.




