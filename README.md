# Push_swap - Radix Sort Implementation

## Introduction

This repository contains my implementation of the **Push_swap** project from 42, where I use the **Radix Sort** algorithm to efficiently sort large stacks of numbers with the fewest possible operations.

## How Radix Sort Works

Radix Sort is a non-comparative sorting algorithm that processes numbers digit by digit, starting from the least significant bit (LSB) to the most significant bit (MSB). In the context of **Push_swap**, we use a binary representation of numbers and sort them based on their bits.

### Steps of Radix Sort in Push_swap:
1. **Convert Numbers to Indexed Values:**
   - Instead of sorting the raw numbers, we first assign each number an index based on its position in the sorted order. This ensures a range from `0` to `N-1`.
   
2. **Sorting by Bit Position:**
   - We loop through each bit (starting from the least significant bit) and split numbers into `stack_a` and `stack_b` based on whether the bit is `0` or `1`.
   - Push all numbers with `0` in the current bit position to `stack_b`.
   - Once the iteration for that bit is done, push all elements back from `stack_b` to `stack_a`.
   
3. **Repeat Until Sorted:**
   - Continue the process for all bits in the largest number (typically `log2(N)` iterations).
   - After all iterations, the stack will be sorted.

## Implementation in Push_swap

### Algorithm Breakdown:
```c
void radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    int max_bits = 0;
    int i, j;

    while ((size - 1) >> max_bits)
        max_bits++;

    for (i = 0; i < max_bits; i++)
    {
        int count = size;
        while (count--)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                pb(stack_a, stack_b);  // Push to stack_b if bit is 0
            else
                ra(stack_a);           // Rotate stack_a if bit is 1
        }
        while (*stack_b)
            pa(stack_a, stack_b);      // Push everything back to stack_a
    }
}
```

### Commands Used:
- `pb` (push to `stack_b`)
- `pa` (push back to `stack_a`)
- `ra` (rotate `stack_a`)

## Complexity & Performance
- **Time Complexity:** O(n log n) – Radix Sort is efficient for large datasets.
- **Space Complexity:** O(n) – Requires an additional stack.

## Why Use Radix Sort in Push_swap?
- Efficient for sorting large stacks (`>100` elements) compared to other sorting strategies.
- Uses fewer operations compared to standard sorting algorithms like Bubble Sort.
- Works well within the constraints of Push_swap's limited command set.

## Usage
If you want to run the Radix Sort implementation in your Push_swap project:
1. Clone this repository:
   ```sh
   git clone https://github.com/YOUR_GITHUB_USERNAME/push_swap.git
   ```
2. Compile the project:
   ```sh
   make
   ```
3. Run the program with a set of numbers:
   ```sh
   ./push_swap 4 67 3 87 23 1
   ```

## Conclusion
This Radix Sort approach provides an efficient way to tackle the sorting challenge in **Push_swap**, ensuring minimal moves and optimal performance. Feel free to contribute or suggest improvements!

