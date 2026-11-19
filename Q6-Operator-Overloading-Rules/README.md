# Q6 – Operator Overloading Rules and Text Class

## Aim

To implement a dynamically allocated Text class using operator overloading and study the rules and limitations of operator overloading in C++.

## Problem Description

Develop a Text class for an SMS Gateway that supports text concatenation, equality comparison, inequality comparison, stream output, copying, and safe memory management.

## Concepts Used

- Operator overloading
- Dynamic memory allocation
- Copy constructor
- Copy assignment operator
- Destructor
- Friend functions
- Self-assignment protection
- Deep copying
- C++17 copy elision
- Performance measurement using chrono

## Algorithm

1. Define a Text class with a dynamically allocated character array.
2. Implement a constructor to allocate memory and copy the input message.
3. Implement a copy constructor to create an independent copy.
4. Implement the assignment operator with self-assignment protection.
5. Overload `+` to concatenate two Text objects.
6. Overload `==` and `!=` to compare messages.
7. Overload `<<` to display text.
8. Implement a destructor to release allocated memory.
9. Test empty messages, long messages, copying, assignment, and chained concatenation.
10. Verify that dynamically allocated memory is released.

## Pseudocode

```text
CLASS Text
    DECLARE dynamic character array
    DECLARE length

    CONSTRUCTOR(message)
        ALLOCATE memory
        COPY message

    COPY CONSTRUCTOR(other)
        ALLOCATE independent memory
        COPY other message

    ASSIGNMENT OPERATOR(other)
        IF objects are different
            ALLOCATE new memory
            COPY message
            RELEASE old memory
            UPDATE pointer and length
        RETURN current object

    OVERLOAD +
        ALLOCATE combined message
        CONCATENATE both messages
        RETURN new Text object

    OVERLOAD ==
        COMPARE messages

    OVERLOAD !=
        RETURN opposite of equality result

    DESTRUCTOR
        RELEASE allocated memory
END CLASS

MAIN
    TEST concatenation
    TEST comparison
    TEST copying and assignment
    TEST self-assignment
    TEST empty and long messages
    TEST chained addition
END MAIN
```

## Actual Output

```text
SMS Gateway - Text Operations
Combined message: Hello Student

Comparison Operations
first == second: False
first != second: True

Copy Constructor Test
Copied message: Hello Student

Copy Assignment Test
Assigned message: Hello Student

Self Assignment Test
After self assignment: Hello Student

Empty Message Test
Empty + first: Hello 

Long Message Test
Long message: This is a long SMS message used to test dynamic memory allocation and safe string operations.

Chained Addition Test
Final message: Hello Student Gateway
Copy constructor calls: 0

All tests completed successfully.
```

## Rules of Operator Overloading

1. Only existing C++ operators can be overloaded. New operators cannot be created.
2. At least one operand must be a user-defined type.
3. Operator precedence cannot be changed.
4. Operator associativity cannot be changed.
5. The number of operands cannot be changed.
6. Operators cannot be overloaded for built-in types alone.
7. The assignment operator (`=`) must be overloaded as a non-static member function.

### Operators That Cannot Be Overloaded

| Operator | Meaning |
|---|---|
| `::` | Scope resolution |
| `.` | Member access |
| `.*` | Pointer-to-member access |
| `?:` | Conditional operator |
| `sizeof` | Size determination |

## Operator Implementation Analysis

| Operator | Purpose | Implementation |
|---|---|---|
| `+` | Concatenates messages | Member function |
| `==` | Checks message equality | Member function |
| `!=` | Checks message inequality | Member function |
| `=` | Assigns one Text object to another | Member function |
| `<<` | Displays a message | Friend function |

Stream insertion uses a friend function because the left operand is an `ostream` object rather than a Text object.

## Memory Management Analysis

The Text class allocates memory dynamically using `new[]` and releases it using `delete[]`.

The copy constructor creates an independent character array, preventing two objects from sharing the same dynamically allocated memory.

The assignment operator checks for self-assignment and allocates replacement memory before releasing the old allocation.

The implementation follows the Rule of Three by providing a destructor, copy constructor, and copy assignment operator.

## Copy Elision Observation

The chained addition test reports zero copy-constructor calls.

This is valid under C++17 because guaranteed copy elision avoids certain temporary-object copies when returning objects by value.

It does not mean that no character data was copied during concatenation.

## Complexity Analysis

Let `n` and `m` represent the lengths of two messages.

| Operation | Time Complexity |
|---|---|
| Construction | O(n) |
| Copy construction | O(n) |
| Copy assignment | O(n) |
| Concatenation | O(n + m) |
| Equality comparison | O(min(n, m)) in the worst case |
| Inequality comparison | O(min(n, m)) in the worst case |
| Destruction | O(1) for releasing the allocation |

The concatenation implementation temporarily allocates a combined character buffer and then constructs the resulting Text object. This introduces an additional allocation and character-copy operation.

## Alternative Approach

The standard C++ `std::string` class provides built-in concatenation, comparison, copying, and automatic memory management.

Using `std::string` is generally safer and more convenient for real-world applications. The custom Text class is implemented here to demonstrate operator overloading and manual dynamic memory management.

## Performance Experiment – Custom Text vs std::string

### Objective

To compare the execution time of the custom Text class and the standard C++ `std::string` class during repeated string concatenation.

### Experimental Configuration

| Parameter | Value |
|---|---|
| Programming language | C++ |
| Standard | C++17 |
| Compiler optimization | `-O2` |
| Iterations | 100,000 |
| Custom implementation | Text class |
| Standard implementation | `std::string` |
| Timing method | `std::chrono::steady_clock` |

### Experimental Procedure

1. Create two Text objects containing fixed messages.
2. Create two equivalent `std::string` objects.
3. Perform 100,000 concatenation operations using the custom Text class.
4. Measure the execution time.
5. Perform 100,000 concatenation operations using `std::string`.
6. Measure the execution time.
7. Repeat the experiment five times.
8. Calculate the average execution time for both implementations.

### Actual Experimental Results

| Run | Custom Text (ms) | std::string (ms) |
|---|---:|---:|
| 1 | 12.0794 | 7.0690 |
| 2 | 13.0122 | 6.3893 |
| 3 | 12.7569 | 6.2781 |
| 4 | 12.5964 | 6.5713 |
| 5 | 15.7835 | 6.8332 |
| **Average** | **13.2457** | **6.6282** |

### Observations

- Both implementations completed 100,000 concatenation operations.
- The checksum was consistently 3,200,000 across all five runs.
- The custom Text class recorded an average execution time of 13.2457 ms.
- The standard `std::string` implementation recorded an average execution time of 6.6282 ms.
- The custom implementation required additional memory allocation and copying operations.
- `std::string` performed better in this particular experiment.

### Performance Analysis

The custom Text class creates a temporary combined character buffer during concatenation. It then allocates another buffer while constructing the resulting Text object.

This additional allocation and copying contributes to its higher execution time.

The standard `std::string` implementation uses an optimized library implementation and performed better in the measured experiment.

The execution times may vary depending on the processor, compiler, optimization settings, and system workload.

### Conclusion of Performance Experiment

The standard `std::string` implementation demonstrated better performance than the custom Text class in this experiment. The comparison highlights the importance of efficient memory allocation and copying in string operations.

## Result

The Text class was successfully implemented and tested. Concatenation, comparison, copying, assignment, self-assignment, empty messages, long messages, and chained addition were verified.

The performance experiment was also completed successfully. The results demonstrated that the standard `std::string` implementation was faster than the custom Text class under the tested conditions.