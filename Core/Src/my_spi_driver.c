/*
 * my_spi_driver.c
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#include "my_spi_driver.h"

uint8_t master_transmit;
uint8_t slave_transmit;

//void spi_driver_init(SPI_HandleTypeDef* master_spi__, SPI_HandleTypeDef* slave_spi__)
//{
//	master_spi = master_spi__;
//	slave_spi = slave_spi__;
//}

// Function to set register address
uint16_t my_spi_set_reg_adr(SPI_HandleTypeDef* hspi, uint8_t* address)
{
	uint16_t error;
	error = HAL_SPI_Transmit_IT(hspi, (uint8_t*) &adress, 1);
	return error;
}

// Function to get register data
uint16_t my_spi_read_reg(SPI_HandleTypeDef* hspi, uint16_t* data)
{
	uint16_t error;
	error = HAL_SPI_Receive(hspi, (uint8_t*) &data, 2, 5000);
	return error;
}

// Function to set register data
uint16_t my_spi_set_reg(SPI_HandleTypeDef* hspi, uint16_t* data)
{
	uint16_t error;
	error = HAL_SPI_Transmit_IT(hspi, (uint8_t*) data, 2);
	return error;
}
