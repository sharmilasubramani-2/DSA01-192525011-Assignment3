# Q7 – Complex Number Class and AC Impedance Calculator

## 1. Aim

To implement a Complex Number class using operator overloading and apply complex arithmetic operations to calculate series and parallel AC impedance.

## 2. Problem Description

Develop a Complex class that represents numbers using real and imaginary components. Implement arithmetic operators, equality comparison, magnitude calculation, and stream insertion.

Apply the class to calculate equivalent impedance in series and parallel AC circuits. Handle division by zero safely and verify the calculated results.

## 3. Concepts Used

- Classes and objects
- Default constructor
- Parameterized constructors
- Operator overloading
- Complex number arithmetic
- Friend functions
- Stream insertion operator
- Equality comparison
- Exception handling
- AC impedance calculations

## 4. Algorithm

1. Define a Complex class with real and imaginary data members.
2. Implement a default constructor that initializes both components to zero.
3. Implement a real-only constructor and a two-argument constructor.
4. Overload the addition and subtraction operators.
5. Overload multiplication using complex number multiplication rules.
6. Overload division using the complex conjugate method.
7. Check for zero impedance before performing division.
8. Overload the equality operator using a small tolerance.
9. Implement a magnitude function.
10. Overload the stream insertion operator to display complex numbers.
11. Calculate series impedance by adding individual impedances.
12. Calculate parallel impedance using the equivalent impedance formula.
13. Display the results and test division-by-zero handling.

## 5. Pseudocode

```text
CLASS Complex
    DECLARE real and imaginary components

    DEFAULT CONSTRUCTOR
        INITIALIZE both components to zero

    REAL-ONLY CONSTRUCTOR(value)
        INITIALIZE real component with value
        INITIALIZE imaginary component to zero

    PARAMETERIZED CONSTRUCTOR(real, imaginary)
        INITIALIZE both components

    OVERLOAD +
        ADD corresponding components

    OVERLOAD -
        SUBTRACT corresponding components

    OVERLOAD *
        APPLY complex multiplication formula

    OVERLOAD /
        CALCULATE denominator
        IF denominator is zero
            THROW exception
        APPLY complex division formula

    OVERLOAD ==
        COMPARE components using tolerance

    METHOD magnitude()
        RETURN square root of real squared plus imaginary squared

    OVERLOAD <<
        DISPLAY complex number

END CLASS

MAIN
    CREATE complex numbers
    PERFORM arithmetic operations
    CALCULATE magnitude
    CHECK equality
    CALCULATE series impedance
    CALCULATE parallel impedance
    TEST division by zero
END MAIN
```

## 6. Mathematical Formulas

Let two complex numbers be:

Z1 = a + bi

Z2 = c + di

### 6.1 Addition

Z1 + Z2 = (a + c) + (b + d)i

### 6.2 Subtraction

Z1 - Z2 = (a - c) + (b - d)i

### 6.3 Multiplication

Z1 × Z2 = (ac - bd) + (ad + bc)i

### 6.4 Division

Z1 / Z2 = [(ac + bd) + (bc - ad)i] / (c² + d²)

The denominator must not be zero.

### 6.5 Magnitude

For Z = a + bi:

|Z| = sqrt(a² + b²)

### 6.6 Series Impedance

The total impedance of components connected in series is:

Zs = Z1 + Z2 + Z3

### 6.7 Parallel Impedance

For two impedances connected in parallel:

Zp = (Z1 × Z2) / (Z1 + Z2)

## 7. Test Cases

| Test Case | Operation | Expected Behaviour |
|---|---|---|
| TC01 | Create complex numbers | Correct real and imaginary components |
| TC02 | Addition | Correct component-wise addition |
| TC03 | Subtraction | Correct component-wise subtraction |
| TC04 | Multiplication | Correct complex multiplication |
| TC05 | Division | Correct complex division |
| TC06 | Magnitude | Correct magnitude calculation |
| TC07 | Equality | Correct comparison of components |
| TC08 | Series impedance | Correct sum of impedances |
| TC09 | Parallel impedance | Correct equivalent impedance |
| TC10 | Division by zero | Exception is handled safely |

## 8. Actual Output

```text
AC Impedance Calculator

Complex Numbers
Z1: 4.00 + 3.00i
Z2: 2.00 - 1.00i

Arithmetic Operations
Addition: 6.00 + 2.00i
Subtraction: 2.00 + 4.00i
Multiplication: 11.00 + 2.00i
Division: 1.00 + 2.00i

Magnitude
|Z1|: 5.00

Equality Comparison
Z1 == Z2: False

Series RLC Impedance
Resistance: 4.00 + 0.00i
Inductive impedance: 0.00 + 3.00i
Capacitive impedance: 0.00 - 1.00i
Total series impedance: 4.00 + 2.00i
Magnitude: 4.47

Parallel Impedance
Branch 1: 4.00 + 2.00i
Branch 2: 2.00 - 1.00i
Equivalent impedance: 1.62 - 0.27i
Magnitude: 1.64

Zero Impedance Division Test
Error: Division by zero impedance

All tests completed successfully.
```

