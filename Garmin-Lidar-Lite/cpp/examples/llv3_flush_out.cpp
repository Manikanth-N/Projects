#include <linux/types.h> // Required for __u16 and __u8 types
#include <cstdio> // Required for printf and fflush

#include <include/lidarlite_v3.h> // Include the header file for LIDAR-Lite v3

LIDARLite_v3 myLidarLite; // Declare an instance of the LIDARLite_v3 class

int main()
{
    __u16 distance; // Variable to store distance data (unsigned 16-bit integer)
    __u8 busyFlag; // Variable to store busy flag (unsigned 8-bit integer)

    // Initialize I2C peripheral in the CPU core
    myLidarLite.i2c_init();

    // Optionally configure LIDAR-Lite
    myLidarLite.configure(0);

    while(1)
    {
        // Each time through the loop, check BUSY flag to see if the sensor is ready
        busyFlag = myLidarLite.getBusyFlag();

        if (busyFlag == 0x00) // If the sensor is not busy
        {
            // When no longer busy, immediately initialize another measurement
            // and then read the distance data from the last measurement.
            // This method will result in faster I2C repetition rates.
            myLidarLite.takeRange(); // Initiate a distance measurement
            distance = myLidarLite.readDistance(); // Read the distance measurement

            // Print distance to stdout
            printf("%d\n", distance);
            fflush(stdout); // Ensure the output is flushed immediately to avoid buffering delays
        }
    }

    return 0; // Indicate successful program termination
}
