#include <stdio.h>
#include <string.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	return (1);
	while(str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		i++;
		else
			return (0);
	}
	return (1);
}
//Bu arada \n -->new line, \t --> tab, \v --> vertical tab, \f --> fromfeed yani direktly alt satıra geçiyoruz. 
int	main(void)
{
    printf("%d", ft_str_is_printable("dsbdfbsb\n\t\v\f\0nnnnnnn"));//tırnak içindeki "\0" ifadeye geldiğinde program çalışmayı durduruyor unutma!
}

