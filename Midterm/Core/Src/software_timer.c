/*
 * software_timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "main.h"
#include "software_timer.h"

int timeout_counter;
int blink_counter;
int LED7_counter;
int longpress_counter;

int timeout_flag = 0;
int blink_flag = 0;
int longpress_flag = 0;
int LED7_flag = 0;

void setTimer(int duration){
	timeout_counter = duration/TIMER_CYCLE;
	timeout_flag = 0;
}

void setBlinkLedTimer(int duration){
	blink_counter = duration/TIMER_CYCLE;
	blink_flag = 0;
}

void setLongpressTimer(int duration){
	longpress_counter = duration/TIMER_CYCLE;
	longpress_flag = 0;
}

void setLED7Timer(int duration){
	LED7_counter = duration/TIMER_CYCLE;
	LED7_flag = 0;
}


void timer_run(){
	if (timeout_counter > 0){
		timeout_counter--;
		if (timeout_counter == 0) timeout_flag = 1;
	}
	if (blink_counter > 0){
		blink_counter--;
		if (blink_counter == 0) blink_flag = 1;
	}
	if (longpress_counter > 0){
		longpress_counter--;
		if (longpress_counter == 0) longpress_flag = 1;
	}
	if (LED7_counter > 0){
		LED7_counter--;
		if (LED7_counter == 0) LED7_flag = 1;
	}
}
