/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to search for bit
 * @index: the index, starting from 0 of the bit you want to get
 *
 * Return: the value of the bit at index index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Get the bit at the bit at the given index */
	return ((n >> index) & 1);
	/* Written by <Dismas> */
}
