# Memory Allocator in C

## Overview
This project is a simple **memory allocator in C** that dynamically allocates memory for an array, takes user input, stores values, and prints them before freeing the allocated memory. It also includes error handling for invalid input and memory allocation failures.

## Features
- Prompts the user to enter the number of elements.
- Dynamically allocates memory using `malloc()`.
- Handles invalid input (e.g., pressing Enter or entering non-numeric values).
- Stores and prints integer values.
- Properly frees allocated memory to prevent memory leaks.

## Compilation & Execution
### **Compile:**
```bash
gcc -o run.exe mem.c
```

### **Run:**
```bash
./run.exe
```

## Example Output
```
Enter number of elements in array: 3
Adding 3 elements

Memory allocation passed!
Memory address of array: 0x5933d58bcac0

Allocate values to store in memory
------------------------------------
Enter value for element 1: 10
Enter value for element 2: 20
Enter value for element 3: 30

Done taking records

Values stored: 10 20 30
Memory freed!
```

## Code Explanation
- Uses a `while` loop to prompt the user until valid input is received.
- Implements pointer arithmetic (`*(array + i)`) to access elements dynamically.
- Ensures safe memory handling by storing the allocated pointer and freeing it at the end.

## Future Enhancements
- Implement error logging.
- Add support for floating-point numbers.
- Use `calloc()` for zero-initialized memory allocation.

## License
This project is licensed under the MIT License.

