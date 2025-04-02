#include <stdio.h>
#include <string.h>

// Length of the generator polynomial
#define N strlen(gen_poly)

// Data to be transmitted and received
char data[28];

// CRC value
char check_value[28];

// Generator polynomial
char gen_poly[10];

// Variables
int data_length, i, j;

// Function that performs XOR operation
void XOR() {
    for (j = 0; j < N; j++)
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
}

// Function to perform CRC division
void crc() {
    // Initializing check_value with the first N bits of data
    for (i = 0; i < N; i++)
        check_value[i] = data[i];

    // Loop through the entire data
    do {
        // If the first bit is 1, perform XOR
        if (check_value[0] == '1')
            XOR();

        // Shift left and bring the next bit from data
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];

        // Append the next data bit
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);

    // Null-terminate check_value for printing
    check_value[N - 1] = '\0';
}

// Function to check for errors on the receiver side
void receiver() {
    // Get the received data
    printf("\nEnter the received data: ");
    scanf("%s", data);

    printf("\nData received: %s", data);

    // Perform CRC check
    crc();

    // Check if remainder is zero
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++);

    if (i < N - 1)
        printf("\nError detected\n");
    else
        printf("\nNo error detected\n");
}

// Main function
int main() {
    // Get the data to be transmitted
    printf("Enter data to be transmitted: ");
    scanf("%s", data);

    // Get the generator polynomial
    printf("Enter the Generating polynomial: ");
    scanf("%s", gen_poly);

    // Find the length of the data
    data_length = strlen(data);

    // Append N-1 zeros to the data
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    data[i] = '\0';  // Null-terminate the string

    // Print padded data
    printf("\nData padded with n-1 zeros: %s", data);

    // Compute CRC
    crc();

    // Print CRC value
    printf("\nCRC or Check value: %s", check_value);

    // Append check_value (CRC) to data
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];
    data[i] = '\0';  // Null-terminate the string

    // Print final transmitted data
    printf("\nFinal data to be sent: %s\n", data);

    // Call receiver function to check for errors
    receiver();

    return 0;
}

