
#include "libft/libft.h"

int main()
{
	char *text;

	text = ft_strdup("abba hello ab i ty ba abb");
	ft_delpattern(&text, "ab");
	ft_printf("%s", text);
}