## 9. Calculation Verification

### 9.1 Complex Division

Given:

Z1 = 4 + 3i

Z2 = 2 - i

Using the complex division formula:

(4 + 3i) / (2 - i)

Multiply the numerator and denominator by the conjugate (2 + i):

= [(4 + 3i)(2 + i)] / [(2 - i)(2 + i)]

= (8 + 4i + 6i + 3i²) / (4 + 1)

Since i² = -1:

= (8 + 10i - 3) / 5

= (5 + 10i) / 5

Final Answer:

**Z1 / Z2 = 1 + 2i**

### 9.2 Series Impedance

Given:

Resistance impedance = 4 + 0i

Inductive impedance = 0 + 3i

Capacitive impedance = 0 - 1i

Total series impedance:

Zs = (4 + 0i) + (0 + 3i) + (0 - 1i)

Zs = 4 + 2i

Magnitude:

|Zs| = sqrt(4² + 2²)

|Zs| = sqrt(16 + 4)

**|Zs| = 4.47 ohms**

### 9.3 Parallel Impedance

Given:

Z1 = 4 + 2i

Z2 = 2 - i

Formula:

Zp = (Z1 × Z2) / (Z1 + Z2)

Substitute the values:

Zp = [(4 + 2i)(2 - i)] / [(4 + 2i) + (2 - i)]

Multiply the numerator:

(4 + 2i)(2 - i)

= 8 - 4i + 4i - 2i²

Since i² = -1:

= 8 + 2

= 10

Add the denominator:

(4 + 2i) + (2 - i) = 6 + i

Therefore:

Zp = 10 / (6 + i)

Multiply the numerator and denominator by the conjugate (6 - i):

Zp = [10(6 - i)] / [(6 + i)(6 - i)]

Zp = (60 - 10i) / (36 + 1)

Zp = (60 - 10i) / 37

Final Answer:

**Zp = 1.62 - 0.27i ohms**

Magnitude:

|Zp| = sqrt(1.62² + (-0.27)²)

**|Zp| = approximately 1.64 ohms**

## 10. Operator Overloading Analysis

| Operator | Purpose | Implementation |
|---|---|---|
| + | Addition | Member function |
| - | Subtraction | Member function |
| * | Multiplication | Member function |
| / | Division | Member function |
| == | Equality comparison | Member function |
| << | Stream insertion | Friend function |

### Member Functions

Arithmetic operators and the equality operator are implemented as member functions because they operate on the current Complex object and another Complex object.

### Friend Function

The stream insertion operator is implemented as a friend function because the left operand is the output stream (`std::ostream`), not a Complex object. The friend function can access the private components for displaying the value.

## 11. Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Addition | O(1) |
| Subtraction | O(1) |
| Multiplication | O(1) |
| Division | O(1) |
| Equality comparison | O(1) |
| Magnitude calculation | O(1) |
| Series impedance with three fixed components | O(1) |
| Parallel impedance | O(1) |

**Space Complexity:** O(1)

All operations use a fixed number of variables and do not require additional data structures.

## 12. Comparison with std::complex<double>

C++ provides the standard library class `std::complex<double>` for representing and performing operations on complex numbers.

| Feature | Custom Complex Class | std::complex<double> |
|---|---|---|
| Representation | Real and imaginary data members | Standard complex representation |
| Addition | User-defined operator | Built-in overloaded operator |
| Subtraction | User-defined operator | Built-in overloaded operator |
| Multiplication | User-defined operator | Built-in overloaded operator |
| Division | User-defined operator | Built-in overloaded operator |
| Magnitude | Custom function | std::abs() |
| Display | Custom stream insertion | Standard stream insertion |
| Main purpose | Demonstrates OOP and operator overloading | General-purpose complex arithmetic |

The custom class provides practical experience in implementing operator overloading. The standard library implementation is preferable for general numerical applications because it is standardized and extensively tested.

## 13. Limitations

- The implementation uses double-precision floating-point values.
- Floating-point calculations may introduce small rounding errors.
- The equality operator uses a fixed tolerance.
- The implementation focuses on two-impedance parallel calculations.
- Additional circuit analysis features can be implemented in future versions.

## 14. Result

The Complex Number class was successfully implemented and executed using C++ operator overloading. Addition, subtraction, multiplication, division, magnitude calculation, equality comparison, series impedance, and parallel impedance calculations were verified.

Division by zero was also handled safely using exception handling. The program produced the expected results for the tested inputs.