/*
 * output_processing.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "output_processing.h"
#include "global.h"

static uint8_t button_flag[3] = {0,0,0};

void fsm_simple_buttons_run (void){
	switch (status){
		case INIT:
			status = _RESET;
			counter = 0;
			clearLED();
			setLED7Timer(1000);
			break;
		case _RESET:
			// LED7 DISPLAY
			if(LED7_flag == 1) {
				display7SEG(counter);
				setLED7Timer(1000);
			}
			// BUTTON_INC PRESS
			if (is_button_pressed(1)){
				if(button_flag[1] == 0) {
					button_flag[1] = 1;
					counter = (counter + 1) % 10;
					display7SEG(counter);
					status = _INC;
					setTimer(10000);
				}
			} else {
				button_flag[1] = 0;
			}
			// BUTTON_DEC PRESS
			if (is_button_pressed(2)){
				if(button_flag[2] == 0) {
					button_flag[2] = 1;
					counter--;
					if(counter < 0) counter = 9;
					display7SEG(counter);
					status = _DEC;
					setTimer(10000);
				}
			} else {
				button_flag[2] = 0;
			}
			break;
		case _INC:
			// LED7 DISPLAY
			if(LED7_flag == 1) {
				display7SEG(counter);
				setLED7Timer(1000);
			}
			// BUTTON_RESET PRESS
			if (is_button_pressed(0)){
				if(button_flag[0] == 0) {
					button_flag[0] = 1;
					counter = 0;
					display7SEG(counter);
					status = _RESET;
					setTimer(10000);
				}
			} else {
				button_flag[0] = 0;
			}
			// BUTTON_INC PRESS
			if (is_button_pressed(1)){
				// LONG PRESS
				if(is_button_pressed_3s(1)) {
					if(longpress_flag == 1) {
						counter = (counter + 1) % 9;
						display7SEG(counter);
						setLongpressTimer(1000);
					}
				}
				// NORMAL PRESS
				if(button_flag[1] == 0) {
					counter = (counter + 1) % 10;
					display7SEG(counter);
					button_flag[1] = 1;
				}
				setTimer(10000);
			} else {
				button_flag[1] = 0;
			}
			// BUTTON_DEC PRESS
			if (is_button_pressed(2)){
				if(button_flag[2] == 0) {
					button_flag[2] = 1;
					counter--;
					if(counter < 0) counter = 9;
					display7SEG(counter);
					status = _DEC;
					setTimer(10000);
				}
			} else {
				button_flag[2] = 0;
			}
			// SET_TIMER 10S IF DON'T PRESS
			if (timeout_flag == 1){
				status = _AUTO_DEC;
				display7SEG(counter);
				setTimer(1000);
			}
			break;
		case _DEC:
			// LED7 DISPLAY
			if(LED7_flag == 1) {
				display7SEG(counter);
				setLED7Timer(1000);
			}
			// BUTTON_RESET PRESS
			if (is_button_pressed(0)){
				if(button_flag[0] == 0) {
					button_flag[0] = 1;
					counter = 0;
					display7SEG(counter);
					status = _RESET;
					setTimer(10000);
				}
			} else {
				button_flag[0] = 0;
			}
			// BUTTON_INC PRESS
			if (is_button_pressed(1)){
				if(button_flag[1] == 0) {
					button_flag[1] = 1;
					counter = (counter + 1) % 10;
					display7SEG(counter);
					status = _INC;
					setTimer(10000);
				}
			} else {
				button_flag[1] = 0;
			}
			// BUTTON_DEC PRESS
			if (is_button_pressed(2)){
				// LONG PRESS
				if(is_button_pressed_3s(2)) {
					if(longpress_flag == 1) {
						counter--;
						if(counter < 0) counter = 9;
						display7SEG(counter);
						setLongpressTimer(1000);
					}
				}
				// NORMAL PRESS
				if(button_flag[2] == 0) {
					counter--;
					if(counter < 0) counter = 9;
					display7SEG(counter);
					button_flag[2] = 1;
				}
				setTimer(10000);
			} else {
				button_flag[2] = 0;
			}
			// SET_TIMER 10S IF DON'T PRESS
			if (timeout_flag == 1){
				status = _AUTO_DEC;
				display7SEG(counter);
				setTimer(10000);
			}
			break;
		case _AUTO_DEC:
			// LED7 DISPLAY
			if(LED7_flag == 1) {
				counter--;
				if(counter < 0) counter = 0;
				display7SEG(counter);
				setLED7Timer(1000);
			}
			// BUTTON_RESET PRESS
			if (is_button_pressed(0)){
				if(button_flag[0] == 0) {
					button_flag[0] = 1;
					counter = 0;
					display7SEG(counter);
					status = _RESET;
					setTimer(10000);
				}
			} else {
				button_flag[0] = 0;
			}
			// BUTTON_INC PRESS
			if (is_button_pressed(1)){
				if(button_flag[1] == 0) {
					button_flag[1] = 1;
					counter = (counter + 1) % 10;
					display7SEG(counter);
					status = _INC;
					setTimer(10000);
				}
			} else {
				button_flag[1] = 0;
			}
			// BUTTON_DEC PRESS
			if (is_button_pressed(2)){
				if(button_flag[2] == 0) {
					button_flag[2] = 1;
					counter--;
					if(counter < 0) counter = 9;
					display7SEG(counter);
					status = _DEC;
					setTimer(10000);
				}
			} else {
				button_flag[2] = 0;
			}
			if(timeout_flag == 1) {
				setTimer(1000);
			}
			break;
		default:
			status = INIT;
			break;
	}
}

