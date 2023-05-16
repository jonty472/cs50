#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height: %d, width: %d\n", height, width);
    printf("R:%d, G:%d, B:%d\n", image[1]->rgbtRed, image[1]->rgbtGreen, image[1]->rgbtBlue);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtGreen = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtBlue = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            // swap to hold original pixel value to reverse row array
            int swapRed = image[i][j].rgbtRed;
            int swapGreen = image[i][j].rgbtGreen;
            int swapBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j].rgbtRed;
            image[i][width - j].rgbtRed = swapRed;

            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][width - j].rgbtGreen = swapGreen;

            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            image[i][width - j].rgbtBlue = swapBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // testing to see if i've copied over the image correctly
    printf("R:%d, G:%d, B:%d\n", copy[1]->rgbtRed, copy[1]->rgbtGreen, copy[1]->rgbtBlue);
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redBlur = 0;
            int greenBlur = 0;
            int blueBlur = 0;
            for (int k = -1; k <= 1; k++)
            {
                redBlur += copy[i-k][j-k].rgbtRed;
                greenBlur += copy[i-k][j-k].rgbtGreen;
                blueBlur += copy[i-k][j-k].rgbtBlue;
            }
            image[i][j].rgbtRed = redBlur / 3;
            image[i][j].rgbtGreen = greenBlur / 3;
            image[i][j].rgbtBlue = blueBlur / 3;
        }
    }
    return;
}