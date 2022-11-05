/*
 * input_reading.h
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

void button_reading_Init(void);
void button_reading (void);
int is_button_pressed(int index);
int is_button_pressed_3s(int index);

#endif /* INC_INPUT_READING_H_ */
