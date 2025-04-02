#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <time.h>   // For random number generation

// Function to simulate sending a frame 
void send_packet(int frame) {
    printf("Sending frame %d...\n", frame);
}

// Function to simulate receiving an acknowledgment (random loss)
int receive_ack() {
    return rand() % 2; // 50% chance of success
}

int main() {
    srand(time(NULL)); // Seed for random number generation 
    int total_frames = 5; // Total number of frames to send
    int frame = 0;

    while (frame < total_frames) { 
        send_packet(frame);
        sleep(1); // Simulate transmission delay

        if (receive_ack()) { // If ACK is received
            printf("Acknowledgment received for frame %d.\n", frame);
            frame++; // Move to next frame
        } else { // If ACK is lost
            printf("Acknowledgment lost for frame %d. Retransmitting...\n", frame);
        }
    }

    printf("All frames sent successfully.\n"); 
    return 0;
}

