#include "../incl/Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm*			Intern::makeForm(std::string form_name, std::string target)
{
	int	form_num = -1;

	std::string forms[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form_name)
			form_num = i;
	}
	switch (form_num)
	{
		case SHRUBBERY:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new RobotomyRequestForm(target));
		case PRESIDENT:
			std::cout << "Intern creates " << form_name << std::endl;
			return(new PresidentialPardonForm(target));
		default:
			std::cout << "Intern gets very nervous ... he never heard of " << form_name << std::endl;
			throw FormNotFound();
	}
}

const char* Intern::FormNotFound::what() const throw()
{
	return ("Form not found.");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */