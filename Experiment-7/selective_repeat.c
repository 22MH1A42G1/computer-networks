#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

typedef struct { 
    int frame_no;
    int is_acknowledged;
} Frame;

void send_frames(Frame frames[], int start, int window_size) { 
    printf("\nSending frames: ");
    int i;
	for (i = start; i < start + window_size && i < TOTAL_FRAMES; i++) { 
        printf("%d ", frames[i].frame_no);
    }
    printf("\n");
}

void receive_ack(Frame frames[], int start, int window_size) {
    int i;
	for (i = start; i < start + window_size && i < TOTAL_FRAMES; i++) { 
        if (rand() % 5 != 0) { // 80% success rate
            frames[i].is_acknowledged = 1;
            printf("Acknowledgment received for frame %d\n", frames[i].frame_no);
        } else {
            printf("Frame %d lost, needs retransmission\n", frames[i].frame_no);
        }
    }
}

int main() {
    Frame frames[TOTAL_FRAMES]; 
    srand(time(0));

    // Initialize frames
    int i;
	for (i = 0; i < TOTAL_FRAMES; i++) { 
        frames[i].frame_no = i; 
        frames[i].is_acknowledged = 0;
    }

    int base = 0;
    while (base < TOTAL_FRAMES) { 
        send_frames(frames, base, WINDOW_SIZE); 
        receive_ack(frames, base, WINDOW_SIZE);

        // Retransmit lost frames
        int i;
		for (i = base; i < base + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            while (!frames[i].is_acknowledged) {
                printf("\nRetransmitting frame %d...\n", frames[i].frame_no);
                if (rand() % 5 != 0) { // Simulate retransmission success
                    frames[i].is_acknowledged = 1;
                    printf("Acknowledgment received for frame %d\n", frames[i].frame_no);
                }
            }
        }

        // Move base to the next unacknowledged frame
        while (base < TOTAL_FRAMES && frames[base].is_acknowledged) { 
            base++;
        }
    }

    printf("\nAll frames successfully transmitted!\n"); 
    return 0;
}

