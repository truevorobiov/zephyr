#include "bh1750.h"

HAL_StatusTypeDef BH1750_Transmit(BH1750_HandleTypeDef* handler, uint8_t command)
{
	return HAL_I2C_Master_Transmit(handler->hi2c, handler->address << 1, &command, 10, 1000);
}

HAL_StatusTypeDef BH1750_Read(BH1750_HandleTypeDef* handler, float *value)
{
	uint8_t data[2];

	HAL_StatusTypeDef status = HAL_I2C_Master_Receive(handler->hi2c, handler->address << 1, data, sizeof(data), 5000);

	if (status != HAL_OK)
	{
		*value = -1.0;
		return status;
	}

	*value = (float)((data[0] << 8) | data[1]) / 1.2f;

	return HAL_OK;
}

HAL_StatusTypeDef BH1750_Init(BH1750_HandleTypeDef* handler, I2C_HandleTypeDef* hi2c, uint8_t address)
{
	HAL_StatusTypeDef status;

    status = HAL_I2C_IsDeviceReady(hi2c, address << 1, 10, 1000);

    if (status != HAL_OK)
    {
        return status;
    }

    handler->hi2c = hi2c;
    handler->address = address;

	status = BH1750_Transmit(handler, BH1750_POWER_ON);

	if (status != HAL_OK)
	{
		return status;
	}

	status = BH1750_Transmit(handler, BH1750_CONTINUOUS_H_MODE);

	if (status != HAL_OK)
	{
		return status;
	}

	HAL_Delay(BH1750_H_MODE_DELAY);

	return HAL_OK;
}
