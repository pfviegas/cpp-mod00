/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:10:04 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/05 16:31:07 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contacts.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void  Contact::Save_FirstName(str First_Name)
{
	trimString(First_Name);
	this->First_Name = First_Name;
}

void  Contact::Save_LastName(str Last_Name)
{
	trimString(Last_Name);
	this->Last_Name = Last_Name;
}

void  Contact::Save_Nickname(str Nickname)
{
	trimString(Nickname);
	this->Nickname = Nickname;
}

void  Contact::Save_PhoneNum(str Phone_Num)
{
	trimString(Phone_Num);
	this->Phone_Num = Phone_Num;
}

void  Contact::Save_Secret(str Secret)
{
	trimString(Secret);
	this->Secret = Secret;
}

str		Contact::Get_Data(str info)
{
	if (!info.compare("First"))
		return (First_Name);
	if (!info.compare("Last"))
		return (Last_Name);
	if (!info.compare("Nick"))
		return (Nickname);
	return (NULL);
}

bool	Contact::Check_Empty()
{
	if (First_Name.empty())
		return (false);
	if (Last_Name.empty())
		return (false);
	if (Nickname.empty())
		return (false);
	if (Phone_Num.empty())
		return (false);
	if (Secret.empty())
		return (false);
	return (true);
}

void	Contact::Print_Contact() 
{
	str input;

	while (input.compare("DONE") != 0)
	{
		system("clear");
		std::cout << GREEN << "First Name: " << RESET << this->First_Name << std::endl;
		std::cout << GREEN << "Last Name: " << RESET << this->Last_Name << std::endl;
		std::cout << GREEN << "Nickame: " << RESET << this->Nickname << std::endl;
		std::cout << GREEN << "Phone Num: " << RESET << this->Phone_Num << std::endl;
		std::cout << GREEN << "Secret: " << RESET << this->Secret << std::endl;

		std::cout << "\nType " << GREEN << "DONE" << RESET << " to back to menu.\n\n$ ";
		getline(std::cin, input);
		// verifica se o utilizador fez ctrl+d
		if (std::cin.eof())
		{
			input = "DONE";
			break;
		}

	}
}

// Função para eliminar espaços e tabulações no início e no final da string
void	trimString(str& str)
{
	// Eliminar espaços e tabulações no início da string
	size_t start = str.find_first_not_of(" \t");
	
	if (start != std::string::npos)
		str = str.substr(start);

	// Eliminar espaços e tabulações no final da string
	size_t end = str.find_last_not_of(" \t");
	if (end != std::string::npos)
		str = str.substr(0, end + 1);
}