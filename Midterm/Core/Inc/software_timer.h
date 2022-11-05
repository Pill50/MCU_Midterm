/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2022
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_CYCLE 10;

extern int timer0_flag;
extern int blink_flag;
extern int longpress_flag;
extern int LED7_flag;

void setTimer(int duration);
void setBlinkLedTimer(int duration);
void setLED7Timer(int duration);
void setLongpressTimer(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
