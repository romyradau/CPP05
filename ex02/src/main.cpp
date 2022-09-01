#include "../incl/Bureaucrat.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"



int	main()
{

	try{
		// ShrubberyCreationForm sh;
		// AForm af("SexualharrassmentForm", 111, 99);
		// std::cout << sh << std::endl;
		// std::cout << af << std::endl;
 
		Bureaucrat romy("romy", 2);
		Bureaucrat holly("holly", 150);
		ShrubberyCreationForm shrub("ChristmasCard");
		ShrubberyCreationForm shrubCopy(shrub);
		std::cout << shrubCopy << std::endl;
//works also without getters
		RobotomyRequestForm robo;
		PresidentialPardonForm	pres("whiteHouse");

		holly.signForm(shrub);
		romy.signForm(shrub);
		romy.signForm(robo);
		romy.signForm(pres);

		// shrub.execute(holly);
		shrub.execute(romy);
		holly.executeForm(shrub);
		romy.executeForm(shrub);
		romy.executeForm(robo);
		romy.executeForm(pres);

		romy.incrementGrade();
		std::cout << romy << std::endl;

		holly.decrementGrade();

		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pres << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return(0);
}
//try and catch in den functions  = mai code lauft weiter
//tya nd catch in main = code hoert auf
//warum braucht man hier keinen getter?(Robotomyoperator=)
//weils selbst ein robotomy ist
