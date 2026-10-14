*This project has been created as part of the 42 curriculum by younes abyaa.*

# Push_swap

## Description

**Push_swap** is an algorithmic project whose goal is to sort data using two stacks and a limited set of instructions, with the lowest possible number of operations.

- Stack `a` starts with a list of unique integers (negative and/or positive).
- Stack `b` starts empty.
- The goal is to have the numbers sorted in ascending order in stack `a`, with the smallest number at the top.

The program `push_swap` takes the integers as arguments (the first argument is at the top of stack `a`) and prints, one per line, the sequence of instructions that sorts them.

### Allowed operations

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` | Swap the first 2 elements at the top of stack `a` / `b`. Does nothing with fewer than 2 elements. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the top element of `b` and put it on top of `a`. Does nothing if `b` is empty. |
| `pb` | Take the top element of `a` and put it on top of `b`. Does nothing if `a` is empty. |
| `ra` / `rb` | Rotate stack `a` / `b`: the first element becomes the last one. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` / `rrb` | Reverse rotate stack `a` / `b`: the last element becomes the first one. |
| `rrr` | `rra` and `rrb` at the same time. |

### Behavior

- If no argument is given, nothing is displayed.
- If the input is already sorted, nothing is displayed.
- In case of error (an argument that is not an integer, an integer out of the `int` range, or a duplicate), `Error` followed by a newline is printed on the standard error.
- Instructions are separated by `\n` and nothing else.
- No global variables are used, and all allocated memory is freed before the program exits.

### Benchmark targets

| Input size | Limit |
|------------|-------|
| 3 numbers | at most 3 instructions |
| 5 numbers | at most 12 instructions |
| 100 random numbers | fewer than 700 operations |
| 500 random numbers | no more than 5500 operations |

## Instructions

### Compilation

Use the Makefile at the root of the repository:

```bash
make        # builds the push_swap executable
make clean  # removes the object files
make fclean # removes the object files and the executable
make re     # rebuilds everything from scratch
```

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`. The Makefile does not relink when nothing has changed.

### Execution

```bash
./push_swap 2 1 3 6 5 8
```

Output:

```
sa
pb
pb
pb
sa
pa
pa
pa
```

The arguments can also be passed through a variable:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG
```

Error example:

```bash
./push_swap 0 one 2 3
Error
```

### Checking the result

The number of instructions can be counted with `wc -l`:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

The result can be verified with the `checker_OS` binary provided by the project resources on the intranet, which prints `OK` when the instructions sort the stack and `KO` otherwise:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## Algorithm

### Overview

The program chooses its strategy depending on the number of elements. Small inputs are handled by dedicated routines, and larger inputs are sorted with a **chunk-based algorithm**: the values are divided into ranges (chunks) that are pushed to stack `b` one after the other, then pulled back to stack `a` from the largest to the smallest.

### Step 1: Parsing and validation

All arguments are checked before anything else. Each one must be a valid integer that fits in an `int`, and no value may appear twice. On any error, `Error\n` is written on the standard error and the program exits after freeing what was allocated. If the stack is already sorted, nothing is printed.

### Step 2: Small inputs

- **2 numbers:** a single `sa` if they are in the wrong order.
- **3 numbers:** the position of the largest value determines the few instructions needed (at most 2 are ever required), which stays within the limit of 3.
- **4 and 5 numbers:** the smallest elements are pushed to stack `b` using the shortest rotation (`ra` or `rra`), the remaining 3 numbers are sorted in stack `a` with the 3-number routine, then the elements of `b` are pushed back with `pa`. This stays within the limit of 12 instructions for 5 numbers.

### Step 3: Large inputs

1. **Index normalization.** Each value is replaced by its rank in the sorted list of all values (from `0` to `n - 1`). Working with ranks instead of raw values makes the chunk boundaries simple, and the algorithm behaves the same whatever the actual numbers are, including negative ones.
2. **Chunk definition.** The ranks are split into consecutive ranges of equal size, and the chunk size depends on the number of elements, so the number of chunks grows with the size of the input.
3. **Push to `b`, chunk by chunk.** Starting with the chunk that contains the smallest ranks and moving up to the chunk with the largest ranks, the program looks in stack `a` for the elements that belong to the current chunk. Each one is brought to the top of `a` using the shortest direction (`ra` or `rra`) and pushed with `pb`. This continues until stack `a` is empty.
4. **Push back to `a`, largest first.** While stack `b` is not empty, the program finds the element with the largest rank in `b`, brings it to the top using the shortest direction (`rb` or `rrb`), and pushes it with `pa`. Since the largest remaining element is always pushed first onto the top of `a`, stack `a` ends up sorted in ascending order with no extra rotation needed.

### Justification

- **Chunks keep `b` roughly organized:** because chunks are pushed from the lowest ranks to the highest, the elements that will be needed first in the push-back phase (the largest ones) are the ones pushed last, so they sit near the top of `b`. This keeps the number of rotations needed to reach the maximum small.
- **Cheaper than moving elements one by one:** pushing an element requires finding it first, and handling a whole range at a time avoids sending elements to `b` in a completely random order, which would make the push-back phase very expensive.
- **Shortest direction everywhere:** at every rotation, the program chooses between rotating and reverse rotating according to the position of the element, so no stack is ever rotated by more than half of its size to reach an element.
- **Ranks instead of values:** using indices removes any dependency on the actual numbers, which makes the chunk logic easy to reason about and to test.
- **Dedicated routines for small inputs:** the chunk method has overhead that is not worth paying for 3 or 5 numbers, and the limits for these sizes are strict, so they are handled separately and directly.
- **Simplicity and predictability:** the approach is easy to explain and to verify, and the number of operations stays consistent from one random input to another.

### Complexity

Finding the next element to move requires scanning a stack, so the time spent searching is O(n²) in the worst case with simple scans. The number of printed instructions grows roughly in proportion to the number of elements times the number of chunk passes and rotations needed, which is what the benchmark limits for 100 and 500 numbers measure.

## Resources

### References

- Complexity of algorithms and Big O notation (introductory articles and course material on algorithmic complexity)
- Stack data structure and its operations (documentation and tutorials)
- Sorting algorithms overview (comparison of common sorting algorithms and their complexity)
- `man 3 malloc`, `man 3 free`, `man 2 write`

### Use of AI

AI was used only to help write and structure this `README.md` file.