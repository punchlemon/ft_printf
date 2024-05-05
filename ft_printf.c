/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:15:53 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/06 06:43:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(char *dst, const char *src, size_t n)
{
	int	i;
	int	dif;
	int	end;

	if (src > dst)
	{
		i = 0;
		dif = 1;
		end = n;
	}
	else
	{
		i = n;
		dif = -1;
		end = -1;
	}
	while (i != end)
	{
		dst[i] = src[i];
		i += dif;
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (i < j)
			return ((size_t)(-1));
		j = i;
		i++;
	}
	return (i);
}

char	*concatenate_char(char *s1, char c)
{
	char	*result;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if ((((size_t)(-1) - s1_len) <= 1) || (c == '\0'))
		return (NULL);
	if (c == '\0')
		return (s1);
	result = (char *)malloc((s1_len + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_memmove(result, s1, s1_len);
		free(s1);
	}
	result[s1_len] = c;
	result[s1_len + 1] = '\0';
	return (result);
}

char	*concatenate_str(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	result_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result_len = s1_len + s2_len;
	if (((size_t)(-1) - s1_len <= s2_len) || (result_len == 0))
		return (NULL);
	result = (char *)malloc((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_memmove(result, s1, s1_len);
		free(s1);
	}
	ft_memmove(result + s1_len, s2, s2_len);
	result[result_len] = '\0';
	return (result);
}

char	convert_x(char c, int flag)
{
	if (0 <= c && c <= 9)
		return (c + '0');
	if (10 <= c && c <= 15)
	{
		if (flag == 0)
			return (c + 'a' - 10);
		else
			return (c + 'A' - 10);
	}
	return (0);
}

char	*convert_pointer(void *p)
{
	size_t	i;
	size_t	p_len;
	char	*result;

	p_len = sizeof(p);
	result = (char *)malloc((p_len + 3) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	i = 0;
	while (i < p_len)
	{
		result[i + 2] = convert_x(((unsigned long long)p >> (p_len - i)) & 0xf, 0);
		i++;
	}
	result[i + 2] = '\0';
	return (result);
}

void	convert_variable(char **str, const char c, va_list args)
{
	if (c == '%')
		*str = concatenate_char(*str, '%');
	else if (c == 'c')
		*str = concatenate_char(*str, (char)va_arg(args, int));
	else if (c == 's')
		*str = concatenate_str(*str, va_arg(args, char *));
	else if (c == 'p')
		*str = concatenate_str(*str, convert_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		*str = concatenate_str(*str, convert_number(va_arg(args, int), 10, 0, 0));
	else if (c == 'u')
		*str = concatenate_str(*str, convert_number(va_arg(args, int), 10, 1, 0));
	else if (c == 'o')
		*str = concatenate_str(*str, convert_number(va_arg(args, int), 8, 1, 0));
	else if (c == 'x')
		*str = concatenate_str(*str, convert_number(va_arg(args, int), 16, 1, 0));
	else if (c == 'X')
		*str = concatenate_str(*str, convert_number(va_arg(args, int), 16, 1, 1));
}

char	*generate_result(const char* source, va_list args)
{
	int	i;
	char	*result;

	if (source == NULL)
		return (NULL);
	result = NULL;
	i = 0;
	while (source[i] != '\0')
	{
		if (source[i] == '%')
		{
			i++;
			convert_variable(&result, source[i], args);
		}
		else
			result = concatenate_char(result, source[i]);
		i++;
	}
	return (result);
}

size_t	ft_putstr(char *s)
{
	size_t	s_len;

	if (s == NULL || ft_strlen(s) == 0)
		write(1, "error\n", 6);
	s_len = ft_strlen(s);
	write(1, s, s_len);
	return (s_len);
}

int	ft_printf(const char* source, ...)
{
	va_list	args;
	char	*result;
	size_t	result_len;

	va_start(args, source);
	result = generate_result(source, args);
	result_len = ft_putstr(result);
	free(result);
	va_end(args);
	return (result_len);
}

int	main(void)
{
	ft_printf("test1\n");
	ft_printf("test2%c", '\n');
	ft_printf("test%s", "3\n");
	ft_printf("test4:%p\n", "hello");
	ft_printf("test5:%p\n", "world");
	ft_printf("test6:%p\n", "!!!!!");
	ft_printf("test7:%p\n", NULL);
	void *p = malloc(1);
	ft_printf("test8:%p\n", p);
	free(p);
}
