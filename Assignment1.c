#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int rot_encrypt ();          //function name for case 'A' that encrypts the users text using a rotation of their choice of key
int rot_decrypt ();          //function name for case 'B' that decrypts the users text using a rotation of their choice of key
int sub_encrypt ();          //function name for case 'C' that encrypts the users text using a substitution key
int sub_decrypt ();          //function name for case 'D' that decrypts the users text using a substitution key

 
int main () 
{
  
 /*
 The below 'printf' statements is printed to the user interface as a main menu. This main menu enables the user
 to choose whatever operation they would like to exicute. By selecting either (A), (B), (C), (D), (E) or (F) the 
 following switch case's will exicute the correct function. These functions, identified outside the main, are wihin 
 their corrosponding 'case' and when that case is called by the user, the function name within that case calls that 
 function to operate. These functions are outside the main below. Once the function has finished exicuting it will then 
 jump back to the case where it is told to 'break', ending the case and subsequently ending the program.
 */

char cipher_method;
  
 
printf ("Please select one of the following options: \n");
printf ("(A) Encryption of a message with a rotation cipher given the message text and rotation amount \n"); 
printf ("(B) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount \n");
printf ("(C) Encryption of a message with a substitution cipher given message text and alphabet substitution \n");
printf ("(D) Decryption of a message encrypted with a substitution cipher given cipher text and substitutions \n"); 
printf ("(E) Decryption of a message encrypted with a rotation cipher given cipher text only \n");
printf ("(F) Decryption of a message encrypted with a substitution cipher given cipher text only \n\n");

scanf ("%c", &cipher_method);	 //Scans the option that the user would like to run and stores it in the char 'cipher_method'
  
 
 
 
switch (cipher_method)	        //Calls the option that was chosen from the main menu and sends it to that case. The case will then exicute the code inside.
    {
    
case 'A':			
rot_encrypt ();                 //Case 'A' calls for function 'rot_encrypt' to be exicuted. The program now jumps down to the function 'rot_encrypt' to perform the code contained inside
break;
    
 
case 'B':
rot_decrypt ();                 //Case 'B' calls for function 'rot_decrypt' to be exicuted. The program now jumps down to the function 'rot_decrypt' to perform the code contained inside
break;                          
    
 
case 'C':
sub_encrypt ();                 //Case 'C' calls for function 'sub_encrypt' to be exicuted. The program now jumps down to the function 'sub_encrypt' to perform the code contained inside
break;
    
 
case 'D':
sub_decrypt ();                 //Case 'D' calls for function 'sub_decrypt' to be exicuted. The program now jumps down to the function 'sub_decrypt' to perform the code contained inside
break;
    
 
case 'E':
break;
    
 
case 'F':
break;
    
 
default:                        // If neither (A), (B), (C), (D), (E) or (F) are chosen by the user then the switch statement will automatically exicute the default case, asking the user to imput a valid case
printf ("Invalid Input\n");
break;
    
}
  
 
return 0;

}


 
 
 
int rot_encrypt () 
 
{
  
char encryption[100];
char character;
int i;
int ci_rot;
  
 
printf ("Please enter a message to encrypt: \n");	//user input for their sentence to be encrypted
scanf (" %[^\n]s", encryption);	                    //scanning the message entered by the user and placing it in the string 'encryption'
printf ("Please enter the cipher key: ");        	//A Key is how many places the encryption rotates the characters eg. key of 3 will turn 'A' into 'D'
scanf (" %d", &ci_rot);	                            //scanning the key entered by the user for the code to execute 
  
for (i = 0; encryption[i] != '\0'; i++)	            //A for loop that: starts by asigning the string 'encryption' to zero,                
    {				                                //string 'encryption' is not equal to NULL and the string is incriminated by 1  
      character = encryption[i];	                //Asigns 'encryption' string to 'character'
      
if (character >= 'a' && character <= 'z')	        //If statement with conditions (if character is greater than or equal to "a") AND (if character is less than or equal to "z")
	{
	  
character = character + ci_rot;	                    //Asigns the character entered to the new character by rotating it by the number of time depending on the key (eg. "A" with a key of 4 is now "D")
	  
if (character > 'z')	                            //If the character is then larger than 'z' do the following
	    {
	      
character = character - 'z' + 'a' - 1;	           //The previous character value of 'z' is added to the ascii value of 'a' and 1 is subtracted 
	    }
	  
 
encryption[i] = character;	                      //The char character is assigned to the string 'encryption'
	}
      
      else if (character >= 'A' && character <= 'Z')
	
	{
	  
character = character + ci_rot;
	  
 
if (character > 'Z')
	    
	    {
	      
character = character - 'Z' + 'A' - 1;
	    
}
	  
 
encryption[i] = character;
	
}
    
}
  
 
printf ("The encrypted message with key %d is: %s", ci_rot, encryption);
  
 
 
return 0;

}


 
 
int rot_decrypt () 
 
{
  
char decryption[100];
char character;
int i;
int ci_rot;
  
 
printf ("Please enter a message to decrypt: ");
scanf ("%s", decryption);
printf ("Please enter the cipher key: ");
scanf ("%d", &ci_rot);
  
 
for (i = 0; decryption[i] != '\0'; i++)
    
    {
      
character = decryption[i];
      
 
if (character >= 'a' && character <= 'z')
	
	{
	  
character = character - ci_rot;
	  
 
if (character < 'a')
	    
	    {
	      
character = character + 'z' - 'a' + 1;
	    
}
	  
 
decryption[i] = character;
	
}
      
      else if (character >= 'A' && character <= 'Z')
	
	{
	  
character = character - ci_rot;
	  
 
if (character < 'A')
	    
	    {
	      
character = character + 'Z' - 'A' + 1;
	    
}
	  
 
decryption[i] = character;
	
}
    
}
  
printf ("The decrypted message with key %d is: %s", ci_rot, decryption);
  
 
 
return 0;

}


 
int sub_encrypt () 
 
{
  
char subkey[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F','G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
char text_in[500];
int counter;
int i;
int ci_minus;
  
 
 
printf ("Please enter a message to encrypt using the substitution cipher method: \n");
scanf (" %[^\n]s", text_in);
  
 
 
text_in[strlen (text_in)] = 0;
  
counter = strlen (text_in);
  
 
char encryption[counter];
  
 
for (i = 0; i < counter; i++)
    
    {
      
ci_minus = ((int) text_in[i]) - 65;
      
if (ci_minus < 0)
	
	{
	  
encryption[i] = ' ';
	
}
      
      else
	
	{
	  
encryption[i] = subkey[ci_minus];
	
}
    
}
  
encryption[counter] = 0;
  
 
printf ("The encrypted message using substitution is: %s\n", encryption);
  
 
return 0;

}


 
 
 
int sub_decrypt () 
 
{
  
char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char subkey[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F','G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

int i;
int n;
int counter;
char text_in[200];
char decryption[200];
  
 
 
printf ("Please enter a message to decrypt using the substitution cipher method: \n");
scanf (" %[^\n]s", text_in);
  
 
 
strcpy (decryption, text_in);
  
 
counter = strlen (decryption);
  
for (i = 0; i < counter; i++)
    
    {
      
for (n = 0; n < 26; n++)
	
	{
	  
if (decryption[i] == subkey[n])
	    
	    {
	      
decryption[i] = alphabet[n];
	      
break;
	    
}
	
}
    
}
  
printf ("The decrypted message using substitution is: %s\n", decryption);
  
 
return 0;

}
