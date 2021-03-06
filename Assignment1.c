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
 to choose between operations, depending which exercise they would like to exicute. By selecting either (A), (B), (C), (D), (E) or (F) the 
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
  
 
return 0;                      //The 'return 0' is used to signal that the main function exicuted correctly and can now exit

}

/*
The following function, called from case 'A', is a rotating encryption cipher. Furthermore, when called upon by the user through 
the interactive interface the function will ask the the user to enter text. The function will store the users text in a string called
"encryption" and follow by asking the user for a key. The key is a integer by which the function rotates the alphabet. e.g. with a
key of 4 'A' is shifted to 'E', 'B' shifted to 'F' etc... Each character of the keyboard is assigned a number which can be located
in the ASCII Table. Contained within the for loop, the code stores each character entered and rotates it through the alphabet by the
key entered accoring to the numbers of the ASCII Table. e.g. 'A' on the ASCII Table is 65, therefore with a key of 4 added it is now 69,
hence, 69 on the ASCII Table is the charcter 'E' etc... 
 */
 
 
 
int rot_encrypt () 
 
{
  
char encryption[200];                                //String (text) entered by the user stored to 'encryption' where 200 character spaces have been made avaliable
char character;                                      //A variable that when the string is stored to 'encryption' it is then assigned to 'charcter' so that the for loop can exicute the rotation of each character in the string
int i;                                               //A variable used that starts at zero and allows the for loop to exicute the rotation by the desired key for each character of the string
int ci_rot;                                          //Cipher rotation (Key), how much the string is to be rotated alone the alphabet e.g. key 4 with character (A) becomes (E) 
  
 
printf ("Please enter a message to encrypt: \n");	 //user input for their sentence to be encrypted
scanf (" %[^\n]s", encryption);	                     //scanning the message entered by the user and placing it in the string 'encryption'
printf ("Please enter the cipher key: ");        	 //A Key is how many places the encryption rotates the characters eg. key of 3 will turn 'A' into 'D'
scanf (" %d", &ci_rot);	                             //scanning the key entered by the user for the code to execute 
  
for (i = 0; encryption[i] != '\0'; i++)	             //A for loop that: starts by asigning the string 'encryption' to zero,                
    {				                                 //string 'encryption' is not equal to NULL and the string is incriminated by 1  
      character = encryption[i];	                 //Asigns 'encryption' string to 'character'
      
if (character >= 'a' && character <= 'z')	         //If statement with conditions (if character is greater than or equal to "a") AND (if character is less than or equal to "z")
	{
	  
character = character + ci_rot;	                     //Asigns the character entered to the new character by rotating it by the number of time depending on the key (eg. "A" with a key of 4 is now "D")
	  
if (character > 'z')	                             //If the character is then larger than 'z' do the following
	    {
	       
character = character - 'z' + 'a' - 1;	             //The previous character value of 'z' is added to the ascii value of 'a' and 1 is subtracted e.g. if Z is entered with a rotation key of 1, the new character will be A
	    }
	  
 
encryption[i] = character;	                         //The char characters are reassigned to the string 'encryption' after they have been rotated by the key
	}
      
      else if (character >= 'A' && character <= 'Z') //The same code above but now for upper case characters
	
	{
	  
character = character + ci_rot;
	  
 
if (character > 'Z')
	    
	    {
	      
character = character - 'Z' + 'A' - 1;
	    
}
	  
 
encryption[i] = character;
	
}
    
}
  
 
printf ("The encrypted message with key %d is: %s", ci_rot, encryption); //Printed to the user is the following message of the encryped text by the key of which they decided
  
 
 
return 0;

}



/*
The following function, called from case 'B', is a rotating decryption cipher. Furthermore, when called upon by the user through 
the interactive interface the function will ask the the user to enter text. The function will store the users text in a string called
"decryption" and follow by asking the user for a key. The key is a integer by which the function rotates the alphabet. e.g. with a
key of 4 'A' is shifted to 'W', 'B' shifted to 'X' etc... Each character of the keyboard is assigned a number which can be located
in the ASCII Table. Contained within the for loop, the code stores each character entered and rotates it through the alphabet by the
key entered accoring to the numbers of the ASCII Table. e.g. 'A' on the ASCII Table is 65, therefore with a key of 4 added it is now 87,
hence, 87 on the ASCII Table is the charcter 'W' etc... This is slighly more confusing that the encryption but shown below is how the
function only uses the 26 characters of the alphabet without calling the other sysmbols of the keyboard 
 */
 
 
