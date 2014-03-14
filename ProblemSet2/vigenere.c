 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
//test case: ./vigenere bacon
//Input: Meet me at the park at eleven am
//Output:Negh zf av huf pcfx bt gzrwep oz
 
int main(int argc, string argv[])
{
    int r,i,k_length,t_length,shift[26],s_index,j=0;
    string text,key;
    char result[100],k_char;
       
    if(argc==2)
        {   
            k_length=strlen(argv[1]);
            for(i=0;i<k_length;i++)
                {
                    if(!isalpha(argv[1][i]))
                    {
                        printf("Wrong input");
                        return 1;
                    }
                }
            text=GetString();
            key=argv[1];
            t_length=strlen(text);
            
            // No. of shifts in shift[i]
            for(i=0;i<26;i++)
            shift[i]=i;
            
            
            for(i=0;i<t_length;i++)
            {
                if (isupper(text[i])&& text[i]!=' ')    //for text in upper case
                {   
                    k_char=toupper(key[j%k_length]);           //storing the single char from key acc to sequence 
                    s_index=(int)k_char-65;             //findind the shift array value index
                    r=(int)text[i]+shift[s_index];      //encipher
                    while(r>90)                            //check if enciphered value is more than Ascii value of Z = 90
                    r=(r-90)+64;                        //return to value to start of A 
                    result[i]=(char)r;                  //inserting value of ciphered char to result array
                    j++;                                //increment value of index of key
                }
                 
                 else if (islower(text[i])&& text[i]!=' ')  //for text in lower case
                {    
                    k_char=tolower(key[j%k_length]);           //storing the single char from key acc to sequence 
                    s_index=(int)k_char-97;             //findind the shift array value index
                    r=(int)text[i]+shift[s_index];      //encipher
                    while(r>122)                           //check if enciphered value is more than Ascii value of z = 122
                    r=(r-122)+96;                       //return to value to start of a
                    result[i]=(char)r;                  //inserting value of ciphered char to result array
                    j++;                                //increment value of index of key
                }
                
                else
                {
                    if(text[i]==' ')                    // for space
                    result[i]=' ';
                    else                                //for other characters
                    result[i]=text[i];
                }
                 
            }
             //printing the ciphered text
             for (i=0;i<strlen(text);i++)
             printf("%c",result[i]);
             printf("\n");
            
        }
        
     else
     {
     printf("Wrong input");
     return 1;
     }
}