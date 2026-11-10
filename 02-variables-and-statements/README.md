# Variables and Statements

```c
const char* var = "Hello, I am a variable!";
```

## Variables

Variable is a human readable **name** that refers to some **data** in memory. You can think of **memory** as a **big array of bytes**. Each variable name maps to some specific memory index or, more precisely, **adress**.

### Variable names

For variable names you can use any characters in the range of 0-9, A-Z, a-z, and underscore (`_`), with the following rules:

- You can’t start a variable with a digit 0-9.
- You can’t start a variable name with two underscores __.
- You can’t start a variable name with an underscore followed by a capital A-Z.

> [!NOTE]
> Fun fact: you can use Unicode characters for variable names, so you can name it for example `переменная` or `😎😀🥰`. Tho nobody seriously uses this.

### A little bit about C standarts

When you read about some library or project written in C or C++ you will often see something like C89 (ANSI C), or C99, C11, C23, C++11, C++14, C++17, C++23, etc. instead of just C or C++. That's called **standard** and number means **year** then it was introduced. Each standart adds new **features** to the language, **reworks** some old ones and **deprecates** the bad ones. You'll be using C23 and C++23.

### Variable types

Here are some basic C types:

| Type | C Type | Example |
| ---- | ------ | ------- |
| Boolean               | bool        | true            |
| Integer number        | int         | 32349           |
| Floating point number | float       | 3.14159         |
| Double number         | double      | 12.87263e+6     |
| (single) Character    | char        | 'c'             |
| String                | const char* | "Hello, World!" |

> [!NOTE]
> `bool` type was added only in `C23`.

Let's write some basic program using them:
```c
#include <stdio.h>

int main(void)
{
    int i = 2;
    const char* text = "Cool!";

    printf("%d + %d = %d\n", i, i, i + i);
    printf("%s\n", text);

    return 0;
}
```

It outuputs this:
```text
2 + 2 = 4
Cool!
```

Cool!.. Wait, what was those `%d` and `%s`?

### `printf`

`printf` is called "printf", because it **formats** a string and **writes** it to **standard output**. A format specifier starts with a % character and has one or more following characters that specify how to serialize a value.
