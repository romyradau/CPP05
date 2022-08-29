#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form();
		Form(std::string name, int sign, int exec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void				beSigned(Bureaucrat const & b);
		std::string			getName()const;
		bool				getFormStatus()const;
		int					getSignGrade()const;
		int					getExecGrade()const;

	private:

		std::string const	_name;
		bool				_signed;
		int const			_sign_grade;
		int const			_exec_grade;


};

std::ostream &			operator<<( std::ostream & o, Form const & form );

#endif /* ************************************************************ FORM_H */