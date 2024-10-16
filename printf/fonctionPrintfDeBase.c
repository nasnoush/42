
int	ft_printf(const char *format, ...)
{
	int		i;
	int		nbr_char;
	va_list	args;

	va_start (args, format);
	i = 0;
	nbr_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				nbr_char += ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
				nbr_char += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'p')
				nbr_char += ft_putpointer(va_arg(args, void *));
			else if (format[i] == 'd')
				nbr_char += ft_putnbr(va_arg(args, int));
			else if (format[i] == 'i')
				nbr_char += ft_putnbr(va_arg(args, int));
			else if (format[i] == 'u')
				nbr_char += ft_putnbr(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				nbr_char += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
			else if (format[i] == 'X')
				nbr_char += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
			else if (format[i] == '%')
				nbr_char += ft_putchar('%');
		}
		else
		{
			nbr_char += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (nbr_char);
}