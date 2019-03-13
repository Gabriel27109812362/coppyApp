
//gcc coppyApp.c -o coppy 
// ./coppy ./plik ./Folder/plik <bytes amount>

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        printf("Pass 4 args to execute programe");
    }
    FILE *in_file;
    FILE *out_file;
    int lSize;
    char *buffer;
    

    in_file = fopen(argv[1], "r");

    if(in_file)
    {
        fseek (in_file , 0 , SEEK_END);
        lSize = ftell (in_file);
        rewind (in_file);

        buffer =    (char*)malloc(sizeof(char)*lSize); 

        fread(buffer, atoi(argv[3]), lSize/atoi(argv[3]), in_file);
        fclose(in_file);


        out_file = fopen(argv[2], "wb");
        if (out_file)
        {
            fseek(out_file, 0,SEEK_SET);
            fwrite(buffer,atoi(argv[3]), lSize/atoi(argv[3]), out_file);
            fclose(out_file);
        }
        free(buffer);
        
    }
    
    return 1;
}