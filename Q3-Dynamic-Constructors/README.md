# Q3 – Dynamic Constructors and Destructors

## Aim

To implement dynamic memory allocation using constructors and release allocated memory using destructors in C++.

## Problem Description

Develop an Event Seat Management System that dynamically allocates memory for a two-dimensional seating arrangement. The system must support seat booking, cancellation, displaying seat availability, and automatic memory deallocation.

## Concepts Used

- Dynamic memory allocation using `new` and `new[]`
- Parameterized constructor
- Destructor
- Two-dimensional dynamic arrays
- Stack-based object creation
- Heap-based object creation using `new`
- Explicit object destruction using `delete`
- Block scope and object lifetime
- Exception-safe memory cleanup

## Algorithm

1. Define an Event class with event name, row count, seats per row, seating array, and booking count.
2. Initialize the object through a parameterized constructor.
3. Validate the seating dimensions.
4. Dynamically allocate memory for the rows and seats.
5. Initialize every available seat with `O`.
6. Implement seat booking by changing `O` to `X`.
7. Implement cancellation by changing `X` to `O`.
8. Display the seating arrangement and booking count.
9. Create objects using stack and heap allocation.
10. Release dynamically allocated memory in the destructor.

## Pseudocode

```text
CLASS Event
    DECLARE name, rows, seatsPerRow, bookedCount
    DECLARE dynamic seating array

    CONSTRUCTOR(name, rows, seatsPerRow)
        VALIDATE dimensions
        ALLOCATE memory for rows
        ALLOCATE memory for seats
        INITIALIZE all seats as available

    METHOD bookSeat(row, seat)
        CHECK valid position
        IF seat is available
            MARK seat as booked
            INCREMENT booking count

    METHOD cancelSeat(row, seat)
        CHECK valid position
        IF seat is booked
            MARK seat as available
            DECREMENT booking count

    METHOD display()
        DISPLAY seating arrangement
        DISPLAY booking count

    DESTRUCTOR
        RELEASE every dynamically allocated row
        RELEASE row pointer array
END CLASS

MAIN
    CREATE stack object
    TEST booking and cancellation
    CREATE block-scope object
    CREATE heap object
    DELETE heap object
    TEST zero-row object
END MAIN
```

## Test Cases

| Test Case | Input / Operation | Expected Behaviour |
|---|---|---|
| TC01 | Create event with 2 rows and 3 seats | All seats initialized as available |
| TC02 | Book seat (0,0) | Seat becomes booked |
| TC03 | Cancel seat (0,0) | Seat becomes available |
| TC04 | Create object inside a block | Destructor executes when block ends |
| TC05 | Create object using `new` | Memory allocated dynamically |
| TC06 | Delete heap object | Destructor executes |
| TC07 | Create event with zero rows | Object handles empty seating arrangement |

## Actual Output

```text
Stack Object
Created event: College Fest
Seat map of College Fest:
O O O
O X O
Booked seats: 1

Block Scope Object
Created event: Workshop
Closed event: Workshop | Final bookings: 1

Heap Object
Created event: Conference
Seat map of Conference:
O O
O X
O O
Booked seats: 1
Closed event: Conference | Final bookings: 1

Zero Row Test
Created event: Empty Event
Seat map of Empty Event:
Booked seats: 0

Program End
Closed event: Empty Event | Final bookings: 0
Closed event: College Fest | Final bookings: 1
```

## Memory Management Analysis

The constructor allocates memory dynamically for the seating arrangement. Each row is allocated separately using `new[]`.

The destructor releases each row using `delete[]` and then releases the row pointer array. This prevents dynamically allocated memory from remaining allocated after an object is destroyed.

Stack objects are destroyed automatically when their scope ends. Heap objects require explicit deletion using `delete`.

## Complexity Analysis

Let `R` represent the number of rows and `S` represent the number of seats per row.

| Operation | Time Complexity |
|---|---|
| Dynamic allocation and initialization | O(R × S) |
| Book a seat | O(1) |
| Cancel a seat | O(1) |
| Display seating arrangement | O(R × S) |
| Memory deallocation | O(R × S) |

**Space Complexity:** O(R × S)

## Alternative Approach

A `std::vector<std::vector<char>>` can be used instead of manually allocated dynamic arrays.

Vectors automatically manage memory and reduce the possibility of memory leaks. However, this implementation uses `new[]` and `delete[]` to demonstrate dynamic constructors and destructors explicitly.

## Result

The Event Seat Management System was successfully implemented and executed. Dynamic memory allocation, seat management, object lifetimes, and destructor-based memory deallocation were demonstrated using stack and heap objects.