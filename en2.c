#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //Get string to be encrypted.
    printf("Enter a string to encrypt : ");
    char str[100];
    scanf("\n%[^\n]",str); //include white spaces

    //Add ~ at the end of string to work as pointer while decrypting.
    strcat(str,"~\0");

    int len=strlen(str),i,j,k;
    char b[len][100]; //Array of length equal to length of string input.

    //Burrows Wheeler Transformation
    //Store all possible rotations by rotating each character by 1 unit.
    printf("\nPossible strings after rotation :\n\n");
    for(j=0;j<len;j++)
    {
        //Store last character of string.
        char last=str[len-1];

        //Displace each character by one unit.
        for(i=len-1;i>0;i--)
            str[i]=str[i-1];

        //Make stored last character as first character.
        str[0]=last;

        //Store and print rotated string.
        strcpy(b[j],str);
        printf("%s\n",b[j]);
    }

    //Sort stored strings in lexical order
    //Bubble sort algorithm
    for(i=0;i<len-1;i++)
        for(j=0;j<len-1;j++)
            {
                //Compare two strings using strcmp.
                //If 1st string is greater than 2nd then swap strings.
                if(strcmp(b[j],b[j+1])>0)
                {
                    char temp[len]; //Temporary string
                    strcpy(temp,b[j]);
                    strcpy(b[j],b[j+1]);
                    strcpy(b[j+1],temp);
                }
            }

    //Print lexical ordered strings one by one.
    printf("\nArranging in lexical order :\n\n");
    for(j=0;j<len;j++)
        printf("%s\n",b[j]);

    //Encrypted string made up of last character of each lexical ordered strings from top to bottom.
    printf("\nEncrypted string : ");
    for(j=0;j<len;j++)
        printf ("%c",b[j][len-1]);

    return 0;
}
