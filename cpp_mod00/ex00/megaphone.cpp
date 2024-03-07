/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:10:29 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/06 10:46:12 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv) 
{
	int	i;
	int	j;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
