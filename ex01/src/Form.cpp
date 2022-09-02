#include "../incl/Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Form::Form(): _name("emptyform"), _sign_grade(75), _exec_grade(75), _signed(false)
{
}

Form::Form(std::string name, int sign, int exec): _name(name), _sign_grade(sign), _exec_grade(exec), _signed(false)
{
	if (_sign_grade > 150 || _exec_grade > 150)
	{
		std::cout << "the form's ";
		throw GradeTooLowException();
	}
	if (_sign_grade <= 0 || _exec_grade <= 0)
	{
		std::cout << "the form's ";
		throw GradeTooHighException();
	}
}

Form::Form( const Form & src ): _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _signed(src._signed)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getFormStatus();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & form )
{
	o << "\n" << "******** FORM INFORMATION ********" << "\n"
	<< form.getName() << "\n"
	<< form.getFormStatus() << "\n"
	<< form.getSignGrade() << "\n"
	<< form.getExecGrade() << "\n\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is TOO low.");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is TOO high.");
}

void			Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Form::getName()const
{
	return (this->_name);
}

bool			Form::getFormStatus()const
{
	return (this->_signed);
}

int				Form::getSignGrade()const
{
	return (this->_sign_grade);
}

int				Form::getExecGrade()const
{
	return (this->_exec_grade);
}

/* ************************************************************************** */