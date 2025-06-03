# C Coding Standard for LAB2

----------------------------

## 1. General Rules

1.1. Code must comply with the C99 standard.
*Example: Use `//` comments and `stdint.h` types.*

1.2. Maximum line width is 80 characters.
*Example: Avoid long function calls on a single line.*

1.3. Curly braces `{}` are required for all control blocks (`if`, `else`, `for`, `while`, `do`).

```c
if (status == OK)
{
    start_motor();
}
```

1.4. Parentheses must clarify operator precedence, especially with `&&`, `||`.

```c
if ((temp > 0) && (temp < 100))
{
    handle_range();
}
```

1.5. Tabs are forbidden. Use 4 spaces for indentation.

1.6. Each statement must be on its own line.
❌ `int a = 0; int b = 1;`
✅ `int a = 0;`
`int b = 1;`

1.7. Use `static`, `const`, and `volatile` keywords appropriately.

1.8. Avoid `goto`, `continue`, `register`, `auto` keywords.

1.9. Boolean variables must be of type `bool` from `<stdbool.h>`.

---

## 2. Naming Conventions

2.1. Function names: `snake_case`, verbs first: `read_adc()`, `init_timer()`.

2.2. Global variables: prefix with `g_`: `g_button_state`.

2.3. Pointers: prefix with `p_`, e.g., `p_buffer`.

2.4. Boolean variables: prefix with `b_`, e.g., `b_ready`.

2.5. Structs, unions, typedefs end in `_t`: `sensor_data_t`.

2.6. Avoid names that start with underscore `_` or match C/C++ keywords.

---

## 3. File and Module Structure

3.1. Each module consists of a `.c` and `.h` file pair.
*Example: `uart.c` and `uart.h`.*

3.2. Header files must have `#ifndef` inclusion guards.

```c
#ifndef UART_H
#define UART_H
... 
#endif /* UART_H */
```

3.3. Each `.c` must include its own `.h` to validate declarations.

3.4. Do not `#include` other `.c` files.

3.5. Public API should be declared in `.h`, and marked as `extern`.

3.6. Use `static` for private functions and variables.

---

## 4. Comments

4.1. Use `//` for single-line comments and `/* */` only for block-level docs.

4.2. Write comments in clear English, using complete sentences.

4.3. Avoid commented-out code. Use `#if 0` if needed temporarily.

4.4. Use capital tags like `TODO:`, `NOTE:`, `WARNING:` to indicate intent.

```c
// TODO: implement calibration
```

4.5. Document each function and module for Doxygen compatibility.

---

## 5. Whitespace and Formatting

5.1. Use 4-space indentation; no tabs.

5.2. Place one space after control keywords (`if`, `while`, etc.).

5.3. Surround binary operators with spaces: `a + b`, `x == y`

5.4. No space between function name and parentheses: `foo(x)`

5.5. Use blank lines to separate logical blocks of code.

---

## 6. Safety and Portability

6.1. Use fixed-width integer types: `uint8_t`, `int32_t`, etc.

```c
uint16_t adc_value = 0;
```

6.2. Avoid using `char`, `short`, `long` unless required for hardware registers.

6.3. Avoid implicit type conversions, especially between signed/unsigned.

6.4. Minimize use of `float`/`double`. If needed, use `float32_t`, `float64_t`.

6.5. Casts must be commented with rationale, e.g., `// safe cast from uint16_t to int32_t`

6.6. Use `volatile` for hardware register access and shared ISR variables.

```c
volatile uint32_t g_tick_count;
```

---

## 7. Interrupts and RTOS

7.1. ISR functions must be named `*_isr` and marked as `static`.

```c
static void timer1_isr(void)
{
    // Handle timer event
}
```

7.2. Task/RTOS thread functions must be named `*_thread` or `*_task`.

7.3. Shared variables between ISRs and main code must be `volatile` and protected appropriately.

---

## 8. Project Notes

8.1. Code must compile without warnings (with `-Wall -Wextra`).

8.2. Static analysis tools (e.g., Cppcheck) should be run before commits.

8.3. Code review comments must refer to the specific rule number (e.g., "Violates 2.3").

8.4. All code must pass peer review before merge.

---

*Adapted from "Barr Group Embedded C Coding Standard (BARR-C:2018)", see: [https://barrgroup.com/coding-standard](https://barrgroup.com/coding-standard)*
