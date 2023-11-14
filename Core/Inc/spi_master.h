/*
 * spi_master.h
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#ifndef INC_SPI_MASTER_H_
#define INC_SPI_MASTER_H_

#include "spi_slave.h"

/*----------READING FROM REGS-----------*/
uint8_t read_alert_status(uint8_t data);
uint8_t read_config(uint8_t data);
uint8_t read_low_limit(uint16_t data);
uint8_t read_high_limit(uint16_t data);
uint8_t read_hysteresis(uint16_t data);
uint8_t read_low_conv(uint16_t data);
uint8_t read_high_conv(uint16_t data);
/*--------------------------------------*/

/*------------WRITING TO REGS-----------*/
uint8_t write_alert_status(uint8_t data);
uint8_t write_config(uint8_t data);
uint8_t write_low_limit(uint16_t data);
uint8_t write_high_limit(uint16_t data);
uint8_t write_hysteresis(uint16_t data);
uint8_t write_low_conv(uint16_t data);
uint8_t write_high_conv(uint16_t data);
/*--------------------------------------*/

#endif /* INC_SPI_MASTER_H_ */
