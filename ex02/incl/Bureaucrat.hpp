#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		std::string			getName()const;
		int					getGrade()const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm & form);
		void				executeForm(AForm const & form);




	private:

		std::string const	_name;
		int					_grade;			

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */