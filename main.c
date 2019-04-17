#include <stdio.h>

void getLine(char line[100]);

void rotEncrypt(char line[100], int key);

int main()
{ 
    
    char str[1024];
    char c;
    int i, N;
    /*//encrypting
    while (1)
    {
        
        
        int i = 0;
        scanf("%c", &c);
        
        if (c == '\n')
        {
            str[i] = '\0';
            break;
        }
        
        str[i] = c;

        if(c != ' ')
        {
            c = c - 6;
            if(c < 65 || c > 90)
            {
                c = c + 25;
            }
        }

            i++;
            printf("%c", c);   
        
    }
    printf("\n");
    */
    
    //decrypting
    //use the spelling check to get a sentence with no errors.
    
    
    char line[100], c;
    int key, i;
    getLine(line);
    printf("Number of rotations:");
    scanf("%d", &key);
    rotEncrypt(line, key);
    printf("%s\n", line);
    
    

    return 0;
}

void getLine(char line[100]){
    char c;
    for (int i = 0; i < 100; i++){
        scanf("%c", &c);     //get character from user and store in c
        if(c == '\n')       //if c is a newline, terminate the string, and return
        {
            line[i] = '\0';
            return;
        }
        line[i] = c;        //otherwise, add c to the string 'line'
    }
    line[100] = '\0';       //sets the end of the string to \0
}

void rotEncrypt(char line[100], int key){
    char c;
    int i;
    for(i = 0; i < 100; i++){
        c = line[i];
        //if c is one of 'A'-'Z'
        if(c >= 65 && c <= 90){
            c = c - 65;
            c = (c + key)%26;
            c = c + 65;
        }
            //convert c to a number from 0-25
            //implement the formula
            //convert back to 'A'-'Z'
        line[i] = c;    
        
        //store the character back in line
        
    }

}