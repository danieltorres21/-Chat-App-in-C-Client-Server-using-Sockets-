#include <iostream>
#include <winsock2.h>
#include <thread>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void receive(SOCKET sock) {
    char buffer[1024];
    while (true) {
        int len = recv(sock, buffer, sizeof(buffer), 0);
        if (len <= 0) break;
        buffer[len] = '\0';
        cout << "\nServer: " << buffer << endl;
    }
}

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2,2), &wsa);
    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(s, (struct sockaddr *)&server, sizeof(server));
    cout << "✅ Connected to server.\n";

    thread t(receive, s);

    string msg;
    while (true) {
        cout << "You: ";
        getline(cin, msg);
        send(s, msg.c_str(), msg.length(), 0);
    }

    t.join();
    closesocket(s);
    WSACleanup();
    return 0;
}
