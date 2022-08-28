#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw() 
				{
					return ("Grade is too high.");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too low.");
				}
		};
		Bureaucrat(std::string const name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		std::string	getName()const;
		int			getGrade()const;
		void				incrementGrade();
		void				decrementGrade();


	private:

		std::string const	_name;
		int					_grade;			

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */