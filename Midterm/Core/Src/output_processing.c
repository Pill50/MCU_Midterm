/*
 * output_processing.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "output_processing.h"

enum MODE { MODE_1 , MODE_2 , MODE_3 , MODE_4 } ;
enum MODE Mode = MODE_1;

static uint8_t buttonflag0, buttonflag1, buttonflag2;

int init = 0;
void fsm_for_output_processing (void){
	switch (Mode){
	case MODE_1:
		// BUTTON_0 PRESS
		if (is_button_pressed(0) == 1){
			if(buttonflag0 == 0) {
				buttonflag0 = 1;
				Mode = MODE_2;
				setTimer(1000);
			}
		} else {
			buttonflag0 = 0;
		}
		// SET_TIMER 1S IF DONT PRESS AND INIT LED_TRAFFIC
		if (timer0_flag == 1){
			if(init == 0) {
				// turn off all led
				init = 1;
			}
			setTimer(1000);
		}
		break;
	case MODE_2:
		// BUTTON_1 PRESS
		if (is_button_pressed(0)){
			if(buttonflag0 == 0) {
				buttonflag0 = 1;
				Mode = MODE_3;
				setTimer(1000);
			}
		} else {
			buttonflag0 = 0;
		}
		// BUTTON_1 PRESS
		if (is_button_pressed(1)){
			if(is_button_pressed_1s(1)) {

			}
			if(buttonflag1 == 0) {

			}
		} else buttonflag1 = 0;
		// BUTTON_2 PRESS
		if (is_button_pressed(2)){
			if(is_button_pressed_1s(2)) {

			}
			if(buttonflag2 == 0) {
				buttonflag2 = 1;

			}
		} else {
			buttonflag2 = 0;
		}
		// SET_TIMER 1S IF DONT PRESS
		if (timer0_flag == 1){
			setTimer(1000);
		}
		break;
	case MODE_3:
		// BUTTON_0 PRESS
		if (is_button_pressed(0)){
			if(buttonflag0 == 0) {
				buttonflag0 = 1;
				Mode = MODE_4;
				setTimer(1000);
			}
		} else {
			buttonflag0 = 0;
		}
		// BUTTON_1 PRESS
		if (is_button_pressed(1)){
			if(is_button_pressed_1s(1)) {

			}
			if(buttonflag1 == 0) {

			}
		} else buttonflag1 = 0;
		// BUTTON_2 PRESS
		if (is_button_pressed(2)){
			if(is_button_pressed_1s(2)) {

			}
			if(buttonflag2 == 0) {
				buttonflag2 = 1;

			}
		} else {
			buttonflag2 = 0;
		}
		// SET_TIMER 1S IF DONT PRESS
		if (timer0_flag == 1){
			setTimer(1000);
		}
		break;
	case MODE_4:
		// BUTTON_0 PRESS
		if (is_button_pressed(0)){
			if(buttonflag0 == 0) {
				buttonflag0 = 1;
				Mode = MODE_1;
				setTimer(1000);
			}
		} else {
			buttonflag0 = 0;
		}
		// BUTTON_1 PRESS
		if (is_button_pressed(1)){
			if(is_button_pressed_1s(1)) {

			}
			if(buttonflag1 == 0) {

			}
		} else buttonflag1 = 0;
		// BUTTON_2 PRESS
		if (is_button_pressed(2)){
			if(is_button_pressed_1s(2)) {

			}
			if(buttonflag2 == 0) {
				buttonflag2 = 1;

			}
		} else {
			buttonflag2 = 0;
		}
		// SET_TIMER 1S IF DONT PRESS
		if (timer0_flag == 1){
			setTimer(1000);
		}
		break;
	default:
		Mode = MODE_1;
	}
}
