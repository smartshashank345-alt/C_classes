# Assignment: Time and Space Complexity Analysis

# Question 1: Print each element of a list
def print_elements(arr):
    for i in arr:
        print(i)

arr = [1, 2, 3, 4, 5]
print_elements(arr)

# Time Complexity: 
# Space Complexity: 

# Question 2: Sum of squares of numbers from 1 to n
def sum_squares(n):
    total = 0
    for i in range(1, n + 1):
        total += i * i
    return total

n = 5
result = sum_squares(n)

# Time Complexity: 
# Space Complexity: 

# Question 3: Check if a list has duplicates
def has_duplicates(arr):
    seen = set()
    for num in arr:
        if num in seen:
            return True
        seen.add(num)
    return False

arr = [1, 2, 2, 3, 4]
has_duplicates(arr)

# Time Complexity: 
# Space Complexity: 

# Question 4: Nested loop printing pairs
def print_pairs(n):
    for i in range(n):
        for j in range(n):
            print(i, j)

n = 4
print_pairs(n)

# Time Complexity: 
# Space Complexity: 

# Question 5: Reverse a list in-place
def reverse_list(arr):
    left = 0
    right = len(arr) - 1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    return arr

arr = [1, 2, 3, 4, 5]
reverse_list(arr)

# Time Complexity: 
# Space Complexity: 

# Question 6: Fibonacci sequence (iterative)
def fibonacci(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
    return b

n = 6
fibonacci(n)

# Time Complexity: 
# Space Complexity: 

# Question 7: Count occurrences in a list
def count_occurrences(arr, target):
    count = 0
    for num in arr:
        if num == target:
            count += 1
    return count

arr = [1, 2, 3, 2, 4, 2]
target = 2
count_occurrences(arr, target)

# Time Complexity: 
# Space Complexity: 

# Question 8: Matrix multiplication
def matrix_multiply(A, B):
    n = len(A)
    result = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += A[i][k] * B[k][j]
    return result

A = [[1, 2], [3, 4]]
B = [[5, 6], [7, 8]]
matrix_multiply(A, B)

# Time Complexity: 
# Space Complexity: 

# Question 9: Merge two sorted lists
def merge_sorted_lists(list1, list2):
    merged = []
    i, j = 0, 0
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            merged.append(list1[i])
            i += 1
        else:
            merged.append(list2[j])
            j += 1
    merged.extend(list1[i:])
    merged.extend(list2[j:])
    return merged

list1 = [1, 3, 5]
list2 = [2, 4, 6]
merge_sorted_lists(list1, list2)

# Time Complexity: 
# Space Complexity: 

# Question 10: Find all subsets of a list
def find_subsets(arr):
    subsets = [[]]
    for num in arr:
        new_subsets = [subset + [num] for subset in subsets]
        subsets.extend(new_subsets)
    return subsets

arr = [1, 2, 3]
find_subsets(arr)

# Time Complexity: 
# Space Complexity: 

