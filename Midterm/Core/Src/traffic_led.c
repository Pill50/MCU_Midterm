/*
 * traffic_led.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "main.h"
#include "traffic_led.h"
#include "led_display.h"


#define RED 0
#define YELLOW 1
#define GREEN 2
#define N0_OF_LED 3

//we define the buffer to store time_of_led
static uint8_t bufferTimerForLED[N0_OF_LED];

//we define some sub-variable counter for each led
static uint8_t counterRED, counterYELLOW, counterGREEN;

//we define variable timer to save time each led
static uint8_t timeRED, timeYELLOW, timeGREEN;

// Function to turn off all led
void LED_TRAFFIC_INIT(void){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
}

// Function to load value are saved in buffer to counter and time of each led
// to use for display in 7SEG
void LED_TRAFFIC_LOAD_BUFFER(void){
	counterRED = bufferTimerForLED[RED];
	counterYELLOW = bufferTimerForLED[YELLOW];
	counterGREEN = bufferTimerForLED[GREEN];

	timeRED = bufferTimerForLED[RED];
	timeYELLOW = bufferTimerForLED[YELLOW];
	timeGREEN = bufferTimerForLED[GREEN];
}

// Function to store value in buffer
void LED_TRAFFIC_STORE_BUFFER(uint8_t time, uint8_t index){
	bufferTimerForLED[index] = time;
}

// Function to setting led in vertical
//void LED_VERTICAL_RUN(void) {
//	//GREEN1 - ON
//	if (counterGREEN2 > 0){
//		update_vertical_clock_buffer(counterGREEN2);
//		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
//		HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
//		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
//		counterGREEN2--;
//
//	}
//	//AMBER1 - ON
//	else if (counterAMBER2 > 0){
//		update_vertical_clock_buffer(counterAMBER2);
//		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
//		HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
//		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
//		counterAMBER2--;
//	}
//	//RED1 - ON
//	else if (counterRED2 > 0){
//		update_vertical_clock_buffer(counterRED2);
//		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
//		HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
//		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
//		counterRED2--;
//	}
//	if(counterRED2 == 0) {
//		counterRED2 = timeRED;
//		counterAMBER2 = timeAMBER;
//		counterGREEN2 = timeGREEN;
//	}
//}

// Function to setting led in horizontal
//void LED_HORIZONTAL_RUN(void) {
//	//RED2 - ON
//	if (counterRED1 > 0){
//		update_horizontal_clock_buffer(counterRED1);
//		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
//		HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, SET);
//		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
//		counterRED1--;
//	}
//	//AMBER2 - ON
//	else if (counterAMBER1 > 0){
//		update_horizontal_clock_buffer(counterAMBER1);
//		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
//		HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, RESET);
//		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
//		counterAMBER1--;
//	}
//	//GREEN2 - ON
//	else if (counterGREEN1 > 0){
//		update_horizontal_clock_buffer(counterGREEN1);
//		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
//		HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, SET);
//		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
//		counterGREEN1--;
//	}
//	if(counterGREEN1 == 0) {
//		counterRED1 = timeRED;
//		counterAMBER1 = timeAMBER;
//		counterGREEN1 = timeGREEN;
//	}
//}

// Funtion is call when we want to display led in each mode
void LED_TRAFFIC_RUN(void) {
//	LED_HORIZONTAL_RUN();
//	LED_VERTICAL_RUN();
}
