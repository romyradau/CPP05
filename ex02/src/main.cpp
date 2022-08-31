#include "../incl/Bureaucrat.hpp"
#include "../incl/ShrubberyCreationForm.hpp"


int	main()
{

	try{
		Bureaucrat romy("romy", 1);
		Bureaucrat holly("holly", 150);
		ShrubberyCreationForm form1("auslaenderbehoerde");
		holly.signForm(form1);
		romy.signForm(form1);
		romy.decrementGrade();
		holly.incrementGrade();

		std::cout << romy << std::endl;
		std::cout << form1 << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return(0);
}