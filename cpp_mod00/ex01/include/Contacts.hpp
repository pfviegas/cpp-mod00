/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:30:31 by paulo             #+#    #+#             */
/*   Updated: 2024/03/05 16:24:47 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>

#define GREEN "\033[32;1m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

typedef std::string	str;

class Contact
{
	private:
		str			First_Name;
		str			Last_Name;
		str			Nickname;
		str			Phone_Num;
		str			Secret;

	public:
		void		Save_FirstName(str First_Name);
		void		Save_LastName(str Last_Name);
		void		Save_Nickname(str Nickname);
		void		Save_PhoneNum(str PhoneNum);
		void		Save_Secret(str Secret);
		void		Print_Contact();
		str			Get_Data(str info);
		bool		Check_Empty();
		
		Contact();
		~Contact();
};

void	trimString(str& str);

#endif
