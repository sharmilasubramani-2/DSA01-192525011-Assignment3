# Q5 – Increment, Comparison and Subscript Operator Overloading

## Aim

To implement prefix and postfix increment, comparison, and subscript operators using operator overloading in C++.

## Problem Description

Develop a NumberList class that demonstrates increment operations, object comparisons, and array element access using overloaded operators. Implement bounds checking to prevent invalid array access.

## Concepts Used

- Operator overloading
- Prefix increment operator (`++obj`)
- Postfix increment operator (`obj++`)
- Equality operator (`==`)
- Greater-than operator (`>`)
- Subscript operator (`[]`)
- Const member functions
- Exception handling
- STL vector

## Algorithm

1. Define a NumberList class containing an integer value and a vector of elements.
2. Initialize objects using a parameterized constructor.
3. Overload prefix increment to increase the value and return the current object by reference.
4. Overload postfix increment using an integer dummy parameter and return the previous object.
5. Overload equality to compare the values of two objects.
6. Overload greater-than to compare the values of two objects.
7. Overload the subscript operator to access and modify vector elements.
8. Perform bounds checking before accessing elements.
9. Display the results of all operations.
10. Handle invalid index access using an out-of-range exception.

## Pseudocode

```text
CLASS NumberList
    DECLARE integer value
    DECLARE vector elements

    CONSTRUCTOR(value, elements)
        INITIALIZE data members

    OVERLOAD PREFIX ++
        INCREMENT value
        RETURN current object

    OVERLOAD POSTFIX ++
        COPY current object
        INCREMENT value
        RETURN copied object

    OVERLOAD ==
        COMPARE values
        RETURN comparison result

    OVERLOAD >
        COMPARE values
        RETURN comparison result

    OVERLOAD []
        CHECK index bounds
        IF invalid
            THROW exception
        RETURN selected element

    METHOD display()
        DISPLAY value and elements
END CLASS

MAIN
    CREATE two NumberList objects
    TEST prefix increment
    TEST postfix increment
    TEST comparison operators
    TEST subscript access and modification
    TEST invalid index handling
END MAIN
```

## Test Cases

| Test Case | Operation | Expected Behaviour |
|---|---|---|
| TC01 | Prefix increment | Value increases before returning |
| TC02 | Postfix increment | Previous value is returned |
| TC03 | Equality comparison | Compares object values |
| TC04 | Greater-than comparison | Checks whether first value is greater |
| TC05 | Valid subscript access | Returns the requested element |
| TC06 | Subscript modification | Updates the selected element |
| TC07 | Invalid index access | Throws an out-of-range exception |

## Actual Output

```text
Initial Objects
Value: 10
Elements: 10 20 30 40
Value: 15
Elements: 5 15 25 35

Prefix Increment
First value: 11

Postfix Increment
Previous value: 15
Current value: 16

Comparison Operators
First == Second: False
First > Second: False

Subscript Operator
First element: 10
Third element: 30
Modified second element: 99

Bounds Checking
Error: Index out of range
```

## Operator Overloading Analysis

| Operator | Purpose | Return Type |
|---|---|---|
| Prefix `++` | Increment value before returning | NumberList& |
| Postfix `++` | Return previous value | NumberList |
| `==` | Compare equality | bool |
| `>` | Compare greater-than condition | bool |
| `[]` | Access or modify an element | int& / const int& |

The postfix increment operator uses a dummy integer parameter to distinguish it from prefix increment. The prefix operator returns a reference to the current object, while postfix returns a copy of the previous state.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Prefix increment | O(1) |
| Postfix increment | O(n) due to object and vector copying |
| Equality comparison | O(1) |
| Greater-than comparison | O(1) |
| Subscript access | O(1) |
| Element modification | O(1) |

Here, `n` represents the number of elements in the vector.

**Space Complexity:** O(n) for the vector. Postfix increment temporarily requires an additional object copy.

## Alternative Approach

The same operations can be implemented using separate member functions instead of overloaded operators.

For example, `increment()`, `isEqual()`, `isGreaterThan()`, and `getElement()` can perform equivalent operations. Operator overloading provides more natural syntax for user-defined types.

## Result

The NumberList class was successfully implemented using prefix, postfix, comparison, and subscript operator overloading. All operations, including invalid index handling, were tested successfully.