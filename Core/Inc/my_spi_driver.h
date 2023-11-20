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
uint16_t my_spi_transmit_reg_adr(SPI_HandleTypeDef* hspi, uint8_t* address);

// Function to set register data
uint16_t my_spi_transmit_reg_data(SPI_HandleTypeDef* hspi, uint16_t* data);

// Function to get register data
uint16_t my_spi_listen_for_req_data(SPI_HandleTypeDef* hspi, uint16_t* data);

#endif /* INC_MY_SPI_DRIVER_H_ */
