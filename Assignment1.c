/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cipher_method;
 
    printf("Please select one of the following options: \n");
    printf("(A) Encryption of a message with a rotation cipher given the message text and rotation amount \n");
    printf("(B) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount \n");
    printf("(C) Encryption of a message with a substitution cipher given message text and alphabet substitution \n");
    printf("(D) Decryption of a message encrypted with a substitution cipher given cipher text and substitutions \n");
    printf("(E) Decryption of a message encrypted with a rotation cipher given cipher text only \n");
    printf("(F) Decryption of a message encrypted with a substitution cipher given cipher text only \n");
    
    scanf("%c", &cipher_method);
    
    
    switch(cipher_method)
    {
        case 'A':
        {
	char encryption[100];
	char character;
	int i;
	int key;
	
	printf("Enter a message to encrypt: "); //user input for their sentence to be encrypted
	gets(encryption); //This function reads the text entered by the user and stores it into the string pointed to by str
	printf("Enter key: "); //A Key is how many places the encryption rotates the characters eg. key of 3 will turn 'A' into 'D'
	scanf("%d", &key); //scanning the key entered by the user for the code to execute 
	
	for(i = 0; encryption[i] != '\0'; ++i){
		character = encryption[i];
		
		if(character >= 'a' && character <= 'z'){
			character = character + key;
			
			if(character > 'z'){
				character = character - 'z' + 'a' - 1;
			}
			
			encryption[i] = character;
		}
		else if(character >= 'A' && character <= 'Z'){
			character = character + key;
			
			if(character > 'Z'){
				character = character - 'Z' + 'A' - 1;
			}
			
			encryption[i] = character;
		}
	}
	
	printf("The encrypted message with key %d is: %s", key, encryption);
	
	return 0;
}
          break;
        
        case 'B':
          break;
        
        case 'C':
          break;
        
        case 'D':
          break;
        
        case 'E':
          break;
        
        case 'F':
          break;
        
        default:
        printf("Invalid Input\n");
          break;
    }
      

    
    return 0;
}
