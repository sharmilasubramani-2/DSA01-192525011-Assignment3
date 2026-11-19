# Q2 - Copy Constructors: Shallow and Deep Copies

## 1. Aim

To implement copy constructors, copy assignment operators and destructors in C++ to achieve independent object copies and prevent memory management errors.

## 2. Problem Description

A Prescription object stores medicine names in a dynamically allocated array. Copying an object using the default copy constructor copies only the pointer address, resulting in shared memory and potential double deletion.

The implementation uses deep copying to ensure independent memory allocation.

## 3. Concepts Used

- Copy Constructor
- Deep Copy
- Shallow Copy
- Copy Assignment Operator
- Destructor
- Self-assignment Protection
- Dynamic Memory Allocation
- Rule of Three

## 4. Algorithm

1. Create a Prescription class with an integer size and a dynamically allocated string array.
2. Implement a parameterized constructor.
3. Implement a copy constructor that allocates independent memory.
4. Copy every medicine name into the newly allocated array.
5. Implement the copy assignment operator.
6. Check for self-assignment before copying.
7. Release previously allocated memory.
8. Implement the destructor using delete[].
9. Create prescription objects and verify their independence.
10. Compile and execute the program.

## 5. Pseudocode

BEGIN

Create Prescription class.

Initialize medicine count and dynamic array.

Define copy constructor:
- Allocate a new array.
- Copy every medicine.

Define copy assignment:
- Check self-assignment.
- Allocate new memory.
- Copy elements.
- Release previous memory.
- Return current object.

Define destructor:
- Release allocated memory.

Create prescription objects.

Modify copied objects.

Display all prescription records.

END

## 6. Expected Output

```text
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS
```

## 7. Rule of Three

The Rule of Three states that if a class requires a user-defined destructor, copy constructor or copy assignment operator, it generally requires all three.

These functions manage dynamically allocated resources and prevent incorrect memory sharing and double deletion.

## 8. Three Situations Where Copy Constructors Are Called

1. Initializing an object using another object.
2. Passing an object to a function by value.
3. Returning an object by value when copy construction is performed.

Modern C++ may apply copy elision in some return-by-value situations.

## 9. Shallow Copy vs Deep Copy

| Feature | Shallow Copy | Deep Copy |
|---|---|---|
| Memory allocation | Shared memory | Independent memory |
| Pointer | Same address | Different addresses |
| Modification | May affect both objects | Independent |
| Memory safety | Risk of double deletion | Safe with correct ownership |
| Complexity | O(1) | O(n) |

## 10. Complexity Analysis

Let n represent the number of medicines.

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Shallow copy | O(1) | O(1) |
| Deep copy | O(n) | O(n) |
| Copy assignment | O(n) | O(n) |
| Destructor | O(n) | O(1) |

## 11. Alternative Concept: std::vector

Using std::vector<std::string> automatically manages dynamic memory and provides independent copies.

The compiler-generated copy constructor and assignment operator perform element-wise copying.

This follows the Rule of Zero, reducing manual memory management.

## 12. Shallow Copy Experiment

The shallow_copy.cpp experiment demonstrates pointer sharing between two objects.

The program creates an original object and initializes another object using its copy constructor. Both objects point to the same dynamically allocated integer.

After modifying the copied object's value, the original object's value also changes.

### Observation

- Both objects contain the same memory address.
- Modifying one object affects the other.
- Independent ownership cannot be achieved through this shallow-copy implementation.

The experiment uses controlled memory cleanup to avoid double deletion.

## 13. Copy Performance Experiment

The copy_timing.cpp experiment compares shallow copying and deep copying using the C++ chrono library.

### Experimental Configuration

| Parameter | Value |
|---|---|
| Array size | 1,024 integers |
| Number of iterations | 10,000 |
| Compiler standard | C++17 |
| Optimization | -O2 |
| Measurement | std::chrono::steady_clock |
| Repeated runs | 5 |

### Experimental Results

| Run | Shallow Copy (ms) | Deep Copy (ms) |
|---|---:|---:|
| 1 | 0.0060 | 6.2332 |
| 2 | 0.0098 | 7.2241 |
| 3 | 0.0057 | 7.7166 |
| 4 | 0.0060 | 6.1734 |
| 5 | 0.0056 | 6.2172 |
| Average | 0.00662 | 6.7129 |

Checksum for all five runs: 10041840.

### Observation

Shallow copying takes less time because it copies only the pointer address. Deep copying requires allocating separate memory and copying all array elements.

The measurements demonstrate the additional cost of independent memory allocation and copying. Actual execution times may vary depending on the system and compiler.

## 14. Compilation and Execution

Main program:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main
```

Shallow-copy experiment:

```bash
g++ -std=c++17 -Wall -Wextra experiments/shallow_copy.cpp -o experiments/shallow_copy
```

Copy-performance experiment:

```bash
g++ -std=c++17 -O2 -Wall -Wextra experiments/copy_timing.cpp -o experiments/copy_timing
```

## 15. Conclusion

The experiment demonstrates the difference between shallow and deep copying in C++.

Shallow copying shares the same memory address, which can lead to unintended modifications and memory-management problems.

Deep copying creates independent memory for each object, ensuring that modifications to one object do not affect another.

The copy-performance experiment also demonstrates the additional execution cost associated with allocating and copying dynamic memory.

The Rule of Three provides a systematic approach to managing dynamically allocated resources through copy constructors, copy assignment operators and destructors.