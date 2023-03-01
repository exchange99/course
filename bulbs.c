#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string mes = get_string("Message: ");

    for (int i = 0, len = strlen(mes); i < len; i++)
    {

        int ascii = mes[i];     // Set ascii to value of the char
        int bin[] = {0, 0, 0, 0, 0, 0, 0, 0};   // Create an int array
        int j = 0;

        // Repeat modulo 2 until nothing remains
        while (ascii > 0)
        {
            bin[j] = ascii % 2;
            ascii = ascii / 2;
            j++;
        }

        // repeat print_bulb() for every char in the message
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bin[k]);
        }
        printf("\n");
    }


}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
