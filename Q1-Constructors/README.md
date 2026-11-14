# Q1 – Constructors and Constructor Overloading

**Topic:** Library Book Records  
**Course Code:** DSA01  
**Assignment:** 3 – CO3  
**Marks:** 6  
**Language:** C++  
**Standard:** C++17

## 1. Aim

To develop a C++ program demonstrating default, parameterized, overloaded and copy constructors using a Library Book Records system. The program demonstrates constructor delegation, member initializer lists and validation to prevent invalid object creation.

## 2. Problem Description

A library needs to maintain book records containing the book title, author and number of available copies.

The program implements a `Book` class with multiple constructors to support different object creation scenarios.

## 3. Class Design

### Data Members

| Member | Data Type | Description |
|---|---|---|
| title | string | Stores the book title |
| author | string | Stores the author's name |
| copies | int | Stores the number of available copies |

### Constructors Implemented

| Constructor | Description |
|---|---|
| Default constructor | Creates an empty book record |
| Title-only constructor | Creates a donated book with one copy |
| Parameterized constructor | Initializes all book details |
| Copy constructor | Creates a new book using an existing book's details |

All constructors use member initializer lists. Constructor delegation is used to avoid duplicated initialization logic.

## 4. Implementation Details

- `Book()` delegates to the parameterized constructor with empty default values.
- The title-only constructor delegates to the parameterized constructor and assigns one copy.
- The parameterized constructor initializes all data members.
- The copy constructor delegates to the parameterized constructor.
- A validation function rejects negative copy counts using `invalid_argument`.
- The `display()` function displays the stored book information.

## 5. Sample Execution

```text
DEFAULT CONSTRUCTOR
Title: Empty
Author: Unknown
Copies: 0

TITLE-ONLY CONSTRUCTOR
Title: Wings of Fire
Author: Unknown
Copies: 1

PARAMETERIZED CONSTRUCTOR
Title: Atomic Habits
Author: James Clear
Copies: 5

COPY CONSTRUCTOR
Title: Atomic Habits
Author: James Clear
Copies: 5

INVALID COPY COUNT TEST
Validation Error: Number of copies cannot be negative.
```

## 6. Experimental Analysis

### Experiment 1: Compiler-Generated Default Constructor

A compiler-generated default constructor is available when no constructor is declared by the programmer, provided the language rules permit it.

A class without any user-declared constructor was tested by creating an array of three objects.

**Result:** All three objects were created successfully.

### Experiment 2: Removing the Default Constructor

A parameterized constructor was declared without providing a default constructor.

An array of three objects was then created.

**Observed compiler error:**

```text
error: no matching function for call to 'Book::Book()'
```

**Inference:** Every element of the array requires default construction. Since no default constructor is available, compilation fails.

### Experiment 3: Initialization Order

An incorrect member initializer order was tested.

**Observed warnings:**
- `-Wreorder`
- `-Wuninitialized`

C++ initializes data members in their declaration order, regardless of their order in the member initializer list.

The corrected implementation initializes members in declaration order.

**Result:** The corrected program compiled without warnings and produced:

```text
Copies: 50
Price: 500
```

### Experiment 4: Explicit Constructor

The `explicit` keyword was tested with a single-argument constructor.

With `explicit`, implicit conversion from a string literal to a `Book` object was rejected.

Without `explicit`, the conversion was permitted.

**Inference:** The `explicit` keyword prevents unintended implicit conversions.

### Experiment 5: Constructor Overloading and Default Arguments

A separate implementation using one constructor with default arguments was tested.

**Observed difference:**

| Object | Overloaded constructors | Default arguments |
|---|---:|---:|
| Empty book | 0 | 0 |
| Donated book | 1 | 0 |
| Full book | 5 | 5 |

Constructor overloading provides independent initialization behaviour for different object creation scenarios. A single default-argument constructor uses the same defaults for omitted arguments.

## 7. Complexity Analysis

For fixed-size member initialization:

- Constructor invocation: O(1), excluding string allocation and copying.
- Display operation: O(n), where n is the total number of characters printed.
- Additional space for object creation: O(1), excluding dynamically allocated string storage.
- Copy construction: O(n), where n is the total length of the copied strings.

## 8. Important Concepts

### When does the compiler generate a default constructor?

The compiler implicitly declares a default constructor when the class has no user-declared constructor, subject to the applicable C++ rules.

### Initializer list versus assignment inside the constructor

Member initializer lists directly initialize data members. Assignment inside the constructor body occurs after the members have already been initialized.

### Why does declaration order matter?

Data members are initialized in the order in which they are declared in the class, not in the order written in the initializer list.

### What is constructor delegation?

Constructor delegation allows one constructor to call another constructor of the same class, reducing repeated initialization code.

### Why use explicit?

It prevents unintended implicit conversions through single-argument constructors.

## 9. Conclusion

The Library Book Records program successfully demonstrates constructor overloading, constructor delegation, member initializer lists and copy construction. Experimental programs verified compiler-generated default constructors, initialization order, explicit conversion control and the limitations of default arguments.

The implementation also validates copy counts to prevent invalid book records.