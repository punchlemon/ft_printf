test:
	./test.sh

printf:
	cc ft_printf.c -D TEST -o printf

ft_printf:
	cc ft_printf.c -D TEST -D FT_PRINTF -o ft_printf

clean:
	rm printf ft_printf

