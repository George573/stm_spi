/*
 * my_spi_driver.h
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#ifndef INC_MY_SPI_DRIVER_H_
#define INC_MY_SPI_DRIVER_H_

#include "stm32f7xx_hal.h"
#include "my_spi_useful.h"
#include "spi_slave.h"
#include <stdio.h>
#include <machine/_default_types.h>

// Function to set register address
uint16_t my_spi_set_reg_adr(SPI_HandleTypeDef* hspi, uint8_t* address);

// Function to get register data
uint16_t my_spi_start_read_reg(SPI_HandleTypeDef* hspi, uint16_t* data);
uint16_t my_spi_end_read_reg(SPI_HandleTypeDef* hspi);

// Function to set register data
uint16_t my_spi_set_reg(SPI_HandleTypeDef* hspi, uint16_t* data);

#endif /* INC_MY_SPI_DRIVER_H_ */
