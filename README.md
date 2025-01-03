# Simple Shell Project

This project is a basic implementation of a Unix-like shell, designed as part of the Holberton School curriculum. It provides a simplified command-line interface, allowing users to execute commands, manage processes, and interact with the operating system.

## Features

*   **Command execution:** Executes basic commands like `ls`, `pwd`, `cat`, etc.
*   **Path searching:** Uses the `PATH` environment variable to locate executable files.
*   **Built-in commands:** Includes a few basic built-in commands, such as `exit` and `env`.
*   **Handles spaces:** Correctly parses commands with spaces as separate arguments.
*   **Interactive and non-interactive modes:** Supports both interactive use and execution from script files.
*   **Basic signal handling:** Handles basic signals like Ctrl+C.

## Usage

1.  Clone the repository:
    ```bash
    git clone https://github.com/your_username/holbertonschool-simple_shell.git
    cd holbertonschool-simple_shell
    ```
2.  Compile the shell:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
    ```
3.  Run the shell:
    ```bash
    ./hsh
    ```

## Built-in Commands

*   `exit`: Exits the shell.
*   `env`: Prints the current environment variables.

## Authors

See the `AUTHORS` file for a list of contributors.

## License

This project is released under the [MIT License](LICENSE).

## Contributing

Contributions are welcome! Feel free to submit pull requests.

