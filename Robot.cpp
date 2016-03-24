
#include "Robot.h"
#include "StupidAlgorithm.h"


Robot::Robot(struct ConfigInfo &config, House &house)
{
	algo = new StupidAlgorithm(house, *this);
}
struct stepData Robot::step(bool is_winner, int steps_left)
{

}