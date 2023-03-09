#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    float R;
    float G;
    float B;
    // select row
    for (int i = 0; i < height; i++)
    {
        // select pixel
        for (int j = 0; j < width; j++)
        {
            R = image[i][j].rgbtRed;
            G = image[i][j].rgbtGreen;
            B = image[i][j].rgbtBlue;

            avg = round((R + G + B) / 3);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sRed;
    int sGreen;
    int sBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sRed > 255)
            {
                sRed = 255;
            }
            if (sGreen > 255)
            {
                sGreen = 255;
            }
            if (sBlue > 255)
            {
                sBlue = 255;
            }

            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int k = width - j - 1;

            tmp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = tmp;
        }
    }

    // long way to do reflect^^
    // int tmpr;
    // int tmpg;
    // int tmpb;

    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width / 2; j++)
    //     {
    //         int k = width - j - 1;
    //         tmpr = image[i][j].rgbtRed;
    //         tmpg = image[i][j].rgbtGreen;
    //         tmpb = image[i][j].rgbtBlue;

    //         image[i][j].rgbtRed = image[i][k].rgbtRed;
    //         image[i][j].rgbtGreen = image[i][k].rgbtGreen;
    //         image[i][j].rgbtBlue = image[i][k].rgbtBlue;

    //         image[i][k].rgbtRed = tmpr;
    //         image[i][k].rgbtGreen = tmpg;
    //         image[i][k].rgbtBlue = tmpb;
    //     }
    // }
    return;
}

// Blur image
// Box blur 9x9 pixels
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pix = 0;
            int avgR;
            int avgG;
            int avgB;

            float R = 0.0;
            float G = 0.0;
            float B = 0.0;

            RGBTRIPLE box[3][3];

            copy[i][j] = image[i][j];

            for (int h = 0; h < 3; h++) //Box height
            {
                for (int w = 0; w < 3; w++) //Box width
                {
                    if ((i - 1 + h >= 0 && j - 1 + w >= 0) || (i + 1 + h <= height && i + 1 + w <= width))
                    {
                        pix++;

                        box[h][w] = copy[i - 1 + h][j - 1 + w];

                        R += box[h][w].rgbtRed;
                        G += box[h][w].rgbtGreen;
                        B += box[h][w].rgbtBlue;
                    }

                }
            }

            // calculate box average
            avgR = round(R / pix);
            avgG = round(G / pix);
            avgB = round(B / pix);

            // set pixel to box average
            image[i][j].rgbtRed = avgR;
            image[i][j].rgbtGreen = avgG;
            image[i][j].rgbtBlue = avgB;
        }
    }
    return;
}
