# Hello World in C

## Why learn C?

You probably have almost no programming experience at all, so why do learn C? Why not something simpler like Python?

**Python** is a **garbage collected** (automatically frees memory), **dynamically typed** (runtime type checking, that adds overhead and leads to variable type ambiguity for developer) **interpreted scripting language** (executed at runtime, requires interpreter to be bundled with a program). Python is good for writing **scripts**, **automation** or something that **rely** all computation on **good libraries**. Python is good as a _second language_ used side by side with compiled one for example for **plugin system** ([Krita](https://docs.krita.org/en/user_manual/python_scripting.html) and [Blender](https://docs.blender.org/api/current/) do like that). For complex, performance‑critical desktop applications or games, a **compiled language will be** much **better**, since all performant libraries for Python are written in compiled languages such as C and C++.

**C** is a **manual memory menagment** (manual memory allocation and deallocation), **statically typed** (variables explicitly declared with a type), **compiled programming language** (code must be compiled in order to run). But ok, it's compiled and statically typed and stuff, but why not like Java or C++ or Rust or whatever? C is the **father** of the _majority_ of modern programming languages, because of that **libraries written in C** can be **used** _almost_ in **any language** without much hustle (in fact [Raylib](https://www.raylib.com/) is written in C). C by itself is much _simpler_ than any of all that languages, and _if you learn it's concepts_ it will be **easier to learn** all those other **programming languages**.

By itself C is a very _limited_ programming language, _compared to modern languages_: it doesn't have that many features as they do (and so C devs implement those features by themselves), but for your first game you **won't need modern features**. You will learn _basics_ of C, it's _limitations_ and will slowly _transition to C++_.

## Introduction to C

A basic example of C program looks like this:
```c
/* "Hello World" program */

#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n"); // Printing "Hello, World!"
    return 0;
}
```

Run it and see what will happened:
```shell
git clone https://github.com/infgotoinf/c-and-raylib-for-noobs.git
cd c-and-raylib-for-noobs/01-hello-world-in-c
make run
```

It will output something like:
```text
gcc hello_world.c -o program
./program
Hello, World!
```

### Makefile

Before explaining the code, let me _quickly_ explain why it outputs all that. So yeah, you can see "Hello, World!" in the code, but where are from all that `gcc hello_world.c -o program` and `./program`? If you run `ls` in current directory you'll see this:
```text
hello_world.c
hello_world.py
Makefile
program
README.md
```

So ok `hello_world.c` is the file with our code, (`hello_world.py` we'll ignore) `program` is the executable program we run and `README.md` is the file you're reading right now, but what is that `Makefile`? Lets see...
```Makefile
all: run

build:
	gcc hello_world.c -o program

run: build
	./program

clean:
	rm program
```

Aha! So this is where those `gcc hello_world.c -o program` and `./program` came from!.. But ok, it doesn't explain much, what is this file? What are those commands?

#### Difference between compiled and interpreted languages

Remember I was telling you that _Python_ is an _interpreted_ language and _C_ is a _compiled_ one?

##### Interpreted

To **run code** written in an _interpreted_ language, you invoke the _interpreter_ and _pass_ it the file containing the _code_, so interpreter can **execute** it. You can try this with Python:
```shell
pacman -S python       # Installing Python
python hello_world.py  # Running program
```

`hello_world.py` looks like this:
```py
print("Hello, World!")
```

And after running `python hello_world.py` it will output:
```text
Hello, World!
```

##### Compiled

To **run** code written in a _compiled_ language, you firstly invoke the _compiler_ and _pass_ it the file containing the _code_, so compiler can **compile** it into an **executable binary file**, and then you **run** the _generated file_. There are many compilers for C and C++, but we'll be using `gcc` and so we build and run our code like this:

1. Pass our code to the compiler, and tell it with `-o` flag to **output** generated executable code to the file called `program`:
    ```shell
    gcc hello_world.c -o program
    ```
2. Run generated executable file:
    ```shell
    ./program
    ```

> [!NOTE]
> On Windows executable files have `.exe` extension, cause Windows determines file type by it's extension. On Linux they don't have any extensions, because Linux checks file's metadata to determine file type.

#### Back to Makefile

So ok, that explains the meaning of those commands, but how they get called then I run `make run`? Let me show you `Makefile`'s code one more time:
```Makefile
all: run

build:
	gcc hello_world.c -o program

run: build
	./program

clean:
	rm program
```

`all`, `build`, `run` and `clean` are the **targets** defined inside that `Makefile`. After colons (:) there are their **prerequesties** (`all: run`, `run: build`). And on the new lines there are commands **indented using `TAB`s**. To run those targets you use `make`. For example:

- Running `make build`, will run the `build` target which has no prerequesties:
    ```Makefile
    build:
    	gcc hello_world.c -o program
    ```
    That will just execute `gcc hello_world.c -o program`.

- Running `make run`, will run the `run` target which has `build` prerequestie:
    ```Makefile
    run: build
    	./program
    ```
    So before executing `./program` it will run `build` target which will execute `gcc hello_world.c -o program`. And so this is the reason, that then you run `make run` it prints:
    ```text
    gcc hello_world.c -o program
    ./program
    ```
    And only then:
    ```text
    Hello, World!
    ```
- Running `make clean`, will run the `clean` target with command `rm program`, which will remove `program` file.
- Running `make` runs the first found target, which is `all` with no commands and a `run` prerequestie, so it will just simply `run` target and so running `make`, `make all` and `make run` with current `Makefile` will result the same.

Knowing all that you can pretty much create any target you want, for example:
```Makefile
# Target that prints "Hello, World!" to the terminal
hello:
	echo "Hello, World!"

# Target that runs multiple commands
many_hello:
	echo "Hello, World1!"
	echo "Hello, World2!"

# Target that runs multiple prerequesties and no commands
ultimate_hello: hello many_hello
```

And although `make` _can_ be used _beyond_ that, to build _complex projects_ with _many dependencies_ and _custom flangs_, it's **too manual** and **gets** too **huge** with a **big project scale**. So we'll be using it just to _define custom targets_, to _easily run_ multiple _commands_. For building complex projects we'll be using **CMake**, but _that will be later_, for now all we need is a good old `make` with a simple `Makefile`.

### Explaining the code

Yup, as always, I told to do something _quickly_ and it took me like 3 pages of text, but I hope you haven't died after reading all that, cause there is more to go!

```c
/* "Hello World" program */

#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n"); // Printing "Hello, World!"
    return 0;
}
```

- Comments `/* ... */` `// ...`
    
    Anything between `/*` and `*/` or after `//` is a comment and gets ignored by the compiler. You can have how many comments you want in your code or none of them, it doesn't matter, compiler will completely ignore them.
- Includes `#include <...>`
    
    Lines that start with `#include` tell the _C preprocessor_ to _insert_ the _contents_ of some _file_ right there. And `<stdio.h>` is the **"Standard I/O"** _header file_, it provides us `printf` function, so we can invoke it. If you comment out the line with `#include <stdio.h>` the compiler will tell us to provide `printf` declaration or add `#include <stdio.h>` line.
- `main` function
    
    Right after include we see our _main function_ `int main(void)` and then curly braces (`{` and `}`) with it's definition. In C and C++ this is the function which gets called upon executing our code.
    - `return 0;`
        
        This line is related to our `main` function, it makes our program to exit with code `0`, which means that it was executed without any errors. Then the program reaches that line
- `printf` function
    
    This function prints text to the console and we call it with one parameter, `"Hello, World!\n"`. It looks straightforward, except for that `\n` at the end. This called an **escape sequence**. Escape sequence always begins with a backslash (`\`) and lets us write a character that otherwise couldn't be written. And `\n` means a **newline** character.

> [!NOTE]
> Note, that lines without include and main function declaration have semicolin (`;`) at the end. They tell the compiler that this is the _end of the expression_ and you gonna be using them **a lot**.

## Exercises

- Try messing around with this "Hello World" program!
   - Change `"Hello, World\n"` in `printf` function call to whatever you want
   - Try removing `#include <stdio.h>`
   - Try adding more `printf`'s
   - Try removing and adding more `\n`
   - Try writing text after `\n`
- Write another C program, that prints something different. Create a new target in `Makefile` to build and execute that program. Run target to execute the first program and then target to execute the second one.

> [!IMPORTANT]
> Commands  must be **indented using `TAB`s**! Otherwise `make` will complain.

- Create a new target to execute both programs. Run in.
