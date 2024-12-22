unsigned char	reverse_bits(unsigned char octet)
{
	return (((octet >> 7) & 1) << 0) +
			(((octet >> 6) & 1) << 1) +
			(((octet >> 5) & 1) << 2) +
			(((octet >> 4) & 1) << 3) +
			(((octet >> 3) & 1) << 4) +
			(((octet >> 2) & 1) << 5) +
			(((octet >> 1) & 1) << 6) +
			(((octet >> 0) & 1) << 7);
}