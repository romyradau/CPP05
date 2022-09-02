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
		{
			std::cout << this->_name << "'s ";
			throw GradeTooLowException();
		}
		if (grade <= 0)
		{
			std::cout << this->_name << "'s ";
			throw GradeTooHighException();
		}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
}
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

void				Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		std::cout << this->_name << "'s ";
		throw GradeTooLowException();
	}
}
void				Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade == 0)
	{
		std::cout << this->_name << "'s ";
		throw GradeTooHighException();
	}
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
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




