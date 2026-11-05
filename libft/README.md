*This project has been created as part of the 42 curriculum by v*

# Libft

## Description

Libft is the first project of the 42 Common Core. The goal is to rebuild a set of standard C library functions from scratch and extend it with additional utility functions that will be reused throughout the rest of the curriculum.

The library is compiled into a static archive (`libft.a`) that can be linked to any future project, eliminating the need to rewrite common operations each time.

**What it covers:**
- Character classification and conversion
- Raw memory manipulation
- String operations with safe size bounds
- Number conversion (string ↔ integer)
- Output to arbitrary file descriptors
- Singly linked list creation and manipulation

---

## Instructions

### Compile

```bash
make        # builds libft.a
make re     # full recompile from scratch
```

### Use in another project

```bash
cc main.c -L. -lft -o program
```

Or link directly against the archive:

```bash
cc main.c libft.a -o program
```

### Makefile rules

| Rule | Effect |
|------|--------|
| `make` / `make all` | Compiles `libft.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | `fclean` + `all` |

Compiled with: `cc -Wall -Wextra -Werror`

---

## Library reference

### Part 1 — Libc reimplementations

Reimplementations of standard C library functions. All function names are prefixed with `ft_`.

| Function | Description |
|----------|-------------|
| `ft_isalpha` | Returns non-zero if `c` is a letter (A–Z or a–z) |
| `ft_isdigit` | Returns non-zero if `c` is a decimal digit (0–9) |
| `ft_isalnum` | Returns non-zero if `c` is a letter or digit |
| `ft_isascii` | Returns non-zero if `c` is a valid ASCII character (0–127) |
| `ft_isprint` | Returns non-zero if `c` is a printable character (32–126) |
| `ft_toupper` | Converts a lowercase letter to uppercase; returns `c` unchanged otherwise |
| `ft_tolower` | Converts an uppercase letter to lowercase; returns `c` unchanged otherwise |
| `ft_memset` | Fills the first `n` bytes of memory area `s` with byte value `c` |
| `ft_bzero` | Sets the first `n` bytes of memory area `s` to zero |
| `ft_memcpy` | Copies `n` bytes from `src` to `dest`; regions must not overlap |
| `ft_memmove` | Copies `n` bytes from `src` to `dest`; handles overlapping regions correctly |
| `ft_memchr` | Finds the first occurrence of byte `c` within the first `n` bytes of `s` |
| `ft_memcmp` | Compares the first `n` bytes of two memory areas; returns the difference at the first mismatch |
| `ft_strlen` | Returns the number of bytes in string `s`, excluding the null terminator |
| `ft_strlcpy` | Copies at most `size - 1` characters from `src` to `dest`, always null-terminates; returns `strlen(src)` |
| `ft_strlcat` | Appends `src` to `dest` up to `size` total bytes, always null-terminates; returns the length that would result without truncation |
| `ft_strchr` | Returns a pointer to the first occurrence of `c` in `s`, or NULL |
| `ft_strrchr` | Returns a pointer to the last occurrence of `c` in `s`, or NULL |
| `ft_strncmp` | Compares up to `n` characters of two strings; returns negative, zero, or positive |
| `ft_strnstr` | Locates `needle` in `haystack`, searching at most `len` bytes |
| `ft_atoi` | Converts the initial portion of `nptr` to an integer, skipping leading whitespace |
| `ft_calloc` | Allocates memory for `count` elements of `size` bytes each, zero-initialized |
| `ft_strdup` | Returns a freshly allocated copy of string `s` |

### Part 2 — Additional functions

Functions not present in the standard library, or present in a different form, designed to complement Part 1.

| Function | Description |
|----------|-------------|
| `ft_substr` | Allocates and returns a substring of `s` starting at index `start` with maximum length `len` |
| `ft_strjoin` | Allocates and returns the concatenation of strings `s1` and `s2` |
| `ft_strtrim` | Allocates and returns a copy of `s` with all leading and trailing characters in `set` removed |
| `ft_split` | Splits `s` by delimiter `c` and returns a NULL-terminated array of substrings |
| `ft_itoa` | Allocates and returns the string representation of integer `n`; supports negative values |
| `ft_strmapi` | Applies function `f(index, char)` to each character of `s` and returns the resulting new string |
| `ft_striteri` | Applies function `f(index, &char)` to each character of `s`, modifying it in place |
| `ft_putchar_fd` | Outputs character `c` to file descriptor `fd` |
| `ft_putstr_fd` | Outputs string `s` to file descriptor `fd` |
| `ft_putendl_fd` | Outputs string `s` followed by a newline to file descriptor `fd` |
| `ft_putnbr_fd` | Outputs integer `n` to file descriptor `fd` |

### Part 3 — Linked lists

Functions to create and manipulate singly linked lists using the `t_list` struct defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` holds any data via a `void *` pointer. `next` points to the following node, or `NULL` if it is the last one.

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Allocates and returns a new node with the given `content` |
| `ft_lstadd_front` | Inserts `new` at the beginning of the list pointed to by `lst` |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns a pointer to the last node of the list |
| `ft_lstadd_back` | Appends `new` at the end of the list pointed to by `lst` |
| `ft_lstdelone` | Frees the memory of node `lst` using `del` on its content; does not free `next` |
| `ft_lstclear` | Deletes and frees every node of the list using `del`; sets the pointer to NULL |
| `ft_lstiter` | Iterates the list and applies function `f` to the content of each node |
| `ft_lstmap` | Iterates the list, applies `f` to each node's content, and returns a new list built from the results; uses `del` on failure |

---

## Resources

- [`man 3 string`](https://man7.org/linux/man-pages/man3/string.3.html) — Linux manual pages for standard string functions

- [cppreference — C standard library](https://en.cppreference.com/w/c) — complete reference for all libc functions and types

- [Data Structures and Algorithms - (DSA)](https://www.geeksforgeeks.org/c/learn-dsa-in-c/) — Master Data Structures and Algorithms Using C

### AI usage

Claude (Anthropic) was used during the development of this project. Its involvement was limited to two areas:

1. **Code review and discussion** — implementations were written independently and then reviewed with Claude to discuss edge cases, type choices, and potential undefined behavior (for example, overflow handling in `ft_calloc` and `ft_itoa`, operand ordering in `ft_strlcat` and `ft_strnstr`). No code was generated or copied from these sessions; the conversations were used as a sounding board to deepen understanding.

2. **README authoring** — the structure and content of this document were written with Claude's assistance, based on the project requirements and the work completed.

All submitted `.c` and `.h` files were written by the author. No AI-generated code is present in the repository.
