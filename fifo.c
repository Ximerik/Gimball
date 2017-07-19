struct ring_bufer{
    uint16_t memory[BUFER_SIZE];
    uint8_t write_count,
            read_count;
};

/* is_free()
* Function check if READ and WRITE COUNT equals to zero - bufer is FREE. 
* Or, if WRITE (READ) COUNT dont equals to zero, but WRITE COUNT doesnt equals to 
* READ COUNT - bufer is FREE, too.
*/
bool is_free(struct ring_bufer *this_bufer){
	if ((this_bufer->write_count == 0  && this_bufer->read_count  === 0) ||
		((this_bufer->write_count != 0 || this_bufer->read_count  != 0) && 
		(this_bufer->write_count != this_bufer->read_count)))
			return 1;
		else 
			return 0;
}
bool is_empty(struct ring_bufer *this_bufer){

		if ((this_bufer->write_count) == (this_bufer->read_count))
			return 1;
		else
			return 0;
}
void write(char data, struct ring_bufer *this_bufer){
	if (is_free(this_bufer)){
	this_bufer -> memory[(this_bufer -> write_count)++] = data;
	if (this_bufer -> write_count > SIZE-1)
		this_bufer -> write_count = 0;
	}
}
void read(char* data, struct ring_bufer *this_bufer){
	If (!(is_empty(this_bufer))){
	*data++ = this_bufer -> memory[(this_bufer -> read_count)++];
	if (this_bufer -> read_count > SIZE-1)
		this_bufer -> read_count = 0;
	}
}
void clear_bufer(struct ring_bufer *this_bufer){
		this_bufer -> write_count = 0;
		this_bufer -> read_count = 0;
}
