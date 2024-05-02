import subprocess

# Function to read distance from C++ program via stdout
def read_distance():
    process = subprocess.Popen("./LIDARLite_RaspberryPi_Library/bin/llv3_flush_out.out", stdout=subprocess.PIPE, shell=True)
    while True:
        output = process.stdout.readline()
        if output == b'' and process.poll() is not None:
            break
        if output:
            # Process distance here, for now, let's just print it
            print("Distance:", output.strip().decode("utf-8"))  # Decode bytes to string and strip newline

# Call the function to start reading distance

while True:
    read_distance()