int rot_decrypt () 
 
{
  
char decryption[200];                                      //String (text) entered by the user stored to 'decryption' where 200 character spaces have been made avaliable
char character;                                            //A variable that when the string is stored to 'decryption' it is then assigned to 'charcter' so that the for loop can exicute the rotation of each character in the string
int i;                                                     //A variable used that starts at zero and allows the for loop to exicute the rotation by the desired key for each character of the string
int ci_rot;                                                //Cipher rotation (Key), how much the string is to be rotated alone the alphabet e.g. key 4 with character (A) becomes (W) 
  
 
printf ("Please enter a message to decrypt: ");            //user input for their sentence to be decrypted
scanf ("%s", decryption);                                  //scanning the message entered by the user and placing it in the string 'decryption'
printf ("Please enter the cipher key: ");                  //A Key is how many places the encryption rotates the characters eg. key of 4 will turn 'A' into 'W'
scanf ("%d", &ci_rot);                                     //scanning the key entered by the user for the code to execute 
  
 
for (i = 0; decryption[i] != '\0'; i++)                    //The following for loop sets the variable i to equal zero, the string 'decryption' is not equal to 'NULL' and each character of the loop will be rotated by the key separtly 
    
    {
      
character = decryption[i];                                 //The text entered by the user that was saved in the string 'decryption' has now been assigned to the char 'character'
      
 
if (character >= 'a' && character <= 'z')                  //If the character entered is greater than or equal to 'a' AND less than or equal to 'z' the following is exicuted
	
	{
	  
character = character - ci_rot;                            //Each character from the string is minused by the key enetered e.g. 'l' is now 'h'
	  
 
if (character < 'a')                                       //Hence, if the character is less than 'a' or rotates past 'a', then the following is exicuted
	    
	    {
	      
character = character + 'z' - 'a' + 1;                     //Each character that rotates past the character 'a' has the ASCII value 'z' added to it, minus the ASCII value 'a', plus 1
	    
}
	  
 
decryption[i] = character;                                 //All the characters from the char character have now been rotated or decryped by the desired key and are now reassigned to the string 'decrytion'
	
}
      
      else if (character >= 'A' && character <= 'Z')       //The same code above but now for upper case characters
	
	{
	  
character = character - ci_rot;
	  
 
if (character < 'A')
	    
	    {
	      
character = character + 'Z' - 'A' + 1;
	    
}
	  
 
decryption[i] = character;
	
}
    
}
  
printf ("The decrypted message with key %d is: %s", ci_rot, decryption);     //Printed to the user is the following message of the decryped text by the key of which they decided
  
 
 
return 0;

}



/*
The following function, called from case 'C', is a substitution encryption cipher. Furthermore, when called upon by the user through 
the interactive interface the function will ask the the user to enter text. The function will store the users text in a string called
"text_in". The key is defined by 'subkey' and was given withing the project requirements. The function then determines the strings length using 'strlen'. 
The function then get the new character in the cipher by subtracting 'A' (65) from the current character. 
This is effictivly changing 'A' to 'Q', 'B' to 'W' etc... and storing the new, substituted characters into the string 'encryption' 
whereby it is then printed to the user.
 */
 
int sub_encrypt () 
 
