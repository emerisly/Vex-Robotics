#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightB = motor(PORT20, ratio18_1, false);
motor LeftB = motor(PORT12, ratio18_1, false);
controller Controller1 = controller(primary);
motor ArmR = motor(PORT9, ratio18_1, false);
motor ArmL = motor(PORT2, ratio18_1, false);
motor IntakeR = motor(PORT10, ratio18_1, false);
motor IntakeL = motor(PORT1, ratio18_1, false);
motor Stacker = motor(PORT19, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}