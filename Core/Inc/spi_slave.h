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
extern uint8_t adress;
extern uint8_t mod;
/*--------------------------------*/

/*-----------registers------------*/
// Registers (set to default values on creation)
uint16_t regs[8] = {
		CONV_RESULT_DEF_VAL,
		ALERT_STATUS_DEF_VAL,
		CONFIG_DEF_VAL,
		LOW_LIMIT_DEF_VAL,
		HIGH_LIMIT_DEF_VAL,
		HYSTERESIS_DEF_VAL,
		LOW_CONV_DEF_VAL,
		HIGH_CONV_DEF_VAL
};

// Registers' masks
uint16_t masks[8] = {
		CONV_RESULT_MASK,
		ALERT_STATUS_MAKS,
		CONFIG_MASK,
		LOW_LIMIT_MASK,
		HIGH_LIMIT_MASK,
		HYSTERESIS_MASK,
		LOW_CONV_MASK,
		HIGH_CONV_MASK
};
/*-------------------------------------*/

/*---------FUNC PROTOTYPE---------*/
uint16_t salve_set_mode(SPI_HandleTypeDef *hspi);
uint16_t slave_resive_reg_adress(SPI_HandleTypeDef *hspi);
uint16_t slave_respond_to_master(SPI_HandleTypeDef *hspi);
uint16_t slave_transimt_reg(SPI_HandleTypeDef *hspi);
uint16_t slave_resive_reg_data(SPI_HandleTypeDef *hspi);
static uint16_t get_reg(uint8_t adress);
static uint16_t set_reg__(uint8_t adress, uint16_t data);
/*--------------------------------*/

#endif /* INC_SPI_SLAVE_H_ */
