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
    printf("(F) Decryption of a message encrypted with a substitution cipher given cipher text only \n\n");
    
    scanf("%c", &cipher_method);                     //scans the option that the user would like to run
    
    
    
    
    switch(cipher_method)                            //whatever option was chosen from the main menu, it will perform the appropriate case
    {
        case 'A':                                    //run option "A" from the main menu
        {
	char encryption[100];
	char character;
	int i;
	int key;
	
  	printf("Enter a message to encrypt: \n");        //user input for their sentence to be encrypted
	scanf("%s",encryption);                          //scanning the message entered by the user and placing it in the string 'encryption'
	printf("Enter key: ");                           //A Key is how many places the encryption rotates the characters eg. key of 3 will turn 'A' into 'D'
 	scanf("%d", &key);                               //scanning the key entered by the user for the code to execute 
	
	for(i = 0; encryption[i] != '\0'; ++i)           //A for loop that: starts by asigning the string 'encryption' to zero,                
	{                                                //string 'encryption' is not equal to NULL and the string is incriminated by 1  
		character = encryption[i];                   //Asigns 'encryption' string to 'character'
		
		if(character >= 'a' && character <= 'z')     //If statement with conditions (if character is greater than or equal to "a") AND (if character is less than or equal to "z")
		{
			character = character + key;             //Asigns the character entered to the new character by rotating it by the number of time depending on the key (eg. "A" with a key of 4 is now "D")
		                                             
			if(character > 'z')                      //
			{
				character = character - 'z' + 'a' - 1;
			}
			
			encryption[i] = character;
		}
		else if(character >= 'A' && character <= 'Z')
		{
			character = character + key;
			
			if(character > 'Z')
			{
				character = character - 'Z' + 'A' - 1;
			}
			
			encryption[i] = character;
		}
	}
	
	printf("The encrypted message with key %d is: %s", key, encryption);
	
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
        //printf("Invalid Input\n");
          break;
    
      
}
    
    return 0;
}