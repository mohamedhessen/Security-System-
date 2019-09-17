/*
 * MATH.h
 *
 *  Created on: Aug 17, 2019
 *      Author: mom
 */

#ifndef MATH_H_
#define MATH_H_

#define  SET_BIT(var,bit) (var)|=(1<<(bit))
#define CLEAR_BIT(var,bit) (var)&=~(1<<(bit))
#define TOGGLE_BIT(var,bit) (var)^=(1<<(bit))
#define GET_BIT(var,bit) ((var)>>(bit))&0x01

#endif /* MATH_H_ */
