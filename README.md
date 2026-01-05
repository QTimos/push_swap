*This project has been created as part of the 42 curriculum by [hdyani].*

## Description

The project push_swap uses two stacks and a restricted set of operations to provide an effective way to sort data. The objective is to use a sorting algorithm that sorts a list(stack) of numbers in ascending order in as few operations as possible.

The project implements:

- Input parsing to handle numbers passed as arguments or in quoted strings
- Validation to check for duplicates and integer limits
- Multiple sorting algorithms depending on stack size:
  - 2-3 numbers: Direct sorting logic
  - 4-5 numbers: Optimal movement algorithm
  - 6+ numbers: Advanced algorithm pushing chunks to stack B and sorting back
- Operation optimization to combine and cancel redundant moves

## Instructions

### Cloning
```bash
git clone [the link of the git repository] # Clone the repository using this command (change the message with the actual link)
```

### Compilation
```bash
make            # compile push_swap executable
make bonus      # compile checker executable (if implemented)
make clean      # remove object files
make fclean     # remove object files and executables
make re         # recompile everything
```

### Usage
```bash
# Basic usage with individual numbers
./push_swap 4 67 3 87 23

# Usage with quoted string
./push_swap "4 67 3 87 23"

# Combine multiple arguments and strings
./push_swap 4 67 "3 87" 23

# Check if sorting is correct
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Generate random numbers
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l                   # This is to count operations
./push_swap $ARG | ./checker $ARG          # Verify sorting
```

### Project Structure
```
push_swap/
├── includes/
│   └── push_swap.h          # Header file with all prototypes
├── src/
│   ├── input_handle1.c      # Input parsing functions
│   ├── input_handle2.c      # Input validation and atoll
│   ├── init_stack.c         # Stack initialization
│   ├── operations.c         # Basic stack operations (push, swap, rotate)
│   ├── ops_optimize.c       # Operation optimization
│   ├── sort_stack.c         # Small stack sorting (2-5 elements)
│   ├── sort_utils.c         # Sorting utilities
│   ├── sorted.c             # Check if stack is sorted
│   ├── push_to_b.c          # Push elements from A to B
│   ├── push_back.c          # Push elements from B back to A
│   ├── push_swap.c          # Main program
│   ├── ft_split.c           # String splitting function
│   ├── libft_funcs.c        # Basic string functions
│   └── free.c               # Memory management
├── Makefile
└── README.md
```

### Sorting Algorithm

#### For Small Stacks (2-5 elements)

- 2 elements: Single swap if needed
- 3 elements: Hardcoded optimal sequence
- 4-5 elements: Find minimum, push to B, sort remaining, push back

#### For Large Stacks (6+ elements)

1. Push to B: Calculate median, push elements within a dynamic range to stack B
2. Sort A: Sort the remaining 3 elements in A
3. Push back: Calculate cheapest element in B to push back to A, rotate both stacks simultaneously when possible
4. Final rotation: Rotate A to bring minimum to top

### Allowed Operations

| Operation | Description                                  | Code       |
|-----------|----------------------------------------------|------------|
| sa        | Swap first two elements of stack A           | ft_swap    |
| sb        | Swap first two elements of stack B           | ft_swap    |
| ss        | sa and sb simultaneously                     | Combined   |
| pa        | Push top element from B to A                 | ft_push    |
| pb        | Push top element from A to B                 | ft_push    |
| ra        | Rotate stack A up (first becomes last)       | ft_rotate  |
| rb        | Rotate stack B up                            | ft_rotate  |
| rr        | ra and rb simultaneously                     | Combined   |
| rra       | Reverse rotate stack A (last becomes first)  | ft_rrotate |
| rrb       | Reverse rotate stack B                       | ft_rrotate |
| rrr       | rra and rrb simultaneously                   | Combined   |

### Performance Requirements

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations (mine: an average of around 566 operations)
- 500 numbers: ≤ 5500 operations (mine: an average of around 4108 operations)

## Resources

### Documentation & References

- [https://mlsu.ac.in/econtents/325_04Stacks.pdf]
- [https://heshanu97.medium.com/optimal-merge-pattern-a-greedy-algorithm-approach-8167d45957fb]
- [https://www.geeksforgeeks.org/dsa/merge-sort/]
- [https://devopedia.org/algorithmic-complexity]

## Author

[Dyani Hatim] - [hdyani] - [https://github.com/qtimos]
