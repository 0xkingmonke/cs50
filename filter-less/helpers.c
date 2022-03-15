#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tempR = image[i][j].rgbtRed;
            int tempG = image[i][j].rgbtGreen;
            int tempB = image[i][j].rgbtBlue;

            if (tempR == tempG && tempR == tempB)
            {
                continue;
            }
            else
            {
                double tempGrey = (tempR + tempG + tempB) / 3.0;
                int tempgreyint = (int) tempGrey;
                double tempgreydp = tempGrey - tempgreyint;
                int greyval;
                if ((tempgreydp) >= 0.5)
                {
                    greyval = tempgreyint + 1;
                }
                else
                {
                    greyval = tempgreyint;
                }
                image[i][j].rgbtRed = greyval;
                image[i][j].rgbtGreen = greyval;
                image[i][j].rgbtBlue = greyval;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int OR = image[i][j].rgbtRed;
            int OG = image[i][j].rgbtGreen;
            int OB = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * OR + 0.769 * OG + 0.189 * OB);
            int sepiaGreen = round(0.349 * OR + 0.686 * OG + 0.168 * OB);
            int sepiaBlue = round(0.272 * OR + 0.534 * OG + 0.131 * OB);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int OR = image[i][j].rgbtRed;
            int OG = image[i][j].rgbtGreen;
            int OB = image[i][j].rgbtBlue;

            tempimage[i][j].rgbtRed = OR;
            tempimage[i][j].rgbtGreen = OG;
            tempimage[i][j].rgbtBlue = OB;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimage[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = tempimage[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = tempimage[i][width - j - 1].rgbtBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0) // top left corner case
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed
                                                 + image[i + 1][j + 1].rgbtRed) / 4.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen
                                                   + image[i + 1][j + 1].rgbtGreen) / 4.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue
                                                  + image[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == width - 1) // top right corner case
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed
                                                 + image[i + 1][j - 1].rgbtRed) / 4.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen
                                                   + image[i + 1][j - 1].rgbtGreen) / 4.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue
                                                  + image[i + 1][j - 1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j != 0 && j != width - 1) // top row non corner cases
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed)
                                            + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0;
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen)
                                            + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0;
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue)
                                            + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/6.0;
            }
            else if (i == height - 1 && j == 0) // bottom left corner case
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed)/4.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)/4.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue)/4.0);
            }
            else if (i == height - 1 && j == width - 1) // bottom right corner case
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed)/4.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen)/4.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue)/4.0);
            }
            else if (i == height - 1 && j != 0 && j != width - 1) // bottom row non corner cases
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed)/6.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen)/6.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue)/6.0);
            }
            else if (i != 0 && i!= height - 1 && j == 0)// left column non corner cases
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/6.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/6.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/6.0);
            }
            else if (i != 0 && i!= height - 1 && j == width - 1)// right column non corner cases
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed)/6.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen)/6.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue)/6.0);
            }
            else // all non edge / corner cases
            {
                tempimage[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)/9.0);
                tempimage[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/9.0);
                tempimage[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/9.0);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempimage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempimage[i][j].rgbtBlue;
        }
    }
    return;
}
