#include <winsock2.h>
#include <windows.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")  // 链接 Winsock 库

int main()
{
    WSADATA wsaData;
    SOCKET sock;
    sockaddr_in server;

    // 初始化 Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // 创建套接字
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed\n";
        WSACleanup();
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);  // 连接到端口 80
    server.sin_addr.s_addr = inet_addr("216.58.217.46"); // Example IP (http://example.com)

    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cerr << "Connect failed\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // 发送 HTTP 请求
    const char *message = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    send(sock, message, strlen(message), 0);

    // 接收服务器响应
    char buffer[1024];
    int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        std::cout << "Response: " << buffer << std::endl;
    }

    // 关闭套接字并清理 Winsock
    closesocket(sock);
    WSACleanup();
    return 0;
}