#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

void swap(RGBTRIPLE*, RGBTRIPLE*);
// RGBTRIPLE calc_average(RGBTRIPLE**, int, int, int, int);
float edge_compute_new_pixel(int, int);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // a gray color is simply defined as the average of the rgb values
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // for mid index
        float mid = (width - 1) / 2.0;

        // we only go up to mid because we don't want to repeat swaps
        for (int j = 0; j < mid; j++)
        {
            // a number that represents an index that starts from the right (len - 1) and goes to the left (0)
            int last = mid * 2 - j;
            swap(&image[i][j], &image[i][last]);
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // this is a box blur:
    // we compute the new value for a pixel by taking an average of the old colors that surround it (within 1 row and 1 column)
    RGBTRIPLE old[height][width];
    // memcpy(old, image, sizeof(image[0]) * width);

    // let's make a copy of the array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            old[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE average = {0,0,0};

            float red = 0, green = 0, blue = 0;
            int start_row = -1, end_row = 1;
            int start_column = -1, end_column = 1;


            float surrounding_vals = 0;

            for (int sur_row = -1; sur_row < 2; sur_row++)
            {
                for(int sur_column = -1; sur_column  < 2; sur_column++)
                {
                    if (row+sur_row < 0 || row+sur_row >= height)
                    {
                        continue;
                    }
                    if (column+sur_column < 0 || column+sur_column >= width)
                    {
                        continue;
                    }

                    // let's aggregate the surrounding red green and blue
                    red += old[row+sur_row][column+sur_column].rgbtRed;
                    blue += old[row+sur_row][column+sur_column].rgbtBlue;
                    green += old[row+sur_row][column+sur_column].rgbtGreen;
                    surrounding_vals++;
                }
            }

            average.rgbtRed = round(red / surrounding_vals);
            average.rgbtBlue = round(blue / surrounding_vals);
            average.rgbtGreen = round(green / surrounding_vals);

            image[row][column] = average;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // we apply this matrices by multiplying these values for each pixel in the array
    // if the value is very large, then that indicates there is a boundary
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    RGBTRIPLE old[height][width];
    // let's make a copy of the array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            old[i][j] = image[i][j];
        }
    }

    // treat all pixels beyond the border as having a 0 value
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {

            int gx_red = 0, gx_blue = 0, gx_green = 0;
            int gy_red = 0, gy_blue = 0, gy_green = 0;

            // get surrounding pixels
            for (int sur_row = -1; sur_row < 2; sur_row++) {
                for(int sur_column = -1; sur_column  < 2; sur_column++) {
                    if (row+sur_row < 0 || row+sur_row >= height)
                    {
                        continue;
                    }
                    if (column+sur_column < 0 || column+sur_column >= width)
                    {
                        continue;
                    }

                    // apply this matrix and store the values in those variables
                    gx_blue += old[row+sur_row][column+sur_column].rgbtBlue * gx[sur_row+1][sur_column+1];
                    gx_green += old[row+sur_row][column+sur_column].rgbtGreen * gx[sur_row+1][sur_column+1];
                    gx_red += old[row+sur_row][column+sur_column].rgbtRed * gx[sur_row+1][sur_column+1];

                    // also check y-axis
                    gy_blue += old[row+sur_row][column+sur_column].rgbtBlue * gy[sur_row+1][sur_column+1];
                    gy_green += old[row+sur_row][column+sur_column].rgbtGreen * gy[sur_row+1][sur_column+1];
                    gy_red += old[row+sur_row][column+sur_column].rgbtRed * gy[sur_row+1][sur_column+1];
                }
            }

            // let's create the new value
            BYTE new_blue = round(edge_compute_new_pixel(gx_blue, gy_blue));
            BYTE new_green = round(edge_compute_new_pixel(gx_green, gy_green));
            BYTE new_red = round(edge_compute_new_pixel(gx_red, gy_red));

            RGBTRIPLE new_pixel = { new_blue, new_green, new_red };
            image[row][column] = new_pixel;
        }
    }

    return;
}

float edge_compute_new_pixel(int gx_color, int gy_color)
{
    // simply a formula that determines how varied a pixel is (in color) from its surrounding pixels
    float new_val = sqrt(pow(gx_color, 2) + pow(gy_color, 2));

    // let's make sure we don't go over a size of uint_8
    if (new_val > 255.0) { return 255.0; }
    return new_val;
}
