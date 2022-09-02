#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"


int	main()
{

	try{
		Bureaucrat romy("romy", 1);
		Bureaucrat holly("holly", 150);
		Form form1("auslanderbehoerde", 51, 50);
		// form1.beSigned(holly);
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