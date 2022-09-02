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
		RobotomyRequestForm * lifeinsurance = new RobotomyRequestForm;
		RobotomyRequestForm health(*lifeinsurance);

		Bureaucrat romy("romy", 1);
		Bureaucrat holly("holly", 6);
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
		romy.signForm(*lifeinsurance);
		romy.signForm(health);

		// shrub.execute(holly);
		shrub.execute(romy);
		holly.executeForm(shrub);
		// romy.executeForm(shrub);
		// romy.executeForm(robo);
		// romy.executeForm(pres);
		std::cout << std::endl;
		holly.executeForm(pres);
		holly.incrementGrade();
		holly.executeForm(pres);
		std::cout << std::endl;

		romy.incrementGrade();
		std::cout << romy << std::endl;


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
