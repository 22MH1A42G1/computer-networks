#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sendFrames(int start, int windowSize, int totalFrames) { 
    int i, ack, lostFrame = -1;
    srand(time(0)); // Seed for randomness

    while (start < totalFrames) { 
        printf("\nSending frames: ");
        for (i = start; i < start + windowSize && i < totalFrames; i++) { 
            printf("[Frame %d] ", i);
        }
        printf("\n");

        // Simulating frame loss randomly
        if (rand() % 5 == 0) { // 20% chance of loss 
            lostFrame = start + (rand() % windowSize); 
            if (lostFrame >= totalFrames) {
                lostFrame = totalFrames - 1;
            }
            printf("Frame %d lost!\n", lostFrame);
        }

        // Receiving Acknowledgments
        for (i = start; i < start + windowSize && i < totalFrames; i++) { 
            if (i == lostFrame) {
                printf("ACK %d not received. Retransmitting from Frame %d\n", i, i); 
                start = i; // Retransmit from lost frame
                break;
            } else {
                printf("ACK %d received.\n", i);
            }
        }

        // Move to next window if no loss
        if (i == start + windowSize || i >= totalFrames) { 
            start += windowSize;
        }
    }
    printf("\nAll frames sent successfully!\n");
}

int main() {
    int windowSize, totalFrames;
    printf("\n--- Go-Back-N ARQ Simulation ---\n"); 
    printf("Enter window size: ");
    scanf("%d", &windowSize); 
    printf("Enter total number of frames: "); 
    scanf("%d", &totalFrames);

    sendFrames(0, windowSize, totalFrames); 
    return 0;
}

