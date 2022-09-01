#include "../incl/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
PresidentialPardonForm::PresidentialPardonForm(): AForm("ShrubberyCreationForm", 145, 137), _target("notarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ): AForm(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm Destructor" << std::endl;
}
//warum wird das zwischen die exception gethrowt?


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & sh )
{
	o << "\n" << "******** PresidentialPardonForm ********" << "\n"
	<< sh.getName() << "\n"
	<< sh.getFormStatus() << "\n"
	<< sh.getSignGrade() << "\n"
	<< sh.getExecGrade() << "\n\n";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				PresidentialPardonForm::executeConcreteForm(AForm const & form) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string& PresidentialPardonForm::getTarget()
{
	return (this->_target);
}
/* ************************************************************************** */