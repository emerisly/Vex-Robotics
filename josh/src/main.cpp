/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Emerald Liu                                      */
/*    Created:      Wed Jan 15 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  vex::brain Brain;
vex::motor LeftMotor(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor RightMotor (vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::controller Controller1 = vex::controller();
 while (true) {          
        LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        RightMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        ArmMotorR.setVelocity(200,pct);
        ArmMotorL.setVelocity(100,pct);
  if (Controller1.ButtonRight.pressing()) {
      ArmMotorR.spin(forward);
      ArmMotorL.spin(forward);
      
    } else if (Controller1.ButtonLeft.pressing()) {
      ArmMotorR.spin(reverse);
      ArmMotorL.spin(reverse);
    }   
    else{
      ArmMotorR.stop();
      ArmMotorL.stop();
    }
    if (Controller1.ButtonX.pressing()){
      Stacker.spin(forward);
    }
    else if(Controller1.ButtonB.pressing()){
      Stacker.spin(reverse);
    }
    else{
      Stacker.stop();
    }
    if(Controller1.ButtonR2.pressing()){
      IntakeR.spin(forward);
      IntakeL.spin(forward);
    }
    else if(Controller1.ButtonR1.pressing()){
      IntakeR.spin(reverse);
      IntakeL.spin(reverse);
    }
    else{
      IntakeL.stop();
      IntakeR.stop();
    }
    
    }
        task::sleep(20);
}
