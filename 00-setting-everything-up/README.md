
_NOTICE:_
_Words between arrows are placeholders meant to be replaced, for example `<filename>` -> `README.md`_


# Setting everything up

This entry will provide necessary steps to **setup** your **environment** for _pleasant_ (but _not platform dependent_) development on Windows (if you use Linux then the steps are _mostly_ the same, you need to use your package manager and install packages with their actual name), teach you some basic **bash commands**, how to **use terminal** and **IDE**, **compile** and **run code**.

> [!NOTE]
> You will need about 5Gb of storage available.

## MSYS2

**MSYS2** (Software Distribution and Building Platform for Windows) is basically a **Linux terminal emulator for Windows** _how I like to call it_. You will need it to **install essential packages for development**. It's much _faster_ to do things via _terminal_ 👍, than via _browser_ 👎 so that's how you'll be doing it. ~~But Window is useless, so we need to install Linux terminal for this.~~

### Installation and setup

1. Install *msys2-x86-64* from the [official web site](https://www.msys2.org/).
2. After installing MSYS2 you'll get many instences of it appeared in your start menu. You need to launch **MSYS2 UCRT64**.

> [!IMPORTANT]
> Use only **MSYS2 UCRT64**, you won't need other MSYS2 things.


3. **Update packages**. In UCRT64 terminal window type this:
```sh
pacman -Syu
```

> [!TIP]
> You can use `Shift+ins` or the **middle mouse button** to _paste text_.

> [!IMPORTANT]
> Rerun the command if you get any errors.


4. **Install** a **compiler** with other necessary **tools for development**:

```shell
pacman -S mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-git mingw-w64-ucrt-x86_64-github-cli \
    mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja make\
    mingw-w64-ucrt-x86_64-clang-tools-extra \
    mingw-w64-ucrt-x86_64-raylib \
    mingw-w64-ucrt-x86_64-emscripten \
    fish
```

<details>
<summary>Explanation of the command</summary>

This command installs:
1. `mingw-w64-ucrt-x86_64-gcc` - compiler
1. `mingw-w64-ucrt-x86_64-git mingw-w64-ucrt-x86_64-github-cli` - source control system
1. `mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja make` - build system generator and build system to build an executable, manage dependencies and configure the project
1. `mingw-w64-ucrt-x86_64-clang-tools-extra` - C/C++ LSP (more about LSP in the [IDE chapter](#ide))
1. `mingw-w64-ucrt-x86_64-raylib` - a simple and easy-to-use library to enjoy videogames programming!
1. `mingw-w64-ucrt-x86_64-emscripten` - library to compile C/C++ code to WebAssembly, to run it in a web browser (it's package is 1.6Gb on Windows btw)
1. `fish` - user-friendly interactive Unix shell

</details>

5. Add UCRT64's bin to *PATH* so all applications can find and use the thing you just installed (we need this so IDE can find LSP and compiler):
```shell
setx PATH "%PATH%;C:\msys64\ucrt64\bin"
```

---

### Basic shell commands

This paragraph will introduce you to some basic ~~Linux~~ MSYS2 **shell commands**.

#### pacman

Did you notice that `pacman` command? `pacman` is a **package manager** for MSYS2 ~~and also Arch btw~~ and it is used to (surprise-surprise) manage packages.

- `pacman -Syu` update and upgrade packages.
- `pacman -Ss <package-name>` to search for a package:
    ```shell
    pacman -Ss matrix
    ```
- `pacman -S <package-name>` to install a package:
    ```shell
    pacman -S cmatrix
    ```
- Run installed package:
    ```shell
    cmatrix
    ```
> [!TIP]
> Use `Ctrl+C` to kill a running process.

- `pacman -Rns <package-name>` to delete a package with it's dependencies that no longer used:
    ```shell
    pacman -Rns cmatrix
    ```
- See what will happened if you try to run it after deleting it:
    ```shell
    cmatrix
    ```
- `pacman -h` of `pacman --help` to print help info.

> [!TIP]
> Majority of **CLI** (Command Line Interface) utils provide `-h` or `--help` flag, so you can learn what they do and what arguments they accept.

#### ls

`ls` is used to **list files of directories**.

- `ls` to list files in current directory.
- `ls ..` to list files in parent directory of current directory.
- `ls <some-dir-name>` to list files in some directory:
    ```shell
    ls main/include # Using relative path (from current directory)
    ls /C/Users # Using absolute path (slash / is a root directory in Linux, directory of all directories, like C:\ on Windows)
    ```
- `ls -h` or `ls --help` to print more info.

> [!TIP]
> You can use `ArrowUp` and `ArrowDown` to scroll through command history.

#### cd

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

That were all shell commands that you need to know for now.

### Terminal usage exercises

- Find a package with `fastfetch` in it's name for UCRT64 platform and install it. Run `fastfetch` in your terminal.
- Find a package with `cow` in it's name for UCRT64 platform and install it. Figure out how to make cow say something.
- Enter the root foolder of your C disk with `cd /C`. And using just `ls` and `cd` find there your `Pictures` folder.
- Think about where you want to store all your programming projects. Using just `cd` and `ls` find a folder there you want (I suggest to use `Documents`, or `Desktop`, or your user's folder for that). Then you entered that folder, create a folder for your projects with `mkdir Programming` or whatever you like to name it. Enter newely create folder.


## IDE

**IDE** (Integrated Development Environment) is the application that you use for writing code. For comfortable development it need to support **syntax highlighting** and **LSP** (Language Server Protocol (thing that your IDE uses for error checking at runtime and code completion)).

### Choosing an IDE

**Visual Studio** is a popular IDE for **C/C++** and **C#** development available **only** for **Windows**. With 'Desktop development with C++' selected takes up enormous **12GB of storage** 💀 and it requires you to configure project specific settings with a looot of options, for you to do development in this specific IDE ☠️.

**Visual Studio Code** is the most **popular cross-platform normie** IDE, works well with _almost_ **any programming language**. Takes up **1-1.5GB of storage** (needs extensions to work with C/C++). Also depends on project settings. Not that bad, but not good ether 😐, there are better options.

**[Zed](https://zed.dev/download)** is a relatively **new**, **modern** and **fast** IDE, works well with **many programming languages**. You can do C/C++ development without any project-specific settings 👍. If I were a normie, I'd use it 👍🔥🔥🔥. Takes up about **600MB of storage**.

> [!NOTE]
> You will be using **Zed**. So install it from the [official web site](https://zed.dev/download) if you haven't done that yet.

### Configuring Zed

To configure Zed you need to **replace your** `settings.json` and `keymap.json` **with** same **files from this folder**. You can _watch a video_ from the next chapter to see how to do this.

### Using Zed

I decided that it's easier to show it once than to include dozens of screenshots and paragraghs explaining how to use it.

<details>
<summary>Shortcuts cheat sheet</summary>

#### Project and settings

| Shortcut | Action |
| -------- | ------ |
| `Ctrl+O`       | open a file or a folder |
| `Ctrl+Shift+S` | save as |

#### Moving around

| Shortcut | Action |
| -------- | ------ |
| `Ctrl+P`                  | file picker |
| `Ctrl+Shift+P`            | command picker |
| `Ctrl+Alt+B`              | project panel |
| ``Ctrl+` ``               | terminal |
| `Ctrl+E`                  | focus editor |
| `Alt+Right` or `Alt+Left` | go to next or previous pane |

#### Working with code

| Shortcut | Action |
| -------- | ------ |
| `Ctrl+/`                    | comment a line |
| `Ctrl+>` or `Ctrl+<`        | indent or outdent |
| `Tab` or `Shift+Tab`        | LSP next or previous item |
| `Ctrl+Left` of `Ctrl+Right` | move left or right one word |
| `Shift+Arrows`              | select code |
| Hover                       | show variable/function information |
| Hover + `Ctrl` + click      | go to variable/function definition |

#### Working with terminal

| Shortcut | Action |
| -------- | ------ |
| `Ctrl+C`        | kill running process |
| `Up` and `Down` | scroll through command history |
| `Tab`           | antocomplete commands, flags and files |

</details>


## Git

**Git** is a distributed **version control system**, but to version control your code you need to _store it_ somethere, of course you can store it on your PC, but if you want to _share it_, or _work together with someone_, or just be able to easily _access it from different devices_ you need a **hosting service** that uses Git. We'll be using **Github** for that.

### Setup

1. **Create** a **Github account** on the [official site of Github](https://github.com/).
2. **Log in** to your Github account from MSYS2 shell:
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

### Basic Git and GitHub CLI commands

I think the easiest way to explain Git and GiHub CLI commands is by _examples_:

#### Creating a new repository

0. If you want to use an _existing folder_, you need to **initialize** your repository:
    ```shell
    cd <folder>
    got init
    ```
1. Create repository on GitHub:
    ```shell
    gh repo create
    ```
    or if you want to use someone's _template_, you must specify everything in one command:
    ```shell
    gh repo create -c -p https://github.com/infgotoinf/enjoy-raylib <your-repo-name> --public
    ```

#### Committing ~~crimes~~ changes

To _save_ and _upload changes_ you made to your repo you do this:

0. Optionally list all changes:
    ```shell
    git status
    ```
1. **Add files** _you want_ to be _updated_ to the **index** so they can be later **committed**:
    ```shell
    git add <filename1> <filename2> <filename3>
    ```
    or if you want to add all changes:
    ```shell
    git add .
    ```
2. Create a **commit**, write a **commit message**:
    ```shell
    git commit -m "<your-commit-message>"
    ```
    or to write commit in your _editor_:
    ```shell
    git commit
    ```
3. Push your changes:
    ```shell
    git push
    ```

#### Cloning existing repository

```shell
git clone <link-to-the-repo>
```

#### Fetching changes that were made to repo

```shell
git pull
```

### Giiteuagte ecitses

_(Do all this inside a folder for your Programming projects)_
- Using `gh` and `git` cleate a repo and call it with **your GitHub username**. Inside it create a `README.md` file and write something about yourself in it. Commit the changes, then push them to GitHub. Open your profile on GitHub, it should show the text you just wrote.
- Clone this repo `https://github.com/infgotoinf/c-and-raylib-for-noobs.git`, look what's inside.
- Create another repo using this template `https://github.com/infgotoinf/enjoy-raylib`, call it something like 'game' or whatever you want. Read it's `README.md` and follow it's build instructions. Build and run the game both for Desktop and Web (run `make help` if you don't know hot to do that), if it builds and runs without any errors then harray! 🎉 You did it all correct! 🥳 ... And if you have errors... 😢 🙏
