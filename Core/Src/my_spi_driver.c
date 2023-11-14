/*
 * my_spi_driver.c
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#include "my_spi_driver.h"

SPI_HandleTypeDef* master_spi;
SPI_HandleTypeDef* slave_spi;

void spi_driver_init(SPI_HandleTypeDef* master_spi__, SPI_HandleTypeDef* slave_spi__)
{
	master_spi = master_spi__;
	slave_spi = slave_spi__;
}

// Function to get register data
uint16_t read_reg(uint8_t adress)
{
	HAL_SPI_Transmit_IT(master_spi, &adress, 1);
	resive_reg_adress(slave_spi);
	transimt_reg(slave_spi);
	uint16_t data;
	HAL_SPI_Receive_IT(master_spi, &data, 2);
	return data;
}

// Function to set register data
uint32_t set_reg(uint8_t adress, uint16_t data)
{

}
