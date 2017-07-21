/**********************/
/* УКАЗАНЕ ПОЛОЖЕНИЯ  */
/**********************/
 void directive(char input){
	switch (input){
		case: HOLD_ORIENTATION
			orientation = save_actual_orientation();
		case: NEW_ORIENTATION
			orientation = save_new_orientation();
		default: 
			write_error_message(WRONG_DIRECTIVE, input);
	}
}
uint32_t save_actual_orientation(){

}

uint32_t save_new_orientation(uint8_t mode, uint16_t *alpha, uint16_t *gamma){
	switch (mode)
		case: ORIENTATION_ABSOLUTE{
			return *gamma+(*alpha<<16);
		}
		case: ORIENTATION_RELATIVE{
			return  orientation+(*gamma+(*alpha<<16));
		}
		default:
			{
				write_error_message(SAVE_NEW_ORIENTATION_ERR, mode);
				return orientation;
			}
}
/**********************/
/*      ЗАМЕР         */
/**********************/
uint16_t get_measurement(uint8_t mode){
	switch (mode){
		case: GET_ANGLE
			//get angle
		case: GET_ANGULAR_SPEED
			//get ang speed
		default:
			write_error_message(WRONG_MEASUREMENT_MODE, mode);
	}
}

uint16_t measure(uint8_t measurement_number){
	uint8_t count = 0;
	uint16_t temp = 0;
	while(count++ < measurement_number)
		temp+= get_measurement(GET_ANGLE);
	measurement = temp/measurement_number;
}

/**********************/
/*      ОШИБКА        */
/**********************/
void orientation_error(void){
	_orientation_error = orientation - measurement;
	write_shift_reg(_orientation_error, error_reg);
}

void write_shift_reg(uint16_t data, struct shift_reg *this_reg){
	char count = ERROR_REG_SIZE;
	while (count-- > -1)
		this_reg->mem[count] = this_reg->mem[count-1];
	this_reg->mem[0] = data;
}
uint16_t get_error_from_reg(uint8_t position, struct shift_reg *this_reg){
	if (position > ERROR_REG_SIZE || position < ERROR_REG_SIZE){
		write_error_message(WRONG_SHIFT_REG_POSITION, position);
		return 0;
	}
	else
		return this_reg->mem[position];
}

/**********************/
/*        ПИД         */
/**********************/
void pid(uint16_t* kp, uint16_t* ki, uint16_t* kd){
	static uint16_t output, pre_output;
	output = pre_output + 
				kp*(get_error_from_reg(0, error) - get_error_from_reg(1, error)+
				ki*get_error_from_reg(0, error)+
				kd*(get_error_from_reg(0, error)-2*get_error_from_reg(1, error)+get_error_from_reg(2, error));
	pre_output = output;
}