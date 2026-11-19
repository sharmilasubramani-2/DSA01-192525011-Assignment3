# Q4 – Arithmetic and Stream Operator Overloading

## Aim

To implement arithmetic and stream operator overloading in C++ using a user-defined Number class.

## Problem Description

Develop a Number class that overloads arithmetic operators to perform addition, subtraction, multiplication, and division. Overload stream insertion and extraction operators to support convenient input and output operations.

## Concepts Used

- Operator overloading
- Binary arithmetic operators
- Stream insertion operator (`<<`)
- Stream extraction operator (`>>`)
- Friend functions
- Exception handling
- Constant member functions

## Algorithm

1. Define a Number class containing a private double variable.
2. Initialize the number using a parameterized constructor.
3. Overload the addition operator to add two Number objects.
4. Overload the subtraction operator to subtract two Number objects.
5. Overload the multiplication operator to multiply two Number objects.
6. Overload the division operator and check for division by zero.
7. Overload the insertion operator to display a Number object.
8. Overload the extraction operator to accept input.
9. Read two numbers and perform all arithmetic operations.
10. Handle division-by-zero exceptions.

## Pseudocode

```text
CLASS Number
    DECLARE private value

    CONSTRUCTOR(value)
        INITIALIZE value

    OVERLOAD +
        RETURN sum of two values

    OVERLOAD -
        RETURN difference of two values

    OVERLOAD *
        RETURN product of two values

    OVERLOAD /
        IF second value is zero
            THROW exception
        RETURN quotient

    OVERLOAD <<
        DISPLAY number

    OVERLOAD >>
        READ number
END CLASS

MAIN
    READ two Number objects
    DISPLAY both numbers
    PERFORM arithmetic operations
    HANDLE division exception
END MAIN
```

## Test Cases

| Test Case | Input | Expected Behaviour |
|---|---|---|
| TC01 | 20 and 5 | All arithmetic operations produce correct results |
| TC02 | 20 and 0 | Division-by-zero exception is handled |
| TC03 | Invalid text input | Invalid input message is displayed |

## Actual Output – Normal Test

```text
Enter two numbers: 20 5
First number: 20
Second number: 5
Addition: 25
Subtraction: 15
Multiplication: 100
Division: 4
```

## Actual Output – Division by Zero

```text
Enter two numbers: 20 0
First number: 20
Second number: 0
Addition: 20
Subtraction: 20
Multiplication: 0
Division: Error: Division by zero is not allowed
```

## Operator Overloading Analysis

| Operator | Purpose | Implementation |
|---|---|---|
| + | Addition | Member function |
| - | Subtraction | Member function |
| * | Multiplication | Member function |
| / | Division | Member function |
| << | Stream insertion | Friend function |
| >> | Stream extraction | Friend function |

The arithmetic operators are implemented as member functions because the left operand is a Number object. The stream operators are implemented as friend functions because the left operand is a standard input or output stream.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Addition | O(1) |
| Subtraction | O(1) |
| Multiplication | O(1) |
| Division | O(1) |
| Input and output | O(1) per value |

**Space Complexity:** O(1), excluding standard stream buffers.

## Alternative Approach

Arithmetic operations can also be implemented using ordinary member functions such as `add()`, `subtract()`, `multiply()`, and `divide()`.

However, operator overloading provides a more natural syntax and allows user-defined objects to behave similarly to built-in numeric types.

## Result

The Number class was successfully implemented using arithmetic and stream operator overloading. All four arithmetic operations were tested, and division-by-zero handling was verified successfully.