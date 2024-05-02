import socket
import struct

# Define the IP address and port to listen on
HOST = '127.0.0.1'  # Loopback address (localhost)
PORT = 8080         # Same port as used in the C++ program

# Create a UDP socket
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    # Bind the socket to the address and port
    s.bind((HOST, PORT))

    print(f"Listening on {HOST}:{PORT}")

    # Infinite loop to continuously receive data
    while True:
        # Receive data from the socket
        data, addr = s.recvfrom(1024)  # Buffer size is 1024 bytes

        # Unpack the received data as an unsigned short (2 bytes)
        distance = struct.unpack('H', data)[0]  # 'H' for unsigned short (16-bit)

        # Print the received distance
        print(f"Received distance from C++: {distance}")