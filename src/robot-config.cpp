#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
motor LeftDrive = motor(PORT1, ratio18_1, false);
motor RightDrive = motor(PORT2, ratio18_1, true);
motor Storage = motor(PORT3, ratio18_1, false);
motor Intake = motor(PORT4, ratio18_1, false);

controller Controller = controller(primary);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
