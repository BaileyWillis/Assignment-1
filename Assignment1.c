/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please select one of the following options: \n");
    printf("(A) Encryption of a message with a rotation cipher given the message text and rotation amount \n");
    printf("(B) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount \n");
    printf("(C) Encryption of a message with a substitution cipher given message text and alphabet substitution \n");
    printf("(D) Decryption of a message encrypted with a substitution cipher given cipher text and substitutions \n");
    printf("(E) Decryption of a message encrypted with a rotation cipher given cipher text only \n");
    printf("(F) Decryption of a message encrypted with a substitution cipher given cipher text only \n");
    
    char c;
    scanf("%c", &c);
    
    return EXIT_SUCCESS;
}
