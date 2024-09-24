#include "../Lib/Duck/DecoyDuck.h"
#include "../Lib/Duck/MallardDuck.h"
#include "../Lib/Duck/ModelDuck.h"
#include "../Lib/Duck/RedheadDuck.h"
#include "../Lib/Duck/RubberDuck.h"
#include "../Lib/DuckFunctions.h"
#include <cstdlib>

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(CreateFlyWithWings());
	PlayWithDuck(modelDuck);

	return EXIT_SUCCESS;
}