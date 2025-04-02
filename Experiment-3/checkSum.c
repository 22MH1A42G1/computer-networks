#include <stdio.h> 
#include <math.h>

// Function to compute checksum at the sender side
int sender(int arr[], int n) {
    int checksum, sum = 0, i; 
    printf("\n**** SENDER SIDE ****\n"); 

    // Compute sum of all array elements
    for(i = 0; i < n; i++) 
        sum += arr[i];

    printf("SUM IS: %d", sum); 

    checksum = ~sum; // 1's complement of sum
    printf("\nCHECKSUM IS: %d", checksum); 

    return checksum;
}

// Function to verify checksum at the receiver side
void receiver(int arr[], int n, int sch) {
    int checksum, sum = 0, i; 
    printf("\n\n**** RECEIVER SIDE ****\n"); 

    // Compute sum of all array elements
    for(i = 0; i < n; i++) 
        sum += arr[i];

    printf("SUM IS: %d", sum); 

    sum = sum + sch;  // Adding sender checksum
    checksum = ~sum;  // 1's complement of sum 

    printf("\nCHECKSUM IS: %d", checksum);

    // Check if checksum is 0 (indicating no error)
    if (checksum == 0)
        printf("\nNO ERROR DETECTED. DATA RECEIVED CORRECTLY.\n");
    else
        printf("\nERROR DETECTED IN TRANSMISSION!\n");
}

int main() {
    int n, sch;

    // Input size of the array
    printf("\nENTER SIZE OF THE STRING: ");
    scanf("%d", &n); 

    int arr[n],i;

    // Input elements for checksum calculation
    printf("ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Compute sender checksum
    sch = sender(arr, n); 

    // Call receiver function to verify checksum
    receiver(arr, n, sch);

    return 0;
}

