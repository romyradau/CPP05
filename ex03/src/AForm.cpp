#include "../incl/AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
AForm::AForm(): _name("emptyAForm"), _sign_grade(75), _exec_grade(75), _signed(false)
{
}

AForm::AForm(std::string name, int sign, int exec): _name(name), _sign_grade(sign), _exec_grade(exec), _signed(false)
{
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	if (_sign_grade <= 0 || _exec_grade <= 0)
		throw GradeTooHighException();
}

AForm::AForm( const AForm & src ): _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _signed(src._signed)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		// this->_name = rhs.getName();
		this->_signed = rhs.getFormStatus();
		// this->_sign_grade = rhs.getSignGrade();
		// this->_exec_grade = rhs.getExecGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & AForm )
{
	o << "\n" << "******** AFORM INFORMATION ********" << "\n"
	<< AForm.getName() << "\n"
	<< AForm.getFormStatus() << "\n"
	<< AForm.getSignGrade() << "\n"
	<< AForm.getExecGrade() << "\n\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is TOO low.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is TOO high.");
}
const char* AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed yet.");
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw FormNotSigned();
	if (executor.getGrade() <= this->_exec_grade)
		executeConcreteForm(*this);
	else
		throw GradeTooLowException();
}

void			AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		AForm::getName()const
{
	return (this->_name);
}

bool			AForm::getFormStatus()const
{
	return (this->_signed);
}

int				AForm::getSignGrade()const
{
	return (this->_sign_grade);
}

int				AForm::getExecGrade()const
{
	return (this->_exec_grade);
}

/* ************************************************************************** */