#include "spi_slave.h"

/*--------------VARS--------------*/
uint8_t address = 0;
uint16_t data = 0;
uint8_t mod = -1;
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

/*----------------FUNCTIONS FOR SPI COMUNICATION-----------------*/
// Resiving address of a register that master want to get/set
uint16_t slave_listen_for_reg_address(SPI_HandleTypeDef *hspi)
{
	HAL_StatusTypeDef error;
	error = HAL_SPI_Receive_IT(hspi, &address, 1);
	return (uint16_t) error;
}

uint16_t slave_set_reg_address(SPI_HandleTypeDef *hspi)
{
	while(hspi->State != HAL_SPI_STATE_READY){};
}

// Transmitting register to master
uint16_t slave_transimt_reg_data(SPI_HandleTypeDef *hspi)
{
	uint16_t Ldata = get_reg(address);
	return (uint16_t) HAL_SPI_Transmit_IT(hspi, (uint8_t*) &Ldata, 2);
}

// Resiving register value from master to set it to desired register
uint16_t slave_listen_for_reg_data(SPI_HandleTypeDef *hspi)
{
	HAL_StatusTypeDef err;
	err = HAL_SPI_Receive_IT(hspi, (uint8_t*) &data, 2);
	return (uint16_t) err;
}

uint16_t slave_set_reg_data(SPI_HandleTypeDef *hspi)
{
	while (hspi->State != HAL_SPI_STATE_READY) {};
	return (uint16_t) set_reg__(address, data);
}

uint16_t slave_respond_to_master(SPI_HandleTypeDef *hspi)
{
	if (mod)
		return slave_resive_reg_data(hspi);
	else
		return slave_transimt_reg(hspi);
}
/*----------------------------------------------------------------*/

/*--------------Function helpers----------------*/
static uint16_t get_reg(uint8_t adress)
{
	if (adress >= 0 && adress <= 7) {
		uint16_t reg = regs[adress];
		return reg;
	}
	return (uint16_t) WRONG_ADRESS;
}

static uint16_t set_reg__(uint8_t adress, uint16_t data)
{
	if (data & (~masks[adress])) {
		uint16_t err = (uint16_t) WRONG_VAL;
		return err;
	}
	regs[adress] = data;
	return 0;
}
/*----------------------------------------------*/
