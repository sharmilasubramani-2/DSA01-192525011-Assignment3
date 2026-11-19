# DSA0111 – OOPS Assignment 3

## Operator Overloading and Object-Oriented Programming in C++

## Student Information

| Detail | Information |
|---|---|
| Name | Sharmila Subramani |
| Register Number | 192525011 |
| Course Code | DSA0111 |
| Course Name | OOPS |
| Assignment | Assignment 3 |
| Programming Language | C++ |
| Compiler | GCC (MSYS2 UCRT64) |
| Standard | C++17 |
| IDE | Visual Studio Code |

## 1. Overview

This repository contains the implementation of seven programming questions for DSA0111 – OOPS Assignment 3.

The assignment focuses on object-oriented programming concepts in C++, particularly constructors, dynamic memory management, copy constructors, destructors, and operator overloading.

Each question is implemented as an individual C++ program with supporting documentation, execution results, and relevant experiments.

## 2. Objectives

- Understand constructors and constructor overloading.
- Implement copy constructors and distinguish shallow copying from deep copying.
- Manage dynamic memory using constructors and destructors.
- Overload arithmetic and stream insertion/extraction operators.
- Implement increment, comparison, and subscript operators.
- Understand operator overloading rules and their practical applications.
- Develop a Complex Number class for AC impedance calculations.
- Apply object-oriented programming concepts to practical problems.

## 3. Technologies and Tools

| Technology / Tool | Purpose |
|---|---|
| C++ | Programming language |
| GCC 16.1.0 | Compiler |
| C++17 | Language standard |
| Visual Studio Code | Code editor |
| PowerShell | Compilation and execution |
| Git | Version control |
| GitHub | Source code hosting and submission |

## 4. Repository Structure

```text
DSA01-192525011-Assignment3/
│
├── Q1-Constructors/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q2-Copy-Constructors/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q3-Dynamic-Constructors/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q4-Arithmetic-Stream-Operators/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q5-Increment-Comparison-Subscript/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q6-Operator-Overloading-Rules/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Q7-Complex-Number-Class/
│   ├── main.cpp
│   ├── README.md
│   ├── experiments/
│   └── screenshots/
│
├── Report/
│
├── .gitignore
└── README.md
```

## 5. Question-wise Implementation

### Q1 – Constructors and Constructor Overloading

Demonstrates the use of constructors to initialize objects with different sets of values.

**Concepts covered:**
- Default constructors
- Parameterized constructors
- Constructor overloading
- Object initialization

### Q2 – Copy Constructors and Deep Copy

Demonstrates object copying and dynamic memory management using deep copying.

**Concepts covered:**
- Copy constructors
- Shallow copy and deep copy
- Copy assignment operator
- Rule of Three
- Dynamic memory allocation

### Q3 – Dynamic Constructors and Destructors

Implements dynamic memory allocation and automatic resource cleanup through constructors and destructors.

**Concepts covered:**
- Dynamic memory allocation
- Dynamic constructors
- Destructors
- Stack and heap objects
- Resource management

### Q4 – Arithmetic and Stream Operator Overloading

Implements arithmetic operations and input/output handling through overloaded operators.

**Concepts covered:**
- Arithmetic operator overloading
- Addition, subtraction, multiplication, and division
- Stream insertion operator
- Stream extraction operator
- Exception handling for division by zero

### Q5 – Increment, Comparison and Subscript Operators

Demonstrates custom behaviour for increment, comparison, and array access operators.

**Concepts covered:**
- Prefix increment
- Postfix increment
- Equality operator
- Greater-than operator
- Subscript operator
- Bounds checking

### Q6 – Operator Overloading Rules and Text Class

Implements a Text class using dynamic character memory and overloaded operators.

**Concepts covered:**
- Operator overloading rules
- String concatenation
- Equality and inequality operators
- Stream insertion
- Copy constructor
- Copy assignment
- Dynamic memory management

### Q7 – Complex Number Class and AC Impedance Calculator

Develops a Complex class to perform complex arithmetic and calculate equivalent AC impedance.

**Concepts covered:**
- Complex number representation
- Arithmetic operator overloading
- Equality comparison
- Stream insertion operator
- Magnitude calculation
- Series impedance
- Parallel impedance
- Division-by-zero handling

## 6. Compilation and Execution

The programs are developed using GCC with the C++17 standard.

### Compiler Version

```powershell
g++ --version
```

### Compilation Command

Navigate to the repository directory and compile the required question.

Example for Q1:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\Q1-Constructors\main.cpp -o .\Q1-Constructors\main.exe
```

### Execution Command

```powershell
.\Q1-Constructors\main.exe
```

Replace `Q1-Constructors` with the required question folder to compile and execute another program.

## 7. Testing and Verification

Each implementation is executed to verify its expected behaviour.

Testing includes:

- Normal input cases
- Arithmetic operation verification
- Object initialization and copying
- Dynamic memory allocation and cleanup
- Operator behaviour
- Boundary and invalid input handling where applicable
- Division-by-zero handling
- Output verification

Individual question folders contain their implementation details, test cases, and execution evidence.

## 8. Documentation

Each question folder includes:

- `main.cpp` – C++ implementation.
- `README.md` – Aim, concepts, algorithm, pseudocode, test cases, complexity analysis, and result.
- `experiments/` – Supporting experiment files, where applicable.
- `screenshots/` – Program execution evidence.

## 9. Version Control

Git is used to maintain the development history of the assignment.

Each question is maintained through individual commits to provide a clear record of implementation progress.

## 10. Conclusion

This assignment provides practical experience in implementing object-oriented programming concepts using C++.

The seven implementations demonstrate constructor overloading, copy semantics, dynamic memory management, operator overloading, exception handling, and complex number operations.

The programs are organized into separate modules with individual documentation and execution evidence, making the repository suitable for academic evaluation and future reference.