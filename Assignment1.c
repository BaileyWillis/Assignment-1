#include <stdio.h>
#include <stdlib.h>


int rotencrypt();
int rotdecrypt();

int main()
{
//I think it is working
   // FILE * fp; 
   // FILE * nfp; 
    
    //fp = fopen("in.txt", "r"); 
    
   // nfp = fopen("out.txt", "w"); 
    
    //char l[100]; 
    
    //fscanf(fp, "%s", l); 
    
   // printf("\n%s\n", l); 
    
     //   printf("\n%s\n", l); 
    
      //  printf("\n%s\n", l); 
    
    
    
    
    
    char cipher_method;
 
    printf("Please select one of the following options: \n");
    printf("(A) Encryption of a message with a rotation cipher given the message text and rotation amount \n");
    printf("(B) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount \n");
    printf("(C) Encryption of a message with a substitution cipher given message text and alphabet substitution \n");
    printf("(D) Decryption of a message encrypted with a substitution cipher given cipher text and substitutions \n");
    printf("(E) Decryption of a message encrypted with a rotation cipher given cipher text only \n");
    printf("(F) Decryption of a message encrypted with a substitution cipher given cipher text only \n\n");
    
    scanf("%c", &cipher_method);                         //scans the option that the user would like to run
    
    
    
    
    switch(cipher_method)                                //whatever option was chosen from the main menu, it will perform the appropriate case
    {
        case 'A':                                        //run option "A" from the main menu
        rotencrypt();
          break;
        
        case 'B':
        rotdecrypt();
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



int rotencrypt()

{
    	   char encryption[100];
    	   char character;
    	   int i;
    	   int ci_rot;
    	
      	   printf("Please enter a message to encrypt: \n"); //user input for their sentence to be encrypted
      	   scanf(" %[^\n]s",encryption);                          //scanning the message entered by the user and placing it in the string 'encryption'
    	   printf("Please enter the cipher key: ");         //A Key is how many places the encryption rotates the characters eg. key of 3 will turn 'A' into 'D'
           scanf(" %d", &ci_rot);                            //scanning the key entered by the user for the code to execute 
    	
	       for(i = 0; encryption[i] != '\0'; i++)           //A for loop that: starts by asigning the string 'encryption' to zero,                
	           {                                            //string 'encryption' is not equal to NULL and the string is incriminated by 1  
    		    character = encryption[i];                   //Asigns 'encryption' string to 'character'
		
    		    if(character >= 'a' && character <= 'z')     //If statement with conditions (if character is greater than or equal to "a") AND (if character is less than or equal to "z")
		        {
    			 character = character + ci_rot;             //Asigns the character entered to the new character by rotating it by the number of time depending on the key (eg. "A" with a key of 4 is now "D")
    		                                             
    			 if(character > 'z')                         //If the character is then larger than 'z' do the following
    			     {
    				  character = character + ci_rot - 27; //The previous character value of 'z' is added to the ascii value of 'a' and 1 is subtracted 
    			     }
    			
    			encryption[i] = character;                   //The char character is assigned to the string 'encryption'
		        }
		        else if(character >= 'A' && character <= 'Z')
	        	{
		        	character = character + ci_rot;
			
		        	if(character > 'Z')
		        	{
			        	character = character + ci_rot - 27;
		        	}
			
		        	encryption[i] = character;
		         }
               }  
               
	       printf("The encrypted message with key %d is: %s", ci_rot, encryption);
	       

        return 0;
    }

   
   int rotdecrypt()
   
    {
        char decryption[100]; 
        char character;
	    int i;
	    int ci_rot;
	
	    printf("Please enter a message to decrypt: ");
	    scanf("%s",decryption); 
	    printf("Please enter the cipher key: ");
	    scanf("%d", &ci_rot);
	
	    for(i = 0; decryption[i] != '\0'; i++)
	       {
		    character = decryption[i];
		
		    if(character >= 'a' && character <= 'z')
		    {
			 character = character - ci_rot;
			
			 if(character < 'a')
    		  {
				character = character - ci_rot + 27;
			  }
			
			 decryption[i] = character;
		     }
		      else if(character >= 'A' && character <= 'Z')
		      {
			     character = character - ci_rot;
			
			     if(character < 'A')
			     {
				    character = character - ci_ot + 27;
			     }
			
			     decryption[i] = character;
		      }
	        }      
        printf("The decrypted message with key %d is: %s", ci_rot, decryption);
        
        
        return 0;
     }