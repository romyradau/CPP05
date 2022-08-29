#include "../incl/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name("noname"), _grade(75)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
		if (grade > 150)
			throw GradeTooLowException();
			// throw std::out_of_range("toolow");

		if (grade <= 0)
			throw GradeTooHighException();
		//Bureaucrat::GradeTooHighException 
		//Bureaucrat::GradeTooLowException
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src._name), _grade(src._grade)
{
	// *this = src;
}
//heir noch checken ob auch wirklich 0 151 gecatcht wird
//ohne dass man haendisch etwas zuweist

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		// this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Bureaucrat::incrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	//Bureaucrat::GradeTooHighException 
	//Bureaucrat::GradeTooLowException

}
void				Bureaucrat::decrementGrade()
{
	this->_grade--;
	if (this->_grade == 0)
		throw GradeTooHighException();
	//Bureaucrat::GradeTooHighException 
	//Bureaucrat::GradeTooLowException
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

void			Bureaucrat::signForm(Form const & form)
{
	if (form.getFormStatus())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else	
		std::cout << this->_name << " couldn't sign " << form.getName() << " because of insufficient rank." << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	Bureaucrat::getName()const
{
	return (this->_name);
}

int				Bureaucrat::getGrade()const
{
	return (this->_grade);
}


/* 
wenn die Klasse, die eine Function benutzt const ist, muss die function auch const sein

************************************************************************** 
*/

