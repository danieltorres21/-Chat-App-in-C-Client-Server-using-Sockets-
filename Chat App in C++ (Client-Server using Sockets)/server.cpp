#include <iostream>
#include <winsock2.h>
#include <thread>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

void handleClient(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) break;
        buffer[bytesRead] = '\0';
        cout << "Client: " << buffer << endl;
    }
    closesocket(clientSocket);
    cout << "🔌 Client disconnected.\n";
}

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    int c;

    WSAStartup(MAKEWORD(2,2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));
    listen(serverSocket, 3);

    cout << "💬 Server is listening on port 8080...\n";

    c = sizeof(struct sockaddr_in);
    while ((clientSocket = accept(serverSocket, (struct sockaddr*)&client, &c)) != INVALID_SOCKET) {
        cout << "✅ Client connected.\n";
        thread t(handleClient, clientSocket);
        t.detach(); // Allow handling multiple clients
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

