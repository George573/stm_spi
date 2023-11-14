/*
 * spi_slave.h
 *
 *  Created on: Nov 13, 2023
 *      Author: George
 */

#ifndef INC_SPI_SLAVE_H_
#define INC_SPI_SLAVE_H_

#include "stm32f7xx_hal_spi.h"
#include "my_spi_useful.h"
#include <machine/_default_types.h>

/*---------FUNC PROTOTYPE---------*/
HAL_StatusTypeDef resive_reg_adress(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef transimt_reg(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef set_reg(SPI_HandleTypeDef *hspi);
static uint16_t get_reg(uint8_t adress);
static uint32_t set_reg__(uint8_t adress, uint16_t data);
/*--------------------------------*/

/*-----------REGISTERS------------*/
extern uint16_t regs[8];
extern uint16_t masks[8];
extern uint8_t adress;
/*--------------------------------*/

#endif /* INC_SPI_SLAVE_H_ */
