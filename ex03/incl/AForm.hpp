#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
#include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		class FormNotSigned: public std::exception
		{
			public:
				const char* what() const throw();
		};
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		void				execute(Bureaucrat const & executor) const;
		virtual void		executeConcreteForm(AForm const & form) const  = 0;
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

std::ostream &			operator<<( std::ostream & o, AForm const & AForm );

#endif /* ************************************************************ AForm_H */