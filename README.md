![Get_next_line Banner](https://raw.githubusercontent.com/oakoudad/badge42/main/subjects/get_next_line.png)

# 📖 Get_next_line

`get_next_line` is a foundational C project from the 42 curriculum that teaches how to read from a file descriptor one line at a time, managing buffer sizes, dynamic memory, and static variables.

## 📚 Table of Contents
- [Overview](#-overview)  
- [Features](#-features)  
- [Installation](#-installation)  
- [Usage](#-usage)  
- [File Structure](#-file-structure)  
- [Subject Breakdown](#-subject-breakdown)  
- [License](#-license)  
- [Subject PDF](#-subject-pdf)  

## 📖 Overview

The goal of this project is to implement the function `get_next_line` which reads from a file descriptor and returns the next line, including the newline character if present, on each call until EOF.

This function is essential for understanding file I/O in C, memory management, and handling buffers efficiently.

## ✨ Features

### ✅ Mandatory Features:
- Read from any file descriptor  
- Return one line at a time, including the newline character if it exists  
- Manage static variables to keep leftover data between function calls  
- Handle multiple file descriptors simultaneously  
- Use only allowed functions (`read`, `malloc`, `free`)  
- Use a buffer size defined by `BUFFER_SIZE` macro  

## ⚙️ Installation

```bash
git clone https://github.com/adil-ech/get_next_line
cd get_next_line
make
```

This will generate the `libftgnl.a` static library.

## 🚀 Usage

In your C file:

```c
#include "get_next_line.h"
```

Compile with:

```bash
cc *.c or *bonus_.c
```

Make sure `get_next_line.h` are in your project directory.

## 📁 File Structure

```
get_next_line/
├── get_next_line.c        # Main function implementation
├── get_next_line_utils.c  # Helper functions
├── get_next_line.h        # Header file
├── Makefile
```

## 📄 Subject Breakdown

### ✅ Part 1 — Basic Functionality
- Implement `get_next_line` with buffer reading  
- Return a line read from the file descriptor including the newline  
- Handle end of file and errors gracefully  

### 🎉 Bonus Part — Multiple File Descriptors Support

- Handle multiple file descriptors simultaneously, ensuring that each descriptor’s buffer and leftover data are managed independently.
- Maintain static variables or structures to keep track of leftover data for each open file descriptor.
- Ensure no interference occurs between file descriptors when reading lines.
- Properly free memory when a file descriptor is closed or no longer needed.
- Maintain robust error handling and edge case management across multiple streams. 

## 📬 License

This project is part of the 42 Network curriculum and is for educational use only.

## 📄 Subject PDF

You can read the official 42 Get_next_line subject here:  
👉 [Get_next_line Subject PDF](./en.subject.pdf)
