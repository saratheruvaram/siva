Sure, here's a simple example of text encryption using a Caesar cipher:

```
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char *text, int shift);

int main() {
    char text[MAX_LENGTH];
    int shift;

    printf("Enter text to encrypt: ");
    fgets(text, MAX_LENGTH, stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    encrypt(text, shift);

    printf("Encrypted text: %s", text);

    return 0;
}

void encrypt(char *text, int shift) {
    int i;

    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + ((text[i] - 'a' + shift) % 26);
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + ((text[i] - 'A' + shift) % 26);
        }
    }
}
```

This program prompts the user to enter a string to encrypt and a shift value, then uses a simple Caesar cipher to encrypt the text. The `encrypt` function takes a pointer to the text and the shift value as arguments, and modifies the text in place. The main function then prints the encrypted text. Note that this is a very basic encryption method and should not be used for secure communication.
