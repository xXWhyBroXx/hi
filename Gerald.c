#pragma config(Sensor, in1,    L,             sensorNone)
#pragma config(Sensor, in3,    M,             sensorNone)
#pragma config(Sensor, in4,    R,             sensorNone)
#pragma config(Sensor, dgtl1,  PWD,            sensorTouch)
#pragma config(Sensor, dgtl2,  fingr,          sensorTouch)
#pragma config(Sensor, dgtl3,  fingr2,         sensorTouch)
#pragma config(Motor,  port2,           RM,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LM,            tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int pwd = 0;
int botton = 0;
int boredom = 0;
int Num = 0;



void Face() {
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, "O ^ O");
	// displayLCDCenteredString(1, "    ");
	sleep(1000);
	displayLCDCenteredString(0, "- ^ -");
	// displayLCDCenteredString(1, "    ");
	sleep (1000);
}

void Startup() {
	bLCDBacklight = 1;
	displayLCDCenteredString(0, "O < O");
	displayLCDCenteredString(1, "Hi im Gerald");
	sleep(2000);
	clearLCDLine(1);
	displayLCDCenteredString(1, "Im smart!");
	sleep(2000);

}
void GameOver() {
	displayLCDCenteredString(0, "O < O");
	displayLCDCenteredString(1, "WHY FATHER");
	sleep(2000);
	clearLCDLine(1);
	displayLCDCenteredString(1, "DONT DO THI-");
	sleep(2000);
	motor[LM] = 0;
	motor[RM] = 0;


}

void Touch() {
	if((SensorValue(fingr) == 1)||(SensorValue(fingr2) == 1)){
		Num++;
		sleep(1000);
		return;
	}
}

void HardC() {
	if(Num == 0){

		motor(LM) = 100
		motor(RM) = 100
	}
	if( Num == 1) {
		motor(LM) = 0; motor(RM) = 0;
		Num++;
	}
	if(Num == 2){

}
}

void GameOn() {
	if(botton == 1){
		pwd = 0;
	}


}

void ColorSense() {





}

void PowerOff() {
	botton = 0;
	while(SensorValue(PWD) == 1){
		botton++;
		displayLCDNumber(1, 7, botton);
		sleep(400);

	}
}
void options() {
	if(botton == 1){
		pwd++;
	}
	if(boredom == 10){
		displayLCDCenteredString(0, "- M -");
		displayLCDCenteredString(1, "This is boring");
		sleep(2000);
		clearLCDLine(1);
		displayLCDCenteredString(1, "Lets do somethin");
		sleep(2000);
		boredom = 0;
	}
	if(botton == 3){
		displayLCDCenteredString(0, "O 3~O <3");
		displayLCDCenteredString(1, "Mwah");
		sleep(2000);
		clearLCDLine(1);
		displayLCDCenteredString(1, "I luv u");
		sleep(2000);
	}
	if(botton == 4) {
		displayLCDCenteredString(0, "O < O");
		displayLCDCenteredString(1, "Yipppe");
		motor[LM] = 50;false;
		motor[RM] = -50;
		sleep(2000);
		motor[LM] = -50;false;
		motor[RM] = 50;
		sleep(2000);
		motor[LM] = 0;false;
		motor[RM] = 0;
	}

}



























task main()
{ 	while (1==1){
		Startup();
		Touch();
		while(pwd == 0){
			//Touch(); false;
			HardC(); false;
			Face(); false;
			PowerOff();
			options(); false;
			// ColorSense();
			boredom++; false;
		}
		GameOver();false;
		while(pwd == 1){
			clearLCDLine(0);
			clearLCDLine(1);
			PowerOff();
			bLCDBacklight = 0;
			GameOn();
		}
	}
}
