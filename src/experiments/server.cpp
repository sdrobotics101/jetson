#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512
#define PORT 8888

int main(int argc, char* argv[])
{
    struct sockaddr_in si_me;
    struct sockaddr_in si_other;
    int s;
    socklen_t slen = sizeof(si_other);
    int recv_len;
    char buf[BUFLEN];

    // Create a UDP socket
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        std::cerr << "UDP socket creation failed" << std::endl;
        exit(1);
    }

    // Zero out my socket address
    memset((char*) &si_me, 0, sizeof(si_me));

    // Set my socket address
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket to port
    if (bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) == -1) {
        std::cerr << "Binding to UDP socket failed" << std::endl;
        exit(1);
    }

    // Listen for data
    for (;;) {
        std::cout << "Waiting for data from client..." << std::endl;

        // Receive data
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&si_other, &slen)) == -1) {
            std::cerr << "Receiving data from UDP socket failed" << std::endl;
        }

        // Print received data
        std::cout << "Received packet from " << inet_ntoa(si_other.sin_addr) << ": " << ntohs(si_other.sin_port) << std::endl;
        std::cout << "Data: " << buf << std::endl;

        // Send data
        if (sendto(s, buf, recv_len, 0, (struct sockaddr*)&si_other, slen) == -1)
        {
            std::cout << "Sending data to UDP socket failed" << std::endl;
        }
    }

    close(s);

    return EXIT_SUCCESS;
}
