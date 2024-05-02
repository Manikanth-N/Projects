#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <linux/types.h>
#include <cstdio>

#include <include/lidarlite_v3.h>

// Constants
#define PORT 8080
#define DELAY_MS 1000 // Delay between sending messages in milliseconds

// Function to send Lidar distance data over UDP
void sendData(int sockfd, const sockaddr_in& servaddr, LIDARLite_v3& lidar) {
    // Variables for Lidar distance measurement
    __u16 distance;
    __u8 busyFlag;

    // Check BUSY flag
    busyFlag = lidar.getBusyFlag();

    if (busyFlag == 0x00) {
        // When not busy, take range measurement and read distance data
        lidar.takeRange();
        distance = lidar.readDistance();
    }

    // Send distance data to Python script
    int n = sendto(sockfd, &distance, sizeof(distance),
                   MSG_CONFIRM, (const struct sockaddr *)&servaddr,
                   sizeof(servaddr));
    if (n < 0) {
        std::cerr << "Failed to send data" << std::endl;
    } else {
        std::cout << "Distance sent: " << distance << std::endl;
    }
}

int main() {
    // Socket variables
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Initialize server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Lidar object initialization
    LIDARLite_v3 myLidarLite;

    // Initialize i2c peripheral in the cpu core
    myLidarLite.i2c_init();

    // Optionally configure LIDAR-Lite
    myLidarLite.configure(0);

    // Main loop
    while (true) {
        // Send Lidar distance data
        sendData(sockfd, servaddr, myLidarLite);

        // Delay before sending the next message
        usleep(DELAY_MS * 1000); // usleep takes microseconds
    }

    // Close socket
    close(sockfd);

    return 0;
}
