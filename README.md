# Simple Shell Project - Holberton School

## Project Description
This repository contains the **Simple Shell** project from Holberton School.  
It is a **Unix command-line interpreter** implemented in C that executes commands, handles arguments, supports built-in commands, and manages processes.  

The project demonstrates strong knowledge of:
- Low-level programming in **C**
- **System calls** (fork, exec, wait, etc.)
- **Memory management**
- **Error handling**
- **Process management**

---

## Extended Description
The **Simple Shell** project is designed to provide hands-on experience with how shells operate internally.  
Key highlights of this project include:

- **Command Execution:** Learn how to execute programs from the command line using system calls like `fork()`, `execve()`, and `wait()`.  
- **Built-in Commands:** Implement internal commands like `exit`, `env`, and `cd`, mimicking real shell behavior.  
- **Error Handling:** Properly detect and handle invalid commands, syntax errors, and unexpected inputs.  
- **Signal Handling:** Understand and manage signals (e.g., `SIGINT`) to improve user experience.  
- **Memory Management:** Manage dynamic memory for strings, arrays, and buffers, preventing leaks or crashes.  
- **Command History:** Store and retrieve past commands efficiently, enhancing shell functionality.  

This project deepens understanding of **low-level programming concepts**, **operating systems fundamentals**, and **how high-level shell features are implemented under the hood**.  

---

## Requirements
- Implement a shell in **C**.
- Support execution of **basic commands** found in `/bin/`.
- Handle **command-line arguments**.
- Implement **built-in commands**: `exit`, `env`, `cd`.
- Handle **signals** (e.g., SIGINT).
- Support **command history**.
- Handle **errors gracefully** (invalid commands, syntax errors).
- Compile using `gcc` with flags:  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`

---

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
- Produces an executable named `hsh`.

---

## Usage
Start the shell:

```bash
./hsh
```

### Examples
```bash
(simple_shell)$ ls -l
(simple_shell)$ pwd
(simple_shell)$ env
(simple_shell)$ cd /tmp
(simple_shell)$ exit
$
```

### Built-in Commands
- `exit [status]` - Exit the shell with optional status code.
- `env` - Print environment variables.
- `cd [directory]` - Change the working directory.

---

## Project Files
| File/Folder | Description |
| ----------- | ----------- |
| `.simple_shell_history` | Stores command history |
| `AUTHORS` | Contributors list |
| `README.md` | Project documentation |
| `*.c` | C source files for shell implementation |
| `main.h` | Header file with function prototypes |
| `man_1_simple_shell` | Manual page describing usage |

---

## About the Developer
👨‍💻 **Ahmad Nawabi**  
- Passionate **Software Engineer** with strong experience in **C programming**, **Python**, and **full-stack web development**.  
- Experienced in designing optimized, scalable solutions with clean and maintainable code.  
- Skilled at solving complex problems and collaborating in a team-driven environment.  

🔗 Connect with me:  
- LinkedIn: [linkedin.com/in/ahmadnawabi](https://www.linkedin.com/in/ahmadshamoonnawabi)  
- GitHub: [github.com/AhmadNawabi](https://github.com/AhmadNawabi)  
- Portfolio: [ahmadnawabi.com](https://ahmadnawabi.github.io/Personal_Website)  

---

## Notes
- No screenshots included (terminal-based project).  
- No live demo available (runs in command-line only).  

---

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
