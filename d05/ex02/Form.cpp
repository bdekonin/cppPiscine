/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:15:19 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/03/23 17:49:46 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructors */
Form::Form()
: _name("Form"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
	std::cout << "[Form] " << _name << " is Default constructed" << std::endl;
	return ;
}
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "[Form] " << _name << " is constructed" << std::endl;
	return ;
}

/* Destructor */
Form::~Form()
{
	std::cout << "[Form] " << _name << " is destructed" << std::endl;
	return ;
}

/* Copy constructor */
Form::Form(const Form& e)
: _name(e._name), _signed(e._signed), _gradeToSign(e._gradeToSign), _gradeToExecute(e._gradeToExecute)
{
	std::cout << "[Form] " << _name << " is copied" << std::endl;
	return ;
}

/* Operation overload = */
Form& Form::operator = (const Form& e)
{
	std::cout << "[Form] " << _name << " is assigned" << std::endl;
	if (this != &e)
		this->_signed = e._signed;
	return (*this);
}

/* Methods */
std::string Form::getName() const
{
	return (this->_name);
}
bool		Form::getSigned() const
{
	return (this->_signed);
}
int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}
int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
void Form::beSigned(Bureaucrat &b)
{
	if(b.getGrade() < this->_gradeToSign)
	{
		std::cout << "[Form] " << this->getName() << " is signed by " << b.getName() << std::endl;
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}
void	Form::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooHighException();
	else
		std::cout << "Executed " << this->getName() << std::endl;
}

/* Exceptions */
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
const char* Form::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

/* Operation Overload << */
std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGradeToSign();
	return o;
}

