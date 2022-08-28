#include "../incl/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
		if (grade > 150)
			throw GradeTooLowException();

		if (grade <= 0)
			throw GradeTooHighException();
		//Bureaucrat::GradeTooHighException 
		//Bureaucrat::GradeTooLowException
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string		Bureaucrat::getName()const
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

