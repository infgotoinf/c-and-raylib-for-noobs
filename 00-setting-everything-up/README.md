# Setting everything up

## Windows

This entry will provide necessary steps to **setup** your **environment** for *pleasant* (but *not platform dependent*) development on Windows, teach you some basic **bash commands**, how to **use terminal** and **IDE**, **compile** and **run code**.

> [!NOTE]
> You will need about 2.5Gb of storage available.

### MSYS2

**MSYS2** (Software Distribution and Building Platform for Windows) is basically a **Linux terminal emulator for Windows** *how I like to call it*. You will need it to **install essential packages for development**. It's much *faster* to install things via *terminal* 👍, than via *browser* 👎 so that's how you'll be doing it. ~~But Window is useless, so we need to install Linux terminal for this.~~

#### Installation and setup

1. Install *msys2-x86-64* from the [official web site](https://www.msys2.org/).
2. After installing MSYS2 you'll get many instences of it appeared in your start menu. You need to launch **MSYS2 UCRT64**.

> [!IMPORTANT]
> Use only **MSYS2 UCRT64**, you won't need other MSYS2 things.


3. **Update packages**. In UCRT64 terminal window type this:
```sh
pacman -Syu
```

> [!TIP]
> You can use `Shift+ins` or the **middle mouse button** to *paste text*.

> [!IMPORTANT]
> Rerun the command if you get any errors.


4. **Install** a **compiler** with other necessary **tools for development**:

```shell
pacman -S mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-git mingw_w64-ucrt-x86_64-github-cli \
    mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja \
    mingw-w64-ucrt-x86_64-clang-tools-extra \
    fish
```

<details>
<summary>Explanation of the command</summary>

This command installs:
1. `mingw-w64-ucrt-x86_64-gcc` - compiler
1. `mingw-w64-ucrt-x86_64-git mingw_w64-ucrt-x86_64-github-cli` - source control system
1. `mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja` - build system generator to build an executable, manage dependencies and configure the project
1. `mingw-w64-ucrt-x86_64-clang-tools-extra` - C/C++ LSP (more about LSP in the [IDE chapter](#ide))
1. `fish` - user-friendly interactive Unix shell

</details>

5. Add UCRT64's bin to *PATH* so all applications can find and use the thing you just installed (we need this so IDE can find LSP and compiler):
```shell
setx PATH "%PATH%;C:\msys64\ucrt64\bin"
```

---

#### Basic shell commands

This paragraph will introduce you to some basic ~~Linux~~ MSYS2 **shell commands**.

##### pacman

Did you notice that `pacman` command? `pacman` is a **package manager** for MSYS2 ~~and also Arch btw~~ and it is used to (surprise-surprise) manage packages.

- `pacman -Ss <package-name>` to search for a package:
    ```shell
    pacman -Ss matrix
    ```
- `pacman -S <package-name>` to install a package:
    ```shell
    pacman -S cmatrix
    ```
- `pacman -Rns <package-name>` to delete a package with it's dependencies that no longer used:
    ```shell
    pacman -Rns cmatrix
    ```
- `pacman -h` of `pacman --help` to print help info.

> [!TIP]
> Majority of **CLI** (Command Line Interface) utils provide `-h` or `--help` flag, so you can learn what they do and what arguments they accept.

##### ls

`ls` is used to **list files of directories**.

- `ls` to list files in current directory.
- `ls ..` to list files in parent directory of current directory.
- `ls <some-dir-name>` to list files in some directory:
    ```shell
    ls main/include # Using relative path
    ls /C/Users # Using absolute path
    ```
- `ls -h` or `ls --help` to print more info.

> [!TIP]
> You can use **Arrow keys Up** and **Down** to scroll through command history.

##### cd

`cd` is used to **change working directory**.

- `cd ..` to change working directory to parent directory of current directory.
- `cd <some-dir-name>` to change working directory to some directory:
    ```shell
    cd main/include # Using relative path
    cd /C/Users # Using absolute path
    ```
- `cd -h` or `cd --help` to print more info.

> [!TIP]
> You can use `Tab` key to **autocomplete commands**, **flags** and **filenames** in terminal.
>
> To see what I'm talking about enter **fish shell** with `fish` command, and enter 'Users' directory with `cd /C/Users` command. Then try typing:
> 1. `ls` (without space) and hitting `Tab` multiple times.
> 2. `ls ` (with space) and hitting `Tab` multiple times.
> 3. `ls -` (with hypothen after space) and hitting `Tab` multiple times.

That's it with shell commands that you need to know for now.

---

### IDE

**IDE** (Integrated Development Environment) is the application that you use for writing code. For comfortable development it need to support **syntax highlighting** and **LSP**
(Language Server Protocol (thing that your IDE uses for error checking at runtime and code completition))

#### Choosing an IDE

**Visual Studio** is a popular IDE for **C/C++** and **C#** development available **only** for **Windows**. With 'Desktop development with C++' selected takes up enormous **12GB of storage** 💀 and it requires you to configure project specific settings with a looot of options, for you to do development in this specific IDE ☠️.

**Visual Studio Code** is the most **popular cross-platform normie** IDE, works well with *almost* **any programming language**. Takes up **1-1.5GB of storage** (needs extensions to work with C/C++). Also depends on project settings. Not that bad, but not good ether 😐, there are better options.

**[Zed](https://zed.dev/download)** is a relatively **new**, **modern** and **fast** IDE, works well with **many programming languages**. You can do C/C++ development without any project-specific settings 👍. If I were a normie, I'd use it 👍🔥🔥🔥. Takes up about **600MB of storage**.

> [!NOTE]
> You will be using **Zed**. So install it from the [official web site](https://zed.dev/download) if you haven't yet.


### Git

**Git** is a distributed version control system, but to version control your code you need to store it somethere, of course you can store it on your PC, but if you want to share it, or work together with someone, or just be able to easly access it from different devices you need a **hosting service** that uses Git. We'll be using **Github** for that.

#### Setup

1. **Create** a **Github account** on the [official site of Github](https://github.com/).
2. Login to your Github account from MSYS2 shell:
    ```shell
    gh auth login
    ```
3. Check that login was successful:
    ```shell
    gh auth status
    ```
4. Set **your user email** and **user name** for Git operations:
    ```shell
    git config --global user.email "you@example.com" # Put your email here
    git congit --global user.name "Your Name" # Put your name here
    ```

That was the whole Git setup.

---

#### Basic Git commands



### Exsersises

#### Terminal usage

- Find a package with `fastfetch` in it's name for UCRT64 platform and install it. Run `fastfetch` in your terminal and send me the screenshot.
- Find a package with `cow` in it's name for UCRT64 platform and install it. Figure out how to make cow say something and send me the screenshot.

#### Git usage
