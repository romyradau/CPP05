#include "../incl/Bureaucrat.hpp"

int	main()
{

	try{
		Bureaucrat romy("romy", 111);
		Bureaucrat holly("holly", 151);

		std::cout << romy << std::endl;
		std::cout << holly << std::endl;


	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//woher weiss er, dass er meine exception nehmen muss??
	return(0);
}