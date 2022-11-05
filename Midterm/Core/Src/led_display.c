/*
 * led_display.c
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#include "main.h"
#include "led_display.h"

void clearLED() {
	HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,1);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,1);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,1);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,1);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,1);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,1);
}

// Display LED7
void display7SEG(int num){
	clearLED();
	switch(num){
		case 0:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,0);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,1);
			break ;
		};
		case 1:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,1);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,1);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,1);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,1);
			break ;
		};
		case 2:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,1);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,0);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,1);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 3: {
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,1);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 4:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,1);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,1);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 5:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,1);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 6:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,1);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,0);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 7:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,1);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,1);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,1);
			break;
		};
		case 8:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,0);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
		case 9:{
			HAL_GPIO_WritePin(LED7_0_GPIO_Port,LED7_0_Pin,0);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port,LED7_1_Pin,0);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port,LED7_2_Pin,0);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port,LED7_3_Pin,0);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port,LED7_4_Pin,1);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port,LED7_5_Pin,0);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port,LED7_6_Pin,0);
			break;
		};
	}
}
