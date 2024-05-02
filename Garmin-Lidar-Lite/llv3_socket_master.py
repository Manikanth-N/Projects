import socket
import struct

# Define the IP address and port to listen on
HOST = '127.0.0.1'  # Use '0.0.0.0' to listen on all available interfaces
PORT = 8080

# Create a socket object
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Bind the socket to the address and port
    s.bind((HOST, PORT))
    
    # Listen for incoming connections
    s.listen()

    print(f"Listening on {HOST}:{PORT}")

    # Accept incoming connections
    conn, addr = s.accept()
    print(f"Connected by {addr}")

    with conn:
        while True:
            # Receive data from the client
            data = conn.recv(1024)
            if not data:
                break
            # Handle binary data received
            distance = struct.unpack('H', data)[0]  # Assuming distance is a 16-bit unsigned integer
            print("Lidar Distance:", distance)
