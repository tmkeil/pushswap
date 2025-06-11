# push\_swap – Sorting with Two Stacks

## Project Goal

Sort a list of integers using as few operations as possible. The rules:

* Only two stacks (`a` and `b`)
* Only a limited set of operations (`sa`, `pb`, `ra`, `rra`, ...)
* You can only work at the top of each stack – no direct access to the middle

---

## 🧠 What I Learned

* **Linked lists in C**
* **Algorithms under constraints**
* **Memory Management**

---

## 🔁 Allowed Operations

- `sa`: Swap the first two elements at the top of stack `a`
- `sb`: Swap the first two elements at the top of stack `b`
- `ss`: Perform `sa` and `sb` at the same time
- `pa`: Push the top element of `b` onto `a`
- `pb`: Push the top element of `a` onto `b`
- `ra`: Rotate `a` upwards (first element becomes last)
- `rb`: Rotate `b` upwards
- `rr`: Perform `ra` and `rb` at the same time
- `rra`: Reverse rotate `a` (last element becomes first)
- `rrb`: Reverse rotate `b`
- `rrr`: Perform `rra` and `rrb` at the same time

---


## My Implementation

I decided **not to use Radix Sort**. I think it causes too many operations in this specific case. You have to check **every bit**, starting from the **least significant**, and that means lots of pushes and rotations here.
Merge sort or insertion sort don't work either, since you only have access to the top of the stack.

Here’s what I did:

1. I divide the values in `a` into groups, based on size.
2. Smaller numbers get pushed to `b` step by step. Larger ones stay in `a` for now.
3. While pushing to `b`, I roughly sort it: smaller values go to the bottom (`rrb`), larger ones stay on top.
4. Once there are only 3 numbers left in `a`, I sort them.
5. Then I push numbers back from `b` to `a`, always choosing the one that can be inserted with **the fewest moves**.

This way I sort the whole list step by step – without unnecessary rotations.
