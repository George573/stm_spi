/*
 * my_spi_driver.h
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#ifndef INC_MY_SPI_DRIVER_H_
#define INC_MY_SPI_DRIVER_H_

#include "stm32f7xx_hal_spi.h"
#include "my_spi_useful.h"
#include "spi_slave.h"
#include <machine/_default_types.h>

// SPIs
extern SPI_HandleTypeDef* master_spi;
extern SPI_HandleTypeDef* slave_spi;

// Call before using
void spi_driver_init(SPI_HandleTypeDef* master_spi__, SPI_HandleTypeDef* slave_spi__);

// Function to get register data
uint16_t read_reg(uint8_t adress);

// Function to set register data
uint32_t set_reg(uint8_t adress, uint16_t data);

#endif /* INC_MY_SPI_DRIVER_H_ */
