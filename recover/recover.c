#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    else
    {
        // Open card.raw
        char *filename = argv[1];
        FILE *filepointer = fopen(filename, "r");

        if (filepointer == NULL)
        {
            printf("Error: cannot open %s\n", filename);
            return 1;
        }

        // Initialise variables
        BYTE buffer[512];
        int counter = 0;
        FILE *imgpointer = NULL;
        char nfilename[8];

        // Repeat from start to end
        while (fread(&buffer, 512, 1, filepointer) == 1)
        {
            // Check if is start of JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // If not first JPEG, close previous
                if (!(counter == 0))
                {
                    fclose(imgpointer);
                }
                // Initialise file
                sprintf(nfilename, "%03i.jpg", counter);
                imgpointer = fopen(nfilename, "w");
                counter++;
            }
            // If is jpeg, write file
            if (!(counter == 0))
            {
                fwrite(&buffer, 512, 1, imgpointer);
            }
        }
        fclose(filepointer);
        fclose(imgpointer);
        return 0;
    }
}

