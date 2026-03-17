# --------------------------------------------
# 📌 CONSTANT TIME — O(1)
# --------------------------------------------

a = 100         # 1 unit
b = 20000       # 1 unit
print(a + b)    # 1 unit

# Total: 3 units --> O(1)

# Accessing element by index — O(1)
myList = [12, 23, 34, 56, 78]
print(myList[2])  # O(1)


# --------------------------------------------
# 📌 CONDITIONAL STATEMENTS — O(1)
# --------------------------------------------

x = 10
if x < 10:
    print("x is smaller")
elif x > 10:
    print("x is greater")
else:
    print("x is 10")

# A fixed number of comparisons → O(1)


# --------------------------------------------
# 📌 LINEAR TIME — O(n)
# --------------------------------------------

# One loop through n elements
for i in range(100):
    print(i)  # O(n)

# Searching an item in a list — O(n)
myList = [12, 23, 34, 56, 78]
item = 56
for i in myList:
    if i == item:
        print("Item found")


# --------------------------------------------
# 📌 NESTED LOOPS — O(n^2)
# --------------------------------------------

# Times table: Loop inside loop
for i in range(1, 11):
    for j in range(1, 11):
        print(i * j, end=" ")
    print()

# Outer loop → n
# Inner loop → n
# Total → n * n = O(n^2)


# --------------------------------------------
# 📌 SEPARATE LOOPS (not nested) — O(n + n) = O(n)
# --------------------------------------------

for i in range(10):
    print("Loop 1:", i)

for j in range(10):
    print("Loop 2:", j)

# Two separate O(n) loops → O(n + n) = O(2n) → Drop constants → O(n)


# --------------------------------------------
# 📌 O(n/2) → Still O(n)
# --------------------------------------------

for i in range(1, 11, 2):  # Step of 2
    print(i)

# Even if we skip steps, complexity is still linear → O(n/2) → O(n)


# --------------------------------------------
# 📌 LOGARITHMIC TIME — O(log n)
# --------------------------------------------

i = 1
while i < 1000:
    print(i)
    i = i * 2

# Each time, i doubles → log₂(n) steps → O(log n)


# --------------------------------------------
# 📌 DOMINANT TERMS — DROP Lower Order Terms & Constants
# --------------------------------------------

# Suppose a function does: n^2 + 5n + 10 operations

n = 100
result = 0

# O(n^2)
for i in range(n):
    for j in range(n):
        result += 1

# O(n)
for i in range(n):
    result += 1

# Constant
result += 10

# Total = O(n^2 + n + 1) → Drop lower terms → O(n^2)


# --------------------------------------------
# 📌 SUMMARY
# --------------------------------------------
# O(1)     → Constant time (e.g., index access, simple operations)
# O(n)     → Linear time (e.g., single loops)
# O(n^2)   → Quadratic time (e.g., nested loops)
# O(log n) → Logarithmic time (e.g., doubling/halving in loops)
# O(n^2 + n + 1) → Dominated by highest degree term → O(n^2)

