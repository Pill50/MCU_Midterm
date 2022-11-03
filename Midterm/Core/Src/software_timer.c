/*
 * software_timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "main.h"
#include "software_timer.h"

int timer0_counter;
int led7_counter;
int blink_counter;

int timer0_flag = 0;

void setTimer(int duration){
	timer0_counter = duration/TIMER_CYCLE;
	timer0_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}
