#include "spi_slave.h"

/*--------------VARS--------------*/
uint8_t adress = 0;
uint8_t mod = -1;
/*--------------------------------*/


/*----------------FUNCTIONS FOR SPI COMUNICATION-----------------*/
// Resiving address of a register that master want to get/set
uint16_t slave_resive_reg_adress(SPI_HandleTypeDef *hspi)
{
	uint16_t error;
	error = HAL_SPI_Receive(hspi, &adress, 1, 5000);
	mod = adress & MY_SPI_WRITE_MOD;
	adress = adress >> 1;
	return error;
}

// Transmitting register to master
uint16_t slave_transimt_reg(SPI_HandleTypeDef *hspi)
{
	uint16_t data = get_reg(adress);
	return (uint16_t) HAL_SPI_Transmit_IT(hspi, (uint8_t*) &data, 2);
}

// Resiving register value fregister master to set it to desired register
uint16_t slave_resive_reg_data(SPI_HandleTypeDef *hspi)
{
	uint16_t data;
	HAL_StatusTypeDef err;
	err = HAL_SPI_Receive(hspi, (uint8_t*) &data, 2, 5000);
	if (!err)
		return (uint16_t) set_reg__(adress, data);
	return (uint16_t) err;
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
	if (adress >= 0 && adress <= 7)
		return regs[adress];
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
