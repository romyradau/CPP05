#include "../incl/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("notarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): AForm(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & sh )
{
	o << "\n" << "******** ShrubberyCreationForm ********" << "\n"
	<< sh.getName() << "\n"
	<< sh.getFormStatus() << "\n"
	<< sh.getSignGrade() << "\n"
	<< sh.getExecGrade() << "\n\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				ShrubberyCreationForm::executeConcreteForm(AForm const & form) const
{
	// std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	// std::cout.rdbuf(shrub.rdbuf()); //redirect std::cout to shrub!
	// // std::string tree;
	// std::cout << 
	std::ofstream shrub (this->_target + "_shrubbery");
	shrub <<
	"###########################'`################################\n"
	 "###########################  V##'############################\n"
	 "#########################V'  `V  ############################\n"
	 "########################V'      ,############################\n"
	 "#########`#############V      ,A###########################V\n"
	 "########' `###########V      ,###########################V',#\n"
	 "######V'   ###########l      ,####################V~~~~'',###\n"
	 "#####V'    ###########l      ##P' ###########V~~'   ,A#######\n"
	 "#####l      d#########l      V'  ,#######V~'       A#########\n"
	 "#####l      ##########l         ,####V''         ,###########\n"
	 "#####l        `V######l        ,###V'   .....;A##############\n"
	 "#####A,         `######A,     ,##V' ,A#######################\n"
	 "#######A,        `######A,    #V'  A########'''''##########''\n"
	 "##########,,,       `####A,           `#''           '''  ,,,\n"
	 "#############A,                               ,,,     ,######\n"
	 "######################oooo,                 ;####, ,#########\n"
	 "##################P'                   A,   ;#####V##########\n"
	 "#####P'    ''''       ,###             `#,     `V############\n"
	 "##P'                ,d###;              ##,       `V#########\n"
	 "##########A,,   #########A              ##,    ##A,..,ooA###\n"
	 "#############A, Y#########A,            ####, ,#############\n"
	 "###############A ############A,        ,###### ##############\n"
	 "###############################       ,#######V##############\n"
	 "###############################      ,#######################\n"
	 "##############################P    ,d########################\n"
	 "##############################'    d#########################\n"
	 "##############################     ##########################\n"
	 "##############################     ##########################\n"
	 "#############################P     ##########################\n"
	 "#############################'     ##########################\n"
	 "############################P      ##########################\n"
	 "###########################P'     ;##########################\n"
	 "###########################'     ,###########################\n"
	 "##########################       ############################\n"
	 "#########################       ,############################\n"
	 "########################        d###########P'    `Y#########\n"
	 "#######################        ,############        #########\n"
	 "######################        ,#############        #########\n"
	 "#####################        ,##############b.    ,d#########\n"
	 "####################        ,################################\n"
	 "###################         #################################\n"
	 "##################          #######################P'  `V##P'\n"
	 "#######P'     `V#           ###################P'\n"
	 "#####P'                    ,#################P'\n"
	 "###P'                      d##############P''\n"
	 "##P'                       V##############'\n"
	 "#P'                         `V###########'\n"
     << std::endl;
	// std::cout.rdbuf(coutbuf);
	// shrub << tree;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string& ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

/* ************************************************************************** */