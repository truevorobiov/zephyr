/*
 * The TCA9548A is a bus multiplexer I2C.
 *
 * {@see https://www.ti.com/lit/ds/symlink/tca9548a.pdf}
 */

#ifndef INC_TCA9548A_H_
#define INC_TCA9548A_H_


#include "main.h"

typedef struct
{
  I2C_HandleTypeDef* hi2c;
  uint8_t address;
  uint8_t channel_id;
} TCA9548A_HandleTypeDef;

void TCA9548A_Init(TCA9548A_HandleTypeDef* handler, I2C_HandleTypeDef* hi2c, uint8_t address);

HAL_StatusTypeDef TCA9548A_SetChannel(TCA9548A_HandleTypeDef* handler, uint8_t channel_id);

#endif /* INC_TCA9548A_H_ */
