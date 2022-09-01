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

void			Bureaucrat::signForm(AForm& form)
{
	try
	{
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " - " << e.what() << '\n';
	}
}
void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() << " - " << e.what() << '\n';
	}
	
}
//executeForm(Form const & form)
//hier sowas wie die signForm function
//form.execute
//ah das beendet das Programm jetzt nicht direkt?
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

