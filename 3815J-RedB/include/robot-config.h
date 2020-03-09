using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RightB;
extern motor LeftB;
extern controller Controller1;
extern motor ArmR;
extern motor ArmL;
extern motor IntakeR;
extern motor IntakeL;
extern motor Stacker;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );