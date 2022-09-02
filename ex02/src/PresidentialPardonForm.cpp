#include "../incl/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("notarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target): AForm("PresidentialPardonForm", 25, 5), _target(target)
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
//why would that message show up between the exception message??


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