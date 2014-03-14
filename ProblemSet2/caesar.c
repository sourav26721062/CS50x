#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
//test case: ./caesar 13
//Input: Be sure to drink your Ovaltine!
//Output:Or fher gb qevax lbhe Binygvar!
 
int main(int argc, string argv[])
{   
    int k,i,r;
    string text;
    char result[100];
 
    if(argc!=2 || atoi(argv[1])< 0)       //check for appropiate command line argument
    {
    printf("Wrong input!!");
    return 1;
    }
    else
    {
        k=atoi(argv[1]);
        text=GetString();
        
        for (i=0;i<strlen(text);i++)
            {   
            
                if(((int)text[i]>=65 && (int)text[i]<=90 )||((int)text[i]>=97 && (int)text[i]<=122))    //check for alphabets
                {
                if(isupper(text[i]))        //check for upper case
                {   
                    if(text[i]==' ')
                        result[i]=' ';
                    else
                    {
                    r=(int)text[i]+k;
                    while (r>90)
                        r=64+(r-90);
                    result[i]=(char)r;
                    }
                }
                
                else                        //check for lower case
                {
                    if(text[i]==' ')
                        result[i]=' ';
                    else
                    {
                    r=(int)text[i]+k;
                    while (r>122)
                        r=96+(r-122);
                    result[i]=(char)r;
                    }
                }
                }
                
                else                    //check for special characters
                result[i]=text[i];
                
               
              
            }
            
     //printing output
 
     for (i=0;i<strlen(text);i++)
     printf("%c",result[i]);
     }
        printf("\n");
   
}
 