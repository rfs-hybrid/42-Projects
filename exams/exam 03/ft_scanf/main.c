/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:08:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/31 14:59:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int decimal;
	unsigned int hex;
	char str[100];
	char ch;

	printf("Enter a decimal, a hex, a string, and a character:\n");
	printf("Example input: 42 0x2A Hello X\n");

	int count = ft_scanf("%d %x %s %c", &decimal, &hex, str, &ch);

	printf("\nYou entered:\n");
	printf("Decimal     : %d\n", decimal);
	printf("Hexadecimal : %u (0x%x)\n", hex, hex); // shows both unsigned and hex
	printf("String      : %s\n", str);
	printf("Character   : %c\n", ch);
	printf("Parsed count: %d\n", count);

	return 0;
}
