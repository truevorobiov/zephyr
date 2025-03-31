/**
 * The BH1750 is a serial ambient light I2C sensor.
 *
 * {@see https://arduino.ua/docs/ADC154/BH1750FVI.pdf}
 */

#ifndef INC_BH1750_H_
#define INC_BH1750_H_

#include "main.h"

#define BH1750_POWER_ON 0x01

/**
 * @brief Command for continuous high-resolution measurement mode
 */
#define BH1750_CONTINUOUS_H_MODE 0x10

#define BH1750_H_MODE_DELAY 180

typedef struct
{
  I2C_HandleTypeDef* hi2c;
  uint8_t address;
} BH1750_HandleTypeDef;

HAL_StatusTypeDef BH1750_Init(BH1750_HandleTypeDef* handler, I2C_HandleTypeDef* hi2c, uint8_t address);
HAL_StatusTypeDef BH1750_Transmit(BH1750_HandleTypeDef* handler, uint8_t command);
HAL_StatusTypeDef BH1750_Read(BH1750_HandleTypeDef* handler, float *value);


#endif /* INC_BH1750_H_ */
