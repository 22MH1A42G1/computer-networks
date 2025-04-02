#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> // for sleep() function

#define BUCKET_SIZE 10  // Maximum capacity of the bucket 
#define OUTPUT_RATE 3    // Rate at which data is sent out

// Function to process packets using Leaky Bucket Algorithm
int leakyBucket(int packetSize) { 
    static int bucketContent = 0;

    if (packetSize > BUCKET_SIZE) {
        printf("Packet size (%d) too large to fit in the bucket. Packet discarded.\n", packetSize);
    } else {
        if (bucketContent + packetSize > BUCKET_SIZE) {
            printf("Bucket overflow! Packet of size %d discarded.\n", packetSize);
        } else {
            bucketContent += packetSize;
            printf("Packet of size %d added to the bucket. Current bucket content: %d\n", packetSize, bucketContent);
        }
    }

    // Simulate output of data at the specified rate 
    if (bucketContent > 0) {
        int sent = (bucketContent < OUTPUT_RATE) ? bucketContent : OUTPUT_RATE; 
        bucketContent -= sent;
        printf("Sent %d units of data. Remaining bucket content: %d\n", sent, bucketContent);
    } else {
        printf("Bucket is empty. No data sent.\n");
    }

    return bucketContent;  // Return remaining content for checking in main()
}

int main() {
    int n, packetSize, i;

    printf("Enter the number of incoming packets: "); 
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter size of packet %d: ", i + 1); 
        scanf("%d", &packetSize); 
        leakyBucket(packetSize);
        sleep(1); // Simulate time delay between packet arrivals
    }

    // Drain the remaining content from the bucket
    while (leakyBucket(0) > 0) {  // Corrected condition
        sleep(1);
    }

    return 0;
}

