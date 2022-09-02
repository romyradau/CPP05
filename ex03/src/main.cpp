#include "../incl/Bureaucrat.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"



int	main()
{

	try{
// 		// ShrubberyCreationForm sh;
		AForm * af = new ShrubberyCreationForm("SexualharrassmentForm");
// 		// std::cout << sh << std::endl;
// 		// std::cout << af << std::endl;
 
		Bureaucrat romy("romy", 1);
// 		Bureaucrat holly("holly", 15);
// 		ShrubberyCreationForm shrub("ChristmasCard");
// 		ShrubberyCreationForm shrubCopy(shrub);
// 		std::cout << shrubCopy << std::endl;
// //works also without getters
// 		RobotomyRequestForm robo;
// 		PresidentialPardonForm	pres("whiteHouse");

// 		holly.signForm(shrub);
// 		romy.signForm(shrub);
// 		romy.signForm(robo);
// 		romy.signForm(pres);

// 		// shrub.execute(holly);
// 		shrub.execute(romy);
// 		holly.executeForm(shrub);
// 		// romy.executeForm(shrub);
// 		// romy.executeForm(robo);
// 		// romy.executeForm(pres);
// 		std::cout << std::endl;
// 		holly.executeForm(pres);
// 		holly.incrementGrade();
// 		holly.executeForm(pres);
// 		std::cout << std::endl;

// 		romy.incrementGrade();
// 		std::cout << romy << std::endl;
// 		std::cout << std::endl;

		Intern someRandomIntern;
		AForm* rrf;
		romy.executeForm(*af);
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		// rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		romy.signForm(*rrf);
		romy.executeForm(*rrf);

		// std::cout << shrub << std::endl;
		// std::cout << robo << std::endl;
		// std::cout << pres << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return(0);
}
