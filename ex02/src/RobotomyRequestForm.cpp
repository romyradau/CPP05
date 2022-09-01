#include "../incl/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("notarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}
//warum braucht man hier keinen getter?
std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & robo )
{
	o << "\n" << "******** RobotomyRequestForm ********" << "\n"
	<< robo.getName() << "\n"
	<< robo.getFormStatus() << "\n"
	<< robo.getSignGrade() << "\n"
	<< robo.getExecGrade() << "\n\n";
	return o;
}
void				RobotomyRequestForm::executeConcreteForm(AForm const & form) const
{
	if (arc4random() % 2)
	{
		std::cout << "please visit" << '\n'
		<< "https://www.youtube.com/watch?v=e839iBeupx4&ab_channel=SirawutWongsuya\n"
		<< this->_target << " has been robotomized" << std::endl;
	}
	else
		std::cout << "robotomy failed" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string& RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

/* ************************************************************************** */