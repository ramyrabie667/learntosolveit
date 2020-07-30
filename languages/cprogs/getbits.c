/*
I copied and pasted from this source:
http://www.iso-9899.info/wiki/Code_snippets:getbits
*/
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    /* Build a mask consisting of 'n' bits */
    
    /* ...111 */
    int all_ones = ~0;

    /* ...111000 */
    int all_ones_shifted_left = all_ones << n;

    /* ...000111 */
    int mask = ~all_ones_shifted_left;

    /* Shift 'x' down to discard lower bits we don't care about */
    /* How many bits do we discard? */
    int shift_down = p + 1 - n;

    /* ...76543210 -> ...765432 */
    unsigned int x_shifted_down = x >> shift_down;

    /* Use the mask to discard the upper bits we don't care about */
    return x_shifted_down & mask;
}

int main(void)
{
    /* Decimal 8 is binary 1000 */
    unsigned x = 8;
    /* Position 4 starts at ...[43210 */
    int p = 4;
    /* 3 bits means the range is ...[432]10 */
    int n = 3;

    printf("%d", getbits(x, p, n));
    return 0;
}
