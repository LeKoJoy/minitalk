# 📡 minitalk

> A minimalist client-server messaging app built in C — using only UNIX signals.  
> **No `libft`, just raw signal power.**

---

## 🚀 Overview

`minitalk` is a small communication project where a **client** sends a string message to a **server**, one bit at a time, using `SIGUSR1` and `SIGUSR2`. The server then reconstructs and prints the message.

It’s a deep dive into:

- UNIX signals  
- Bitwise operations  
- Inter-process communication  
- Handling async behavior in C  
- Writing clean, self-contained C code (yep — **no libft!**)

---

## 📁 Project Structure

```
minitalk/
├── client.c             # Sends messages to the server
├── server.c             # Receives and reconstructs messages
├── utils.c              # Helper functions (libft-style, written from scratch)
├── utils.h
├── Makefile
└── README.md
```

---

## 🧰 No libft used!

All helper functions (`ft_atoi`, `ft_strlen`, `ft_putstr_fd`, etc.) were implemented manually in `utils.c`.  
The entire project is **fully self-contained** and dependency-free.

---

## 🧪 How to Use

1. **Build the project**

```bash
make
```

2. **Start the server**

```bash
./server
```

This will print the server’s **PID**. You’ll need it for the client.

3. **Send a message with the client**

```bash
./client <server_pid> "Hello from the client!"
```

The server will receive and print your message.

---

## 🧠 How it Works

- The **client** encodes each character bit-by-bit.
  - Sends `SIGUSR1` for bit `0`
  - Sends `SIGUSR2` for bit `1`
- The **server** receives the signals, rebuilds the bits into characters, and prints the message.
- It’s kind of like Morse code, but nerdier.

---

## 📌 Notes

- Error handling is included for invalid PIDs and failed signals.
- Signals are sent synchronously with `usleep` delays to avoid overflow.
- The server can handle multiple messages but one client at a time (basic implementation).

---

## 🤘 Author

Crafted from scratch, bit by bit, by [Your Name].  
No `libft`. Just raw C and signals.

---

![alt text](image-1.png)