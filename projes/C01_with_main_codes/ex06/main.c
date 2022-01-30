#include <stdio.h>

int		ft_strlen(char *str);

int		main(void)
{
	char *str;

	str = "Il y a 20 caracteres";
	printf("Retour (20): %d\n", ft_strlen(str));
}
