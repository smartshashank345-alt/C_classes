# Sorting Algorithms – Complete Complexity Guide

A clean and structured reference sheet for interviews and revision.

---

## 📊 Complexity Comparison Table

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable | In-Place | Other Characteristics |
|------------|------------|--------------|------------|------------------|--------|----------|------------------------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Simple; adaptive with early-exit optimization |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | No | Yes | Minimizes swaps; not adaptive |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Efficient for small or nearly sorted data; online |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No (arrays) | Divide & conquer; ideal for linked lists |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) stack | No | Yes | Very fast in practice; pivot dependent |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Yes | Based on heap structure; not stable |
| **Counting Sort** | O(n + k) | O(n + k) | O(n + k) | O(k) | Yes | No | Non-comparison; integers only |
| **Radix Sort** | O(d(n + b)) | O(d(n + b)) | O(d(n + b)) | O(n + b) | Yes | No | Digit-based; uses counting sort internally |
| **Bucket Sort** | O(n + k) | O(n + k) | O(n²) | O(n + k) | Depends | No | Performance depends on distribution |
---

## 📌 Detailed Best and Worst Case Explanations

---

### Bubble Sort
**Best Case:**  
Already sorted array with early-exit flag enabled. Only one pass needed.  

**Worst Case:**  
Reverse sorted array. Maximum swaps and passes required.

---

### Selection Sort
**Best Case:**  
Even if already sorted, algorithm still scans entire unsorted portion.  

**Worst Case:**  
Reverse or random order. Comparisons remain the same as best case.

Key Insight:  
Selection sort always performs the same number of comparisons.

---

### Insertion Sort
**Best Case:**  
Already sorted or nearly sorted input. Minimal shifting.  

**Worst Case:**  
Reverse sorted array. Every element must shift across the sorted portion.

---

### Merge Sort
**Best Case:**  
Input order does not matter. Always divides and merges consistently.  

**Worst Case:**  
Same as best case. Number of operations remains proportional to n log n.

---

### Quick Sort
**Best Case:**  
Pivot splits array into two nearly equal halves each time. Balanced recursion tree.

**Worst Case:**  
Pivot always smallest or largest element. Happens with poor pivot strategy on sorted input. Creates unbalanced partitions.

---

### Heap Sort
**Best Case:**  
Input order does not affect heap building and extraction.

**Worst Case:**  
Same as best case. Always n log n.

---

### Counting Sort
**Best Case:**  
Small integer range relative to n.

**Worst Case:**  
Large value range k. Still n + k but memory heavy.

---

### Radix Sort
**Best Case:**  
Small number of digits d.

**Worst Case:**  
Large digit count. Complexity increases proportionally to d.

---

### Bucket Sort
**Best Case:**  
Uniform distribution across buckets. Each bucket small.

**Worst Case:**  
All elements fall into one bucket. Degrades to quadratic if inner sort is quadratic.

---

### Shell Sort
**Best Case:**  
Efficient gap sequence leads to near n log n performance.

**Worst Case:**  
Poor gap sequence can lead to quadratic behavior.

---

### Tim Sort
**Best Case:**  
Input contains long natural runs or already sorted segments.

**Worst Case:**  
Still guarantees n log n due to merge sort foundation.

---

## 🔎 Quick Decision Guide

- Nearly sorted data → Insertion Sort or Tim Sort  
- Guaranteed n log n → Merge Sort or Heap Sort  
- Fastest average case → Quick Sort  
- Integer limited range → Counting or Radix Sort  
- Stable required → Merge, Insertion, Tim, Counting  

---

## 🧠 Key Symbols

- n = number of elements  
- k = value range or number of buckets  
- d = number of digits  
- b = base per digit  

---

