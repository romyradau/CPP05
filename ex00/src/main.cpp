#include "../incl/Bureaucrat.hpp"

int	main()
{

	try{
		Bureaucrat romy("romy", 151);
		Bureaucrat holly("holly", 150);
		Bureaucrat jolly("jolly", 1);

		// std::cout << romy << std::endl;
		std::cout << jolly << std::endl;
		jolly.incrementGrade();
		Bureaucrat olly(jolly);
		std::cout << jolly << std::endl;
		std::cout << olly << std::endl;


	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//how does the program recognize my special execption calss and stores it in there?
	return(0);
}