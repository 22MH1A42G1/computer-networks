#include <stdio.h>
#include <string.h>

void main() {
    char a[30], fs[50] = "", t[3], sd, ed, x[3], s[3], d[3], y[3]; 
    int i;

    // Input data
    printf("Enter characters to be stuffed: "); 
    scanf("%s", a);

    printf("\nEnter a character that represents starting delimiter: "); 
    scanf(" %c", &sd);

    printf("\nEnter a character that represents ending delimiter: "); 
    scanf(" %c", &ed);

    // Initialize delimiters
    x[0] = s[0] = s[1] = sd;
    x[1] = s[2] = '\0';

    y[0] = d[0] = d[1] = ed;
    d[2] = y[1] = '\0';

    // Start stuffing with the starting delimiter
    strcat(fs, x);

    for (i = 0; i < strlen(a); i++) {
        t[0] = a[i];
        t[1] = '\0';

        if (t[0] == sd)
            strcat(fs, s);  // Escape start delimiter
        else if (t[0] == ed)
            strcat(fs, d);  // Escape end delimiter
        else
            strcat(fs, t);  // Append normal characters
    }

    // Append ending delimiter
    strcat(fs, y);

    printf("\nAfter stuffing: %s", fs);
}

