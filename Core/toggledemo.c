#pragma config(Motor,  port1,           dr,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           stl,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           sbl,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           str,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           sbr,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intakefront,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           intakeback,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           m8,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           m9,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          dl,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 _____                 _      ____
|_   _|__   __ _  __ _| | ___|  _ \  ___ _ __ ___   ___
  | |/ _ \ / _` |/ _` | |/ _ \ | | |/ _ \ '_ ` _ \ / _ \
  | | (_) | (_| | (_| | |  __/ |_| |  __/ | | | | | (_) |
  |_|\___/ \__, |\__, |_|\___|____/ \___|_| |_| |_|\___/
           |___/ |___/

Weston Middle School
*/

task main()	{

	while (true) {

		int shooterButtonToggleState = 0;
		int shooterButtonPressed = 0;

		int shooterSpeed = 127;

		// SHOOTERS
		if( vexRT[ Btn6U ] == 1 )
		{
			if( ! shooterButtonPressed )
			{
				// change the toggle state
				shooterButtonToggleState = 1 - shooterButtonToggleState;

				// Note the button is pressed
				shooterButtonPressed = 1;
			}
		}
		else
		{
			// the button is not pressed
			shooterButtonPressed = 0;
		}

		if (shooterButtonToggleState) {
			motor[stl] = shooterSpeed;
			motor[sbl] = shooterSpeed;
			motor[str] = shooterSpeed;
			motor[sbr] = shooterSpeed;
			} else {
			motor[stl] = 0;
			motor[sbl] = 0;
			motor[str] = 0;
			motor[sbr] = 0;
		}
	}
}