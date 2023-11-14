/*
 * my_spi_driver.c
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#include "my_spi_driver.h"

SPI_HandleTypeDef* master_spi;
SPI_HandleTypeDef* slave_spi;

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == master_spi->Instance) {
		printf("Master T callback\r\n");
	} else {
		printf("Slave T callback\r\n");
	}
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == master_spi->Instance) {
			printf("Master T callback\r\n");
	} else {
			printf("Slave T callback\r\n");
	}
}

void spi_driver_init(SPI_HandleTypeDef* master_spi__, SPI_HandleTypeDef* slave_spi__)
{
	master_spi = master_spi__;
	slave_spi = slave_spi__;
}

// Function to get register data
uint16_t my_spi_read_reg(uint8_t adress)
{
	HAL_SPI_Transmit_IT(master_spi, &adress, 1);
	slave_resive_reg_adress(slave_spi);
	slave_transimt_reg(slave_spi);
	uint16_t data;
	HAL_SPI_Receive_IT(master_spi, (uint8_t*) &data, 2);
	return data;
}

// Function to set register data
uint16_t my_spi_set_reg(uint8_t adress, uint16_t data)
{
	HAL_SPI_Transmit_IT(master_spi, &adress, 1);
	slave_resive_reg_adress(slave_spi);
	HAL_SPI_Transmit_IT(master_spi, (uint8_t*) &data, 2);
	return slave_set_reg(slave_spi);
}
