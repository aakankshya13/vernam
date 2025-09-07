#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt using Vernam Cipher
void vernamEncrypt(char *plaintext, char *key, char *ciphertext)
{
    int i;
    int len = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0; i < len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i % keyLen]; // repeat key if shorter
    }
    ciphertext[i] = '\0';
}

// Decrypt using Vernam Cipher
void vernamDecrypt(char *ciphertext, char *key, char *decrypted)
{
    int i;
    int len = strlen(ciphertext);
    int keyLen = strlen(key);

    for (i = 0; i < len; i++)
    {
        decrypted[i] = ciphertext[i] ^ key[i % keyLen]; // repeat key if shorter
    }
    decrypted[i] = '\0';
}

int main()
{
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    char decrypted[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline

    vernamEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%02X ", (unsigned char)ciphertext[i]); // Print as hex
    }
    printf("\n");

    vernamDecrypt(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
