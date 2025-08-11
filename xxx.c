
#include "libft/libft.h"

int main()
{
	char *text;

	text = "abba hello ab i ty ba abb";
	int i = ft_strstr_count(text, "ab");
	ft_printf("%s | %i\n", text, i);
}