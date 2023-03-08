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
