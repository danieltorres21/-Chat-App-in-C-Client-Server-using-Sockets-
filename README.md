# 💬 C++ Chat System using Sockets

This is a basic terminal-based chat system written in C++ that uses sockets for network communication and multithreading for concurrent message handling. It consists of a client and a server that can exchange messages in real-time over a local or LAN network.

## 📦 Features

- Client-server architecture
- Real-time bidirectional messaging
- Multithreaded message listening on both ends
- Terminal interface

## 🧠 Key Concepts

- C++ socket programming
- TCP communication
- WinSock (Windows) / BSD Sockets (Linux)
- Threads using `std::thread`
- Basic synchronization

## 🛠 Technologies Used

- C++
- WinSock2 (Windows) or BSD sockets (Linux)
- Multithreading (C++11)

---

## ▶️ How to Compile and Run

### 🪟 For Windows (using MinGW or g++)

Make sure you link the Winsock library:

```bash
g++ server.cpp -o server -lws2_32
g++ client.cpp -o client -lws2_32
