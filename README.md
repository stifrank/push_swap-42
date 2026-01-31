*This project has been created as part of the 42 curriculum by fjaramil.*

# push_swap

Project from the **42 Common Core** whose goal is to sort a stack of integers using a limited set of instructions, aiming to **minimize the number of operations**.

---

## Description

`push_swap` receives a list of integers as arguments and must output to **stdout** a sequence of instructions (from an allowed set) that sorts stack `A` in ascending order, using stack `B` as auxiliary storage.

The main challenge is not only to sort correctly, but to do so **efficiently**, while strictly respecting the constraints defined in the subject:
- Norminette compliance
- Proper error handling
- No crashes (segfaults, double frees, etc.)
- No memory leaks

This project is an important learning step to better understand:
- Stack-based data structures
- Algorithm design and optimization
- Complexity trade-offs
- Careful debugging and reasoning

---

## Instructions

### Compilation

```bash
make
```

The Makefile includes the rules required by the subject:
- `all`
- `$(NAME)`
- `clean`
- `fclean`
- `re`

### Execution

```bash
./push_swap 3 2 1
```

It also works using a variable:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG
```
```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG
```

### Checker (verification)

During development, the official `checker` is used to verify that the output actually sorts the stack:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```

To count the number of operations:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

---

## Project structure

```
push_swap/
├── include/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── instructions/
│   │   ├── instructions_push.c
│   │   ├── instructions_reverse_rotate.c
│   │   ├── instructions_rotate.c
│   │   └── instructions_swap.c
│   ├── parsing/
│   │   ├── check_duplicates.c
│   │   ├── error.c
│   │   ├── parse_arguments.c
│   │   ├── safe_atoi.c
│   │   └── validate_number.c
│   ├── sorting/
│   │   ├── sort_small.c
│   │   ├── chunk_sort.c
│   │   ├── indexing.c
│   │   └── dispatcher.c
│   └── stack/
│       ├── stack_add.c
│       ├── stack_create.c
│       ├── stack_pop.c
│       └── free_stack.c
├── Makefile
└── README.md
```

---

## Implementation overview

### 1) Validation & parsing

The program strictly validates the input:
- Only integers (valid `+` / `-` signs allowed)
- Values within `int` range
- No duplicate numbers
- Correct error handling (`Error\n` written to stderr when required)

---

### 2) Indexation (value compression)

Before sorting, all values are converted into indices ranging from `0` to `n - 1`, based on their relative order.

This approach:
- Simplifies comparisons
- Makes the algorithm independent of actual values
- Enables the use of ranges and windows

Example:

```
Input:  42  -3  100
Index:   1   0   2
```

---

### 3) Small sorts (≤ 5 elements)

For small stack sizes, deterministic and optimized strategies are used, ensuring a minimal number of operations:

- `sort_2`
- `sort_3` (placing the maximum at the bottom)
- `sort_4` / `sort_5`
  - Push the smallest element(s) to stack `B`
  - Sort stack `A`
  - Restore elements with `pa`

Rotations (`ra` or `rra`) are chosen depending on element position to reduce unnecessary moves.

---

### 4) Chunk sort (n > 5)

For larger inputs, **chunk sort** is implemented. This algorithm works by dividing the index range into **windows (chunks)**.

#### Chunk size (dynamic)

The chunk size is adjusted dynamically depending on input size:

- `≤ 100` → `20`
- `≤ 500` → `35`
- `> 500` → `n / 11 + 10`

This provides a good balance between simplicity and performance.

---

#### Phase A → B

An incremental pointer `index` is used as reference:

- If `a->top->index <= index`
  - `pb` followed by `rb` (smallest values go deeper in `B`)
- If `a->top->index <= index + chunk`
  - `pb`
- Otherwise
  - `ra` (to rotate and keep searching)

This strategy avoids deadlocks and keeps stack `B` partially ordered.

---

#### Phase B → A (optimized)

- Locate the expected maximum index in stack `B`
- Rotate `B` (`rb` or `rrb`) until it reaches the top
- Execute `pa`

Additional optimization:
- If after `pa` the next expected index (`target - 1`) is on top of `B`, perform `pa` followed by `sa` to place both elements correctly with fewer moves.

---

## Benchmarks (subject reference)

Performance targets used for evaluation and maximum validation:
- 100 numbers: **< 700** operations
- 500 numbers: **≤ 5500** operations

Typical results achieved with this implementation:
- 100 elements: **< 700**
- 500 elements: **~4000–4500**

---

## Testing

The program has been tested with:
- Negative numbers
- Duplicate values (expected error)
- `INT_MIN` and `INT_MAX` limits

---

## AI usage

Artificial Intelligence has been used **only as a conceptual support tool**, not as an automatic code generator.

It was mainly used to:
- Better understand and justify the **chunk sort** approach (windows, `index` pointer, rotations)
- Review algorithmic reasoning in both A → B and B → A phases
- Detect potential infinite loops or logical edge cases
- Suggest small, well-understood optimizations
- Improve documentation clarity (README)

All code has been written, understood, tested, and debugged manually, in full compliance with the subject and Norminette.

---

## Subject compliance

- No forbidden functions are used
- No memory leaks
- Norminette compliant
- Proper error handling
- No external libraries
- Efficient and justifiable algorithm

---

## Author

Francisco Jaramillo  
42 Madrid – Common Core
