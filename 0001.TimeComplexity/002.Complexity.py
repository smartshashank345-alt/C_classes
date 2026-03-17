# --------------------------------------------
# 📌 Convention in Space Complexity:
# --------------------------------------------
# In many analyses, the input (e.g., the list numbers) is considered part of the problem and not counted in the auxiliary space complexity. If we only consider the extra space used by the algorithm (auxiliary space), the space complexity is O(1).
# If the input space is included (e.g., if the list is created within the algorithm), the total space complexity is O(n).

# --------------------------------------------
# 📌 1. Simple Function with Constant Time Complexity
# --------------------------------------------

print("Hello")                # O(1) - Single print operation

# --------------------------------------------
# 📌 2. Single Print Statement
# --------------------------------------------
def PrintHello():
    print("Hello Printing")      # O(1) - Single print operation

print("Hello")   # O(1) - Uncomment to run, single operation
PrintHello()     # O(1) - Function call
#Total: O(1) + O(1) = O(1)


# --------------------------------------------
# 📌 3. Loop Calling Function - Linear Time Complexity
# --------------------------------------------

for i in range(10):              # O(n) - Loop runs n times (n=10)
    PrintHello()                 # O(1) - Function call
# Total: O(n) * O(1) = O(n)


# --------------------------------------------
# 📌 4. Loop with Multiple Operations - Linear Time Complexity
# --------------------------------------------

for i in range(10):              # O(n) - Loop runs n times (n=10)
    PrintHello()                 # O(1) - Function call
    x = 20                       # O(1) - Assignment
    print("Value of x is :", x)  # O(1) - Print operation
    # Inner loop: O(1) + O(1) + O(1) = O(3)
# Total: O(n) * O(3) = O(3n) = O(n)


# --------------------------------------------
# 📌 5. Function with Loop - Linear Time Complexity
# --------------------------------------------

def UseLoopsForPrinting():
    for i in range(6):           # O(n) - Loop runs n times (n=6)
        print("I am inside the function")  # O(1) - Print operation
    # Total: O(n) * O(1) = O(n)


# --------------------------------------------
# 📌 6. Nested Loop Structure - Quadratic Time Complexity
# --------------------------------------------
 
for i in range(10):              # O(n) - Outer loop runs n times (n=10)
    UseLoopsForPrinting()        # O(n) - Function with loop
    x = 20                       # O(1) - Assignment
    print("Value of x is :", x)  # O(1) - Print operation
    # Inner: O(n) + O(1) + O(1) = O(n + 2)
# Total: O(n) * O(n + 2) = O(n^2 + 2n) = O(n^2)


# --------------------------------------------
# 📌 7. Sum of List Elements - Linear Time and Space Complexity
# --------------------------------------------

sum = 0                          # O(1) - Variable initialization
myList = [12, 22, 11, 2, 34, 67, 89, 36]  # O(1) - List creation, but O(n) space
for i in range(len(myList)):     # O(n) - Loop runs n times (n=length of list)
    sum += myList[i]             # O(1) - Addition and assignment
print(sum)                       # O(1) - Print operation
# Time: O(1) + O(1) + O(n) * O(1) + O(1) = O(n + 3) = O(n)
# Space: O(n) for the list, O(1) for variables = O(n)


# --------------------------------------------
# 📌 8. Nested Loops for Counting - Quadratic Time Complexity
# --------------------------------------------

count = 0                        # O(1) - Variable initialization
for i in range(10):              # O(n) - Outer loop runs n times (n=10)
    for j in range(10):          # O(n) - Inner loop runs n times (n=10)
        print(count, end=" ")    # O(1) - Print operation
        count += 1               # O(1) - Increment
    print()                      # O(1) - New line
# Time: O(1) + O(n) * (O(n) * (O(1) + O(1)) + O(1))
#     = O(1) + O(n) * (O(n) * O(2) + O(1))
#     = O(1) + O(n) * (O(n) + O(1))
#     = O(1) + O(n^2 + n) = O(n^2)
# Space: O(1) - Only uses a few variables


# --------------------------------------------
# 📌 9. Finding Maximum in List - Linear Time Complexity
# --------------------------------------------
def find_max(numbers):
    max_num = numbers[0]         # O(1) - Assignment
    for num in numbers:          # O(n) - Loop runs n times (n=length of list)
        if num > max_num:        # O(1) - Comparison
            max_num = num        # O(1) - Assignment
    print(max_num)               # O(1) - Print operation
numbers = [12, 23, 45, 67, 78, 79, 20]  # O(1) - List creation, but O(n) space
find_max(numbers)                # O(1) - Function call
# Time: O(1) + O(n) * (O(1) + O(1)) + O(1) + O(1) = O(n + 4) = O(n)
# Space: O(n) for the list, O(1) for variables = O(n)