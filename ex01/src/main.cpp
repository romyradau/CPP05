#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"


int	main()
{

	try{
		Bureaucrat romy("romy", 111);
		// Bureaucrat holly("holly", 151);
		Bureaucrat jolly("jolly", 1);

		std::cout << romy << std::endl;
		// std::cout << holly << std::endl;
		std::cout << jolly << std::endl;
		jolly.decrementGrade();
		std::cout << jolly << std::endl;


	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//woher weiss er, dass er meine exceptionClass nehmen muss??
	return(0);
}