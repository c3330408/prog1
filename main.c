#include <stdio.h>



int main()
{ 
    
    
    
    //encrypting
    while (1)
    {
        char str[1024];
        char c;
        int i = 0;
        scanf("%c", &c);
        
        if (c == '\n')
        {
            str[i] = '\0';
            break;
        }
        
        str[i] = c;

        if (c != ' ')
        {
            c = c - 4;
        }

            i++;
            printf("%c", c);   
        
    }
    printf("\n");
    
    
    //decrypting
    //use the spelling check to get a sentence with no errors.
    
    while (1)
    {
        char str[1024]; //won't work for later functions
        char c;
        int i = 0;
        scanf("%c", &c);
        
        if(c == '\n')
        {
            str[i] = '\n';
            break;
        }
        str[i] = c; // sentence is stored in a string
        i ++;
        
        
        
    }
    for(N = 0; N < 26; N++)
        {
            i = 0;
            str[i] = str[i] + 1;
            printf("%s\n", str);
        }
    

    return 0;
}
