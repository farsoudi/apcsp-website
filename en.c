#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
//Get string to be encrypted.
    char a[100]="";
printf("Enter a string to encrypt : ");
    char str[100];
    sscanf(argv[1],"%s",str); //include white spaces
    atoi(str);

    strcat(str,"~\0");

    int len=strlen(str),i,j,k;
    char b[len][100]; //Array of length equal to length of string input.

    printf("\nPossible strings after rotation :\n\n");
    for(j=0;j<len;j++)
    {
        char last=str[len-1];

        for(i=len-1;i>0;i--)
            str[i]=str[i-1];

        str[0]=last;

        strcpy(b[j],str);
        printf("%s\n",b[j]);
    }

    for(i=0;i<len-1;i++)
        for(j=0;j<len-1;j++)
            {
                if(strcmp(b[j],b[j+1])>0)
                {
                    char temp[len]; //Temporary string
                    strcpy(temp,b[j]);
                    strcpy(b[j],b[j+1]);
                    strcpy(b[j+1],temp);
                }
            }

    printf("\nArranging in lexical order :\n\n");
    for(j=0;j<len;j++)
        printf("%s\n",b[j]);

    printf("\nEncrypted string : ");
    for(j=0;j<len;j++)
        printf ("%c",b[j][len-1]);

    return 0;
}
