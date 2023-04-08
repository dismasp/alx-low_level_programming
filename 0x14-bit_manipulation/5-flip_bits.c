/**
 * flip_bits - returns the number of bits needed to be flipped to get from
 *             one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits needed to be flipped.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result;
	unsigned int num_bits = 0;

	xor_result = n ^ m;
	while (xor_result > 0)
	{
		if (xor_result & 1)
			num_bits++;
		xor_result >>= 1;
	}

	return (num_bits);
}
/* Written by Dismas*/
