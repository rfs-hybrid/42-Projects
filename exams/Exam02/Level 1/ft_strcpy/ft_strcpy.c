char	*ft_strcpy(char *s1, char *s2)
{
	for (int i = 0; s2[i]; i++)
		s1[i] = s2[i];
	return (s1);
}

// #include <stdio.h>

// int main(void)
// {
// 	char	s[100] = "This is a string!\n";
// 	char	*res = NULL;

// 	printf("%s", s);
// 	printf("%s", res);
// 	printf("\n-----------------------------------------------------\n");
// 	res = ft_strcpy(s, "Welcome to 42 school!\n");
// 	printf("%s", s);
// 	printf("%s", res);
// 	return (0);
// }
