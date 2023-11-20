/*
 * my_spi_driver.c
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#include "my_spi_driver.h"

// Function to set register address
uint16_t my_spi_transmit_reg_adr(SPI_HandleTypeDef* hspi, uint8_t* address)
{
	uint16_t error;
	error = HAL_SPI_Transmit_IT(hspi, (uint8_t*) address, 1);
	return error;
}

// Function to get register data
uint16_t my_spi_listen_for_req_data(SPI_HandleTypeDef* hspi, uint16_t* data)
{
	uint16_t error;
	error = HAL_SPI_Receive_IT(hspi, (uint8_t*) data, 2);
	return error;
}

// Function to set register data
uint16_t my_spi_transmit_reg_data(SPI_HandleTypeDef* hspi, uint16_t* data)
{
	uint16_t error;
	error = HAL_SPI_Transmit_IT(hspi, (uint8_t*) data, 2);
	return error;
}
