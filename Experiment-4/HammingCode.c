#include <stdio.h>

int main() {
    int data[7], dataatrec[7], c, c1, c2, c3, i;

    printf("Enter 4 bits of data one by one: \n");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);

    // Calculation of even parity bits
    data[6] = data[0] ^ data[2] ^ data[4]; // P4
    data[5] = data[0] ^ data[1] ^ data[4]; // P2
    data[3] = data[0] ^ data[1] ^ data[2]; // P1

    printf("\nEncoded data (7-bit Hamming Code) is: ");
    for (i = 0; i < 7; i++)
        printf("%d", data[i]);
    
    printf("\n\nEnter received 7-bit data one by one:\n");
    for (i = 0; i < 7; i++)
        scanf("%d", &dataatrec[i]);

    // Syndrome bits calculation
    c1 = dataatrec[6] ^ dataatrec[4] ^ dataatrec[2] ^ dataatrec[0];
    c2 = dataatrec[5] ^ dataatrec[4] ^ dataatrec[1] ^ dataatrec[0];
    c3 = dataatrec[3] ^ dataatrec[2] ^ dataatrec[1] ^ dataatrec[0];

    c = c3 * 4 + c2 * 2 + c1 * 1; // Calculating error position

    if (c == 0) {
        printf("\nNo error detected in received data.\n");
    } else {
        printf("\nError detected at position: %d\n", c);

        // Display original data and received data
        printf("\nData sent     : ");
        for (i = 0; i < 7; i++)
            printf("%d", data[i]);

        printf("\nData received : ");
        for (i = 0; i < 7; i++)
            printf("%d", dataatrec[i]);

        // Correct the erroneous bit
        printf("\nCorrected data is: ");
        dataatrec[7 - c] = dataatrec[7 - c] ^ 1; // Flip the bit

        for (i = 0; i < 7; i++)
            printf("%d", dataatrec[i]);

        printf("\n");
    }
    return 0;
}

