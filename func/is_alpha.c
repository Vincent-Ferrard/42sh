/*
** EPITECH PROJECT, 2017
** is_alpha.c
** File description:
** check
*/

int int_is_alpha(int ch)
{
	if ((ch <= 90 && ch >= 65) || (ch >= 87 && ch <= 122))
		return (1);
	return (0);
}

int is_alpha(char c)
{
	if (31 < c)
		return (1);
	return (0);
}

int is_alpha_str(char const *str)
{
	int temp = 0;
	int temp2 = 0;

	for (int i = 0; str[i] != 0; i = i + 1) {
		temp = ('0' <= str[i] && str[i] <= '9');
		temp2 = ('A' <= str[i] && str[i] <= 'Z');
		if (!temp && !temp2 && !('a' <= str[i] && str[i] <= 'z'))
			return (0);
	}
	return (1);
}