{
  
char subkey[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F','G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
char text_in[200];              //String (text) entered by the user stored to 'decryption' where 200 character spaces have been made avaliable
int counter;                    //The length of the string is stored to counter so that when exicuted in the for loop it exits after the desired amount of characteres needing to be encrypted 
int i;                          //A variable used that starts at zero and allows the for loop to exicute each character of the string by the substitution
int ci_minus;                   //A variable where the text entered by the user is stored once the substitution has occured
  
 
 
printf ("Please enter a message to encrypt using the substitution cipher method: \n"); //Interface asks the user for text to be encrypted
scanf (" %[^\n]s", text_in);                                                           //Text ntered by the user is stored in 'text_in'
  
 
 
text_in[strlen (text_in)] = 0;                                                         //strlen is used to find the length of the string 
  
counter = strlen (text_in);                                                            //Once the length of the string is found, this integer is stored to 'counter'. This tells the loop how many times to run.
  
 
char encryption[counter];                                                              /*After the length of the string has been determined and stored in 'counter', it is then used to 
                                                                                       store that amount of spaces in the new string called 'encryption' which will be later printed to the user as the encrypted text 
                                                                                       */  
 
for (i = 0; i < counter; i++)                                                          //The following for loop assigns 'i' to equal zero, which is to be less than the string 'text_in' length and to repeat until all characters have been exicuted
    
    {
      
ci_minus = ((int) text_in[i]) - 65;                                                    //Determines what the new character needs to be in the cipher by subtracting 'A' (65) from the current character
      
if (ci_minus < 0)                                                                      //If the user enters less than zero characterers, the string 'encryption' will be set to a space. This is for if there is more than 1 word entered or no text entred at all
	
	{
	  
encryption[i] = ' ';                                                                   //'encryption' string assigned to a space 
	
}
      
      else
	
	{
	  
encryption[i] = subkey[ci_minus];                                                      // Else, assign the 'subkey' (encrypted text which has already been substituted) to the encryption string which will then be printed to the user as seen below
	
}
    
}
  
encryption[counter] = 0;                                                               //NULL event, therefore the string is terminated
  
 
printf ("The encrypted message using substitution is: %s\n", encryption);              //Printed to the user is the following message of the encryped text by the substitution key
  
  
 
return 0;

}



/*
The following function, called from case 'D', is a substitution decryption cipher. Furthermore, when called upon by the user through 
the interactive interface the function will ask the the user to enter text. The function will store the users text in a string called
"text_in". The key is defined by 'subkey' and was given withing the project requirements. The function then determines the strings length using 'strlen'. 
The function then assigns the text entered to the string 'decryption'. Using a for loop, the characters stored in 'decryption' are substituted back to "plan text", 
defined by the string 'alphabet'.
 */
 
 
 
int sub_decrypt () 
 
{
  
char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char subkey[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F','G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

int i;                       //A variable used that starts at zero and allows the for loop to exicute each character of the string by the substitution
int n;                       //A variable used that starts at zero and allows the for loop to exicute each character of the string by the substitution
int counter;                 //Used to store the numerical value of the string entered by the user
char text_in[200];           //Where the text first entered by the user is stored
char decryption[200];        //Where the text entered by the user is assigned to the string 'decryption', this is then exicuted in the for loop. Once substituted back into "plan text" it is then printed to the user
  
 
 
printf ("Please enter a message to decrypt using the substitution cipher method: \n"); //User is asked to enetr text for decryption by the substitution cipher method
scanf (" %[^\n]s", text_in);                                                           //Text entered by the user is stored to the string 'text_in'
  
 
 
strcpy (decryption, text_in);                      //Assigns the string 'text_in' to the new string 'decryption'
  
 
counter = strlen (decryption);                     //Using the strlen function, this line counts the length of the string and assigns the number to the ineger 'counter'
  
for (i = 0; i < counter; i++)                      //For loop which will exicute the following loop until the number of characters entered is complete which is know by the variable 'counter'
    
    {
      
     for (n = 0; n < 26; n++)                      /*A for loop that uses an 'if' statement, changing the encrypted text entered by the user into "plan text". 
                                                     Because there is only one substitution key (Subkey) it will take the encryptd text that is stored in 'decryption'
                                                     and then assign it the the correct string called 'alphabet'. this process is carried out for each character
                                                     until the parent loop fails, meaning all characters have been decrypted back into "plan text"
	                                               */
	 {
	  
      if (decryption[i] == subkey[n])
	    
	   {
	      
        decryption[i] = alphabet[n];
	      
      break;
	    
       }
	
     }
    
    }
  
printf ("The decrypted message using substitution is: %s\n", decryption); //Printed to the user is the following message of the decryped text by the substitution key
  
  
 
return 0;

}
