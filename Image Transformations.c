#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float sum, avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen);//stores the sum of the pixels
            avg = sum / 3; // takes average of the numbers
            image[i][j].rgbtRed = (int) round(avg);//round to nearest integer
            image[i][j].rgbtBlue = (int) round(avg);
            image[i][j].rgbtGreen = (int) round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    double sRed, sBlue, sGreen;//stores the sepia values of individual colours of each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;//sepia red formula
            sGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;//sepia green formula
            sBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;//sepia blue formula
            if (sRed > 255)
            {
                image[i][j].rgbtRed = 255;//set pixel value to 255 if it exceeds 255
            }
            else
            {
                image[i][j].rgbtRed = (int) round(sRed);//round to nearest integer
            }
            if (sGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (int) round(sGreen);
            }
            if (sBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (int) round(sBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int cR, cG, cB;//temporary variables
    for (int i = 0; i < height ; i++)
    {
        if (width % 2 == 0)// check if image has even number of columns
        {
            for (int j = 0; j < (width / 2); j++)
            {
                for (int k = 0; k < width ; k++)
                {
                    if (j + k == (width - 1))
                    {
                        cR = image[i][j].rgbtRed;
                        image[i][j].rgbtRed = image[i][k].rgbtRed;
                        image[i][k].rgbtRed = cR;

                        cB = image[i][j].rgbtBlue;
                        image[i][j].rgbtBlue = image[i][k].rgbtBlue;
                        image[i][k].rgbtBlue = cB;

                        cG = image[i][j].rgbtGreen;
                        image[i][j].rgbtGreen = image[i][k].rgbtGreen;
                        image[i][k].rgbtGreen = cG;

                        break;//exit the loop
                    }
                }

            }
        }
        else//odd number of columns
        {
            int w = (width - 1);
            for (int j = 0; j < (w / 2); j++)
            {
                for (int k = 0; k < width; k++)
                {
                    if (j + k == w)
                    {
                        cR = image[i][j].rgbtRed;
                        image[i][j].rgbtRed = image[i][k].rgbtRed;
                        image[i][k].rgbtRed = cR;

                        cB = image[i][j].rgbtBlue;
                        image[i][j].rgbtBlue = image[i][k].rgbtBlue;
                        image[i][k].rgbtBlue = cB;

                        cG = image[i][j].rgbtGreen;
                        image[i][j].rgbtGreen = image[i][k].rgbtGreen;
                        image[i][k].rgbtGreen = cG;

                        break;//exit the loop
                    }
                }
            }
        }
    }
    return;
}
//BLURS the image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width - 1, h = height - 1;//stores the final number of row and column
    RGBTRIPLE images2[height][width];//temporary array
    for (int i = 0; i < height; i++) // copying array
    {
        for (int j = 0; j < width; j++)
        {
            images2[i][j] = image[i][j];
        }
    }

    double avgR, avgG, avgB;//takes average of the colours numbers


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int cR = 0, cG = 0, cB = 0;//store the sum of the neighbouring colours

            if (i == 0 && j == 0)//upper left corner
            {
                cR = images2[0][0].rgbtRed + images2[0][1].rgbtRed + images2[1][0].rgbtRed + images2[1][1].rgbtRed;
                cB = images2[0][0].rgbtBlue + images2[0][1].rgbtBlue + images2[1][0].rgbtBlue + images2[1][1].rgbtBlue;
                cG = images2[0][0].rgbtGreen + images2[0][1].rgbtGreen + images2[1][0].rgbtGreen + images2[1][1].rgbtGreen;
                avgR = cR / (4 * 1.0);
                avgG = cG / (4 * 1.0);
                avgB = cB / (4 * 1.0);
                image[0][0].rgbtRed = (int) round(avgR);
                image[0][0].rgbtGreen = (int) round(avgG);
                image[0][0].rgbtBlue = (int) round(avgB);

            }
            else if (i == h && j == 0)//bottom left corner
            {
                cR = images2[h][0].rgbtRed + images2[h][1].rgbtRed + images2[h - 1][0].rgbtRed + images2[h - 1][1].rgbtRed;
                cB = images2[h][0].rgbtBlue + images2[h][1].rgbtBlue + images2[h - 1][0].rgbtBlue + images2[h - 1][1].rgbtBlue;
                cG = images2[h][0].rgbtGreen + images2[h][1].rgbtGreen + images2[h - 1][0].rgbtGreen + images2[h - 1][1].rgbtGreen;
                avgR = (double)(cR / (4 * 1.0));
                avgG = (double)(cG / (4 * 1.0));
                avgB = (double)(cB / (4 * 1.0));
                image[h][0].rgbtRed = (int) round(avgR);
                image[h][0].rgbtGreen = (int) round(avgG);
                image[h][0].rgbtBlue = (int) round(avgB);

            }
            else if (i == 0 && j == w)//upper right corner
            {
                cR = images2[0][w].rgbtRed + images2[0][w - 1].rgbtRed + images2[1][w].rgbtRed + images2[1][w - 1].rgbtRed;
                cB = images2[0][w].rgbtBlue + images2[0][w - 1].rgbtBlue + images2[1][w].rgbtBlue + images2[1][w - 1].rgbtBlue;
                cG = images2[0][w].rgbtGreen + images2[0][w - 1].rgbtGreen + images2[1][w].rgbtGreen + images2[1][w - 1].rgbtGreen;
                avgR = (double)(cR / (4 * 1.0));
                avgG = (double)(cG / (4 * 1.0));
                avgB = (double)(cB / (4 * 1.0));
                image[0][w].rgbtRed = (int) round(avgR);
                image[0][w].rgbtGreen = (int) round(avgG);
                image[0][w].rgbtBlue = (int) round(avgB);

            }
            else if (i == h && j == w)//lower right corner
            {
                cR = images2[h][w].rgbtRed + images2[h][w - 1].rgbtRed + images2[h - 1][w].rgbtRed + images2[h - 1][w - 1].rgbtRed;
                cB = images2[h][w].rgbtBlue + images2[h][w - 1].rgbtBlue + images2[h - 1][w].rgbtBlue + images2[h - 1][w - 1].rgbtBlue;
                cG = images2[h][w].rgbtGreen + images2[h][w - 1].rgbtGreen + images2[h - 1][w].rgbtGreen + images2[h - 1][w - 1].rgbtGreen;
                avgR = (double)(cR / (4 * 1.0));
                avgG = (double)(cG / (4 * 1.0));
                avgB = (double)(cB / (4 * 1.0));
                image[h][w].rgbtRed = (int) round(avgR);
                image[h][w].rgbtGreen = (int) round(avgG);
                image[h][w].rgbtBlue = (int) round(avgB);

            }
            else if (i == 0 && (0 < j < w))//topmost row
            {
                cR = images2[0][j - 1].rgbtRed + images2[0][j].rgbtRed + images2[0][j + 1].rgbtRed + images2[1][j - 1].rgbtRed + 
                     images2[1][j].rgbtRed + images2[1][j + 1].rgbtRed;
                cG = images2[0][j - 1].rgbtGreen + images2[0][j].rgbtGreen + images2[0][j + 1].rgbtGreen + images2[1][j - 1].rgbtGreen + 
                     images2[1][j].rgbtGreen + images2[1][j + 1].rgbtGreen;
                cB = images2[0][j - 1].rgbtBlue + images2[0][j].rgbtBlue + images2[0][j + 1].rgbtBlue + images2[1][j - 1].rgbtBlue + 
                     images2[1][j].rgbtBlue + images2[1][j + 1].rgbtBlue;
                avgR = (double)(cR / (6 * 1.0));
                avgG = (double)(cG / (6 * 1.0));
                avgB = (double)(cB / (6 * 1.0));
                image[i][j].rgbtRed = (int) round(avgR);
                image[i][j].rgbtGreen = (int) round(avgG);
                image[i][j].rgbtBlue = (int) round(avgB);

            }
            else if (i == h && (0 < j < w))//bottomost row
            {
                
                cR = images2[h][j - 1].rgbtRed + images2[h][j].rgbtRed + images2[h][j + 1].rgbtRed + images2[h - 1][j - 1].rgbtRed + images2[h - 
                        1][j].rgbtRed + images2[h - 1][j + 1].rgbtRed;
                cG = images2[h][j - 1].rgbtGreen + images2[h][j].rgbtGreen + images2[h][j + 1].rgbtGreen + images2[h - 1][j - 1].rgbtGreen +
                     images2[h - 1][j].rgbtGreen + images2[h - 1][j + 1].rgbtGreen;
                cB = images2[h][j - 1].rgbtBlue + images2[h][j].rgbtBlue + images2[h][j + 1].rgbtBlue + images2[h - 
                        1][j - 1].rgbtBlue + images2[h - 1][j].rgbtBlue + images2[h - 1][j + 1].rgbtBlue;
                avgR = (double)(cR / (6 * 1.0));
                avgG = (double)(cG / (6 * 1.0));
                avgB = (double)(cB / (6 * 1.0));
                image[i][j].rgbtRed = (int) round(avgR);
                image[i][j].rgbtGreen = (int) round(avgG);
                image[i][j].rgbtBlue = (int) round(avgB);

            }
            else if (j == 0 && (0 < i < h))//leftmost column
            {
                cR = images2[i - 1][j].rgbtRed + images2[i][j].rgbtRed + images2[i + 1][j].rgbtRed + images2[i - 1][j + 1].rgbtRed + images2[i][j + 
                        1].rgbtRed + images2[i + 1][j + 1].rgbtRed;
                cG = images2[i - 1][j].rgbtGreen + images2[i][j].rgbtGreen + images2[i + 1][j].rgbtGreen + images2[i - 1][j + 1].rgbtGreen +
                     images2[i][j + 1].rgbtGreen + images2[i + 1][j + 1].rgbtGreen;
                cB = images2[i - 1][j].rgbtBlue + images2[i][j].rgbtBlue + images2[i + 1][j].rgbtBlue + images2[i - 1][j + 1].rgbtBlue +
                     images2[i][j + 1].rgbtBlue + images2[i + 1][j + 1].rgbtBlue;
                avgR = (double)(cR / (6 * 1.0));
                avgG = (double)(cG / (6 * 1.0));
                avgB = (double)(cB / (6 * 1.0));
                image[i][j].rgbtRed = (int) round(avgR);
                image[i][j].rgbtGreen = (int) round(avgG);
                image[i][j].rgbtBlue = (int) round(avgB);

            }
            else if (j == w && (0 < i < h))//rightmost column
            {
                cR = images2[i - 1][j].rgbtRed + images2[i][j].rgbtRed + images2[i + 1][j].rgbtRed + images2[i - 1][j - 1].rgbtRed + images2[i][j - 
                        1].rgbtRed + images2[i + 1][j - 1].rgbtRed;
                cG = images2[i - 1][j].rgbtGreen + images2[i][j].rgbtGreen + images2[i + 1][j].rgbtGreen + images2[i - 1][j - 1].rgbtGreen +
                     images2[i][j - 1].rgbtGreen + images2[i + 1][j - 1].rgbtGreen;
                cB = images2[i - 1][j].rgbtBlue + images2[i][j].rgbtBlue + images2[i + 1][j].rgbtBlue + images2[i - 1][j - 1].rgbtBlue +
                     images2[i][j - 1].rgbtBlue + images2[i + 1][j - 1].rgbtBlue;
                avgR = (double)(cR / (6 * 1.0));
                avgG = (double)(cG / (6 * 1.0));
                avgB = (double)(cB / (6 * 1.0));
                image[i][j].rgbtRed = (int) round(avgR);
                image[i][j].rgbtGreen = (int) round(avgG);
                image[i][j].rgbtBlue = (int) round(avgB);

            }
            else//middle elements
            {
                cR = images2[i - 1][j - 1].rgbtRed + images2[i - 1][j].rgbtRed + images2[i - 1][j + 1].rgbtRed + images2[i][j - 1].rgbtRed +
                     images2[i][j].rgbtRed + images2[i][j + 1].rgbtRed + images2[i + 1][j - 1].rgbtRed + images2[i + 1][j].rgbtRed + images2[i + 1][j +
                             1].rgbtRed;
                cG = images2[i - 1][j - 1].rgbtGreen + images2[i - 1][j].rgbtGreen + images2[i - 1][j + 1].rgbtGreen + images2[i][j - 1].rgbtGreen + 
                     images2[i][j].rgbtGreen + images2[i][j + 1].rgbtGreen + images2[i + 1][j - 1].rgbtGreen + images2[i + 1][j].rgbtGreen + images2[i +
                             1][j + 1].rgbtGreen;
                cB = images2[i - 1][j - 1].rgbtBlue + images2[i - 1][j].rgbtBlue + images2[i - 1][j + 1].rgbtBlue + images2[i][j - 1].rgbtBlue +
                     images2[i][j].rgbtBlue + images2[i][j + 1].rgbtBlue + images2[i + 1][j - 1].rgbtBlue + images2[i + 1][j].rgbtBlue + images2[i + 1][j
                             + 1].rgbtBlue;
                avgR = (double)(cR / (9 * 1.0));
                avgG = (double)(cG / (9 * 1.0));
                avgB = (double)(cB / (9 * 1.0));
                image[i][j].rgbtRed = (int) round(avgR);
                image[i][j].rgbtGreen = (int) round(avgG);
                image[i][j].rgbtBlue = (int) round(avgB);

            }
        }
    }
    return;
}//end of the program