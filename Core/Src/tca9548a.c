#include "tca9548a.h"

void TCA9548A_Init(TCA9548A_HandleTypeDef* handler, I2C_HandleTypeDef* hi2c, uint8_t address)
{
  handler->hi2c = hi2c;
  handler->address = address;
}

HAL_StatusTypeDef TCA9548A_SetChannel(TCA9548A_HandleTypeDef* handler, uint8_t channel_id)
{
  chanell_id = 1 << channel_id;

  HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(handler->hi2c, handler->address << 1, &channel_id, 10, 1000);

  if (status != HAL_OK)
  {
    return status;
  }

  handler->channel_id = address;

  return HAL_OK;
}
