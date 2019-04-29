#include <stdio.h>
#include <string.h>

void getLine();

void rotEncrypt(char line[1000], int key);

void rotDecrypt(char line[1000], int key);

void subEncrypt(char line[1000]);

void subDecrypt(char line[1000]);

void findThe(char line[1000]);

void findYou(char line[1000]);

        char line[1000], c;
        
int main()
{ 
    int x = 1;
    while(x){
        int key;
        int choice; //Initiates flow of the program
        
        printf("1: Encrypt Substitution\n2: Decrypt Substitution\n3: Decrypt Substitution without key\n4: Encrypt Rotation\n5: Decrypt Rotation\n6: Decrypt Rotation without Key\n7: End\n"); //gives options for user
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                scanf("%c", &c);    //first scanf in a switch statement doesn't get read
                printf("Enter Text: ");
                getLine(line);    //Gets line from user input and stores it in an array
                subEncrypt(line);    //function does a substitution encryption
                printf("First 13 letters substituted with last 13:\n");    //Informs user of the substitution key
                printf("%s\n", line);    //prints encyrpted text
                break;
            
            case 2:
                scanf("%c", &c);    //first scanf in a switch statement doesn't get read
                printf("Enter Text: ");
                getLine(line);    //Gets line from user input and stores it in an array
                subDecrypt(line);    //function does a substitution decryption
                printf("First 13 letters substituted with last 13:\n");    //Informs user of the substitution key
                printf("%s\n", line);    //prints encyrpted text
                break;
            
            case 4:
                scanf("%c", &c);    //first scanf in a switch statement doesn't get read
                printf("Enter Text: ");
                getLine(line);    //Gets line from user input and stores it in an array
                printf("Number of rotations:");
                scanf("%d", &key);    //decides how many times the cipher rotates
                rotEncrypt(line, key);    //function encrypts cipher code
                printf("%s\n", line);    //prints encrypted text
                break;    //breaks out of switch statement
                
            case 5:
                scanf("%c", &c);    //first scanf in a switch statement doesn't get read
                printf("Enter Text: ");
                getLine(line);    //Gets line from user input and stores it in an array
                printf("Number of rotations:");
                scanf("%d", &key);    //decides how many times the cipher rotates
                rotDecrypt(line, key);    //function decrypts cipher code with a given key
                printf("%s\n", line);    //prints decrypted text
                break;    //breaks out of switch statement
                
            case 6:
                scanf("%c", &c);    //first scanf in a switch statement doesn't get read
                printf("Enter Text: ");
                getLine(line);    //Gets line from user input and stores it in an array
                printf("\n");    //adds some spacing to the output
                for(int i = 1; i < 26; i++){    /* goes through all possible keys for cipher*/
                    key = 1;
                    rotDecrypt(line, key);    //decrypts cipher
                    findThe(line);    //finds if 'THE' is in the sentence and prints it
                    
                }
                printf("Was cipher decrypted?\n1: NO\n2: YES\n3: Force all possible ciphers?\n");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                        for(int i = 1; i < 26; i++){    /* goes through all possible keys for cipher*/
                            key = 1;
                            rotDecrypt(line, key);    //decrypts cipher
                            findYou(line);    //finds if 'I' is in the sentence and prints it. but only if I is on its own.
                        }
                        break;    
                    
                    case 2:
                            break;  //user has nothing more to do so switch statement breaks
                            
                    case 3:
                        for(int i = 1; i < 26; i++){    /* goes through all possible keys for cipher*/
                            key = 1;
                            rotDecrypt(line, key);    //decrypts cipher
                            printf("%d: %s\n", i, line);
                        }
                        break;
                        
                    default:
                        break;
                }

                break;    //breaks out of switch statement
                
            case 7:
                x = 0;    //sets x to 0 to stop the infinite loop
                break;    //breaks out of switch statement
            
            default:
                printf("Choose an option from 1-7\n");    //asks user to choose an available option
                break;    //breaks out of switch statement
        }
        
    }
    //use the spelling check to get a sentence with no errors.
    return 0;
}




void getLine(char line[1000]){
//This function gets input from the user and stores each character into an array including whitespace    
    char c;
    
    for (int i = 0; i < 1000; i++){
        scanf("%c", &c);     //gets characters from user and stores them in c
        if(c == '\n')       //if c is a newline the string will terminate and return
        {
            line[i] = '\0';
            return;
        }
        line[i] = c;        //if c isn't a new line add c to the string 'line'
    }
    line[100] = '\0';       //sets the end of the string to \0

    
}



void rotEncrypt(char line[1000], int key){
//This function rotates the letters in an array by a given amount. Encrypts a Rotation cipher
    char c;
    int i;
    for(i = 0; i < 1000; i++){
        c = line[i];
        //only initiates if c is one of 'A'-'Z'
        if(c >= 65 && c <= 90){
            c = c - 65;    //convert c to a number from 0-25
            c = (c + key)%26;   //implement the formula given
            c = c + 65;    //convert back to 'A'-'Z'
        }   
        line[i] = c;    //This will store the character back in line
    }
}


void rotDecrypt(char line[1000], int key){
//This function rotates the letters in an array by a given amount. Decrypts a Rotation cipher
    char c;
    int i;
    for(i = 0; i < 1000; i++){
        c = line[i];
        //only initiates if c is one of 'A'-'Z'
        if(c>= 65 && c <= 90){
            c = c - 65;    //converts c to a number from 0 - 25
            c = (c - key);    //Decryption formula implemented
            if(c < 0){
                c = c + 26;    //Stops the modulus dividing a negative number by adding 26
            }
            c = c%26;   //second part of the formula
            c = c + 65;    //converts back to 'A'-'Z'
            
               
        }
        line[i] = c;    //This will store the character back into line
    }
}

void subEncrypt(char line[1000]){
//This function substitues the first 13 letters with the last 13 letters in an array. Ecnrypts a Substitution cipher
    char c;
    int i;
    for(i = 0; i < 1000; i++){
        c = line[i];
        //only initiates if c is one of 'A'-'Z'
        if(c>= 65 && c <= 90){
            if(c>= 65 && c <= 77){
                c = c + 13;    //substitues first 13 letters of alphabet into last 13
            }
            else if(c>= 78 && c <= 90){
                c = c - 13;    //substitues last 13 letters of alphabet into first 13
            }
        }
        line[i] = c;    //stores character back into array
    }
}

void subDecrypt(char line[1000]){
//This function substitues the first 13 letters with the last 13 letters in an array. Decrypts a Substitution cipher
    char c;
    int i;
    for(i = 0; i < 1000; i++){
        c = line[i];
        //only initiates if c is one of 'A'-'Z'
        if(c>= 65 && c <= 90){
            if(c>= 65 && c <= 77){
                c = c + 13;    //substitutes last 13 letters back into original positions
            }
            else if(c>= 78 && c <= 90){
                c = c - 13;    //substitutes first 13 letters back into original positions
            }
        }
        line[i] = c;    //stores character back into array
    }
}


void findThe(char line[1000]){
	char search[] = "THE";     //string that contains the word 'THE'
	char *ptr = strstr(line, search);  //function for finding a string within a string

	if (ptr != NULL)    //This occurs when a substring is found
	{
		printf("%s\n", line);     //prints when substring is found
	}
	
}


void findYou(char line[1000]){
	char search[] = "YOU";     //string that contains the word 'YOU'
	char *ptr = strstr(line, search);      //function for finding a string within a string

	if (ptr != NULL)    //This occurs when a substring is found
	{
		printf("%s\n", line);     //prints when substring is found
	}
	
}