/*
 * spi_slave.h
 *
 *  Created on: Nov 13, 2023
 *      Author: George
 */

#ifndef INC_SPI_SLAVE_H_
#define INC_SPI_SLAVE_H_

#include "stm32f7xx_hal.h"
#include "my_spi_useful.h"
#include <machine/_default_types.h>

/*--------------VARS---------------*/
extern uint16_t regs[8];
extern uint16_t masks[8];
extern uint8_t adress;
extern uint8_t mod;
/*--------------------------------*/

/*---------FUNC PROTOTYPE---------*/
uint16_t salve_set_mode(SPI_HandleTypeDef *hspi);
uint16_t slave_resive_reg_adress(SPI_HandleTypeDef *hspi);
uint16_t slave_respond_to_master(SPI_HandleTypeDef *hspi);
uint16_t slave_transimt_reg(SPI_HandleTypeDef *hspi);
uint16_t slave_resive_reg_data(SPI_HandleTypeDef *hspi);
static uint16_t set_reg__(uint8_t adress, uint16_t data);
static uint16_t get_reg(uint8_t adress);
/*--------------------------------*/

#endif /* INC_SPI_SLAVE_H_ */
