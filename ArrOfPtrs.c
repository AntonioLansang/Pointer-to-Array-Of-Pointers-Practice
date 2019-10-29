#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct listType
{
        int index;
        int length;
        char *phrase;
};

typedef struct listType Data;
int main(int argc, char *argv[])
{
        FILE *fp;
        char buff[1024];
        Data **ArrOfStructs;

        if(argc<2)
        {
                printf("Give file name");
                return 1;
        }

        fp=fopen(argv[1], "r");
        if(fp==NULL)
        {
                printf("File does not exist. Please try again\n");
                return 1;
        }

//Initial Reading of the files
        int NumOfLines;
        int k;
        int len;
        fscanf(fp,"%d\n", &NumOfLines);

        ArrOfStructs=calloc(NumOfLines, sizeof( Data*));

        for(k=0; k<NumOfLines; k++)
        {

                fgets(buff, 1024, fp);

        //Deletes the trailing \n from fgets
                len=strlen(buff);
                len--;
                buff[len]='\0';




        //Points to the struct
                ArrOfStructs[k]=calloc(1, sizeof(Data));
                ArrOfStructs[k]->phrase=calloc(strlen(buff),sizeof(char));
                strcpy(ArrOfStructs[k]->phrase, buff);


        }

    for (k=0; k<NumOfLines; k++)
    {
        printf("%d. %s\n",k+1, ArrOfStructs[k]->phrase);
    }

}
