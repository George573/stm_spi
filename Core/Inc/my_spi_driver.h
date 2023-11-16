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

// SPIs
//extern SPI_HandleTypeDef* master_spi;
//extern SPI_HandleTypeDef* slave_spi;
extern uint8_t master_transmit;
extern uint8_t slave_transmit;

// Call before using
//void spi_driver_init(SPI_HandleTypeDef* master_spi__, SPI_HandleTypeDef* slave_spi__);

// Function to set register adress
uint16_t my_spi_set_reg_adr(SPI_HandleTypeDef* hspi, uint8_t* address);

// Function to get register data
uint16_t my_spi_read_reg(SPI_HandleTypeDef* hspi, uint16_t* data);

// Function to set register data
uint16_t my_spi_set_reg(SPI_HandleTypeDef* hspi, uint16_t* data);

#endif /* INC_MY_SPI_DRIVER_H_ */
