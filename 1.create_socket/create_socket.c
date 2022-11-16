//create_socket.c: successfully create a socket
#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
    #include <winsock.h>
    #pragma comment (lib,"wsock32.lib")
    #pragma warning(disable:4996)
#elif __linux__
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h> //contains many function prototypes of system services: read(), write(), getpid(), close(), etc.
#endif

#define MY_IP "127.0.0.1"
#define MY_IP_IN_HOST_BYTE_ORDER ((in_addr_t)0x7f000001)  // 127.0.0.1
#define MY_PORT 0x0110 // MY_PORT = 272

void printf_error();

int main()
{
    int retval, len;
    int s;

    struct sockaddr_in my_addr;

    #ifdef _WIN32
        WSAData wsa;
        WSAStartup(0x101, &wsa);
    #endif
    
    //1. create socket
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        printf_error();
        goto exit;
    }
    fprintf(stdout, "create socket successfully! Socket id: %d\n", s);
    
    //2. bind socket to a socket address
    //2.1 configure the socket address
    my_addr.sin_family = AF_INET; // 使用IPv4来表示IP
    #ifdef _WIN32
        //my_addr.sin_addr.S_un.S_addr = htonl(MY_IP_IN_HOST_BYTE_ORDER);
        my_addr.sin_addr.S_un.S_addr = inet_addr(MY_IP);
    #elif __linux__
        // my_addr.sin_addr.s_addr = htonl(MY_IP_IN_HOST_BYTE_ORDER); // 与下一行完全等价
        my_addr.sin_addr.s_addr = inet_addr(MY_IP); 
        /* inet_addr()的作用是将 MY_IP 由 string类型 转换为 network byte order (unsigned long)类型。*/
    #endif
    my_addr.sin_port = htons(MY_PORT); 
    /* htons()的作用是将 MY_PORT 由 host byte order (unsigned short)类型 转换为 network byte order (unsigned short)类型。*/
    
    //2.2 bind
    len = sizeof(my_addr);
    retval = bind(s, (struct sockaddr*)&my_addr, len);
    if (s < 0) {
        printf_error();
        goto exit;
    }
    fprintf(stdout, "Successfully bind socket to address:\n    IP: %s\n    Port: %d\n", 
                                inet_ntoa(my_addr.sin_addr) ,ntohs(my_addr.sin_port));

    //3. close socket
    exit:{
        #ifdef _WIN32
            if(s > 0){
                closesocket(s);
            }
            WSACleanup();
        #elif __linux__
            if(s > 0){
                close(s);
            }
        #endif
    }
}

void printf_error()
{
    #ifdef _WIN32
        int retval = WSAGetLastError();
        fprintf(stderr, "socket error: %d\n", retval);
    #elif __linux__
        fprintf(stderr, "socket error: %s(errno: %d)\n",strerror(errno),errno);
    #endif
}
