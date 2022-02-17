/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:10:20 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/02/17 21:11:51 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
# include "ICharacter.hpp"
#include <iostream>

class AMateria
{
	public:
		/* Constructor  */
		AMateria()
		: _type("")
		{
		}
		AMateria(std::string const & type)
		: _type(type)
		{
		}

		/* Destructor */
		virtual ~AMateria()
		{
		}

		/* Copy constructor */
		AMateria(const AMateria &e)
		{
			*this = e;
		}

		/* Operation overload = */
		AMateria& operator = (const AMateria& e)
		{
			this->_type = e._type;
			return *this;
		}

		// Methods
		std::string const & getType() const
		{
			return this->_type;
		}
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target)
		{
			std::cout << this->_type << " used on " << target.getName() << std::endl;
		}
	protected:
		std::string _type;
};

#endif // AMATERIA_HPP