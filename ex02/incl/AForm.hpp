#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
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
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm( AForm const & src );
		~AForm();

		AForm &		operator=( AForm const & rhs );

		void				execute(Bureaucrat const & executor) const;
		//die vielleicht absolute virtual machen?
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