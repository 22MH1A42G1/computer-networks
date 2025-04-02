#include <stdio.h>

int main() {
    int a[20], b[30], i, j, k, count, n;

    // Taking input for frame length
    printf("Enter frame length: ");
    scanf("%d", &n);

    // Taking input for frame (only 0s and 1s)
    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    i = 0;
    count = 1;
    j = 0;

    // Bit Stuffing logic
    while (i < n) {
        if (a[i] == 1) {
            b[j] = a[i];
            for (k = i + 1; a[k] == 1 && k < n && count < 5; k++) {
                j++;
                b[j] = a[k];
                count++;
                if (count == 5) {
                    j++;
                    b[j] = 0; // Stuffing a '0' after 5 consecutive '1's
                }
                i = k;
            }
        } else {
            b[j] = a[i];
            count = 0; // Reset count if 0 is found
        }
        i++;
        j++;
    }

    // Displaying the stuffed frame
    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++)
        printf("%d", b[i]);

    return 0;
}

