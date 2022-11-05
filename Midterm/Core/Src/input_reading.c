/*
 * input_reading.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "main.h"
#include "input_reading.h"
// we aim to work with more than one buttons
#define N0_OF_BUTTONS 					3
#define DURATION_FOR_AUTO_INCREASING 	300
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET

// the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static uint16_t buttonPin[N0_OF_BUTTONS] = {BUTTON_RESET_Pin, BUTTON_INC_Pin, BUTTON_DEC_Pin};
static uint8_t flagForButtonPress3s [ N0_OF_BUTTONS ];
static uint16_t counterForButtonPress3s [ N0_OF_BUTTONS ];

//we define function to SET all buffers to RELEASED
void button_reading_Init(void){
	for (int i = 0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		buttonBuffer[i] = BUTTON_IS_RELEASED;
	}
}

void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, buttonPin[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
		// CHECK PRESS 3S
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			if(counterForButtonPress3s[i] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress3s[i]++;
			} else {
				flagForButtonPress3s[i] = 1;
			}
		} else {
			counterForButtonPress3s[i] = 0;
			flagForButtonPress3s[i] = 0;
		}
		// END CHECK PRESS 3S
	}
}

int is_button_pressed(int index){
	if(index >= N0_OF_BUTTONS) return 1;
	if (buttonBuffer[index] == BUTTON_IS_PRESSED){
		return 1;
	}
	else return 0;
}

int is_button_pressed_3s(int index) {
	if(index >= N0_OF_BUTTONS) return 0;
	return (flagForButtonPress3s[index] == 1);
}

