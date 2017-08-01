/**********************/
/*  GLOBAL VARIABLES  */
/**********************/



uint32_t orientation,
		 measurement,
		 _orientation_error;
/**
* Структура cable служит для передачи информации между функциями и функциональными блоками программы
*/
typedef uint8_t wire;
struct cable{
wire 	zero,
		one,
		two,
		three,
		four,
		five,
		six,
		seven;
};

/* Shift register for sorege data about orientation error */		 
struct shift_reg{
	uint16_t mem[ERROR_REG_SIZE];
	uint8_t  write_count,
			 read_count;
}error;
struct ring_bufer{
    uint16_t memory[BUFER_SIZE];
    uint8_t write_count,
            read_count;
};
