/*FIFO bufer size. Must be power of 2*/
#define SIZE 8
/* COMAND CODES (MODE) */
#define HOLD_ORIENTATION            0x48
#define NEW_ORIENTATION             0x4E
#define GET_ANGLE                   0x41
#define GET_ANGULAR_SPEED           0x61
#define ORIENTATION_ABSOLUTE        0x21
#define ORIENTATION_RELATIVE        0x7E

/*MPU 6050 REGISTERS*/
#define	ax 0xff //register of accelerometer x-axis
#define	ay 0xff //register of accelerometer y-axis
#define	az 0xff //register of accelerometer z-axis
#define	gx 0xff //register of gyro x-axis
#define	gy 0xff //register of gyro y-axis
#define	gz 0xff //register of gyro z-axis

/*ERROR MESSAGES*/
#define WRONG_DIRECTIVE  			0xFFF0
#define WRONG_MEASUREMENT_MODE		0xFFF1
#define WRONG_SHIFT_REG_POSITION	0xFFF2
#define SAVE_NEW_ORIENTATION_ERR	0xFFF3

/*IIC DEVICES*/
#define MPU6050 0xFF 		/*mcu mpu6050 adress*/

/*CONSTANTS*/
#define ERROR_REG_SIZE 3

/* WIRE NAMES */
#define AXEL_X zero
#define AXEL_Y one
