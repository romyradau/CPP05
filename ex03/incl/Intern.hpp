#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		class FormNotFound: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );
		AForm*			makeForm(std::string form_name, std::string target);

	private:
		enum forms{
					SHRUBBERY,
					ROBOTOMY,
					PRESIDENT,
				};
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */