#include <stdio.h>
#include <string.h>

#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 


#define SIZE 1024
int len;
unsigned char buf[SIZE]=  {0x00};
int fd;


void appendcrlf(unsigned char* );

struct msg_event {
	unsigned char no[14];
	unsigned char msg_id[2];
};
void send_sms(unsigned char *buf, unsigned char *ph)
{
	//frame at+cmgs   write(atcmgs="9492709581")
	strcat(buf,"at+cmgs=");
	strcat(buf,ph);
	appendcrlf(buf);
	printf("final: %s \n", buf);
	write(fd, buf, strlen(buf));


	unsigned char msg[25];
	printf("enter message\n");
	scanf("%s",msg);
	int len = strlen(msg);
	msg[len++] = 0x1a;
	//printf("%s\n",msg);
	write(fd,msg,sizeof(msg));
	sleep(10);

}
void appendcrlf( unsigned char *buf)
{
	int len;
	len = strlen(buf);
	buf[len++] = 0xd;
	buf[len] = 0xa;
}
unsigned char *get_msg_id(void *buf1, int len)
{
	int i=2;
	unsigned char read_sms[25] = {0x00};
	unsigned char *buf = (unsigned char *)buf1;
	struct msg_event msg_eve;
	//+CMTI: "ME",10

	//d a 2b 43 4d 54 49 3a 20 22 4d 45 22 2c 31 30 d a 
	//d a 2b 43 4d 54 49 3a 20 22 53 4d 22 2c 36 d a
	//+CMGR,    16/ 0X...................
	if(buf[i++] == 0x2b)
	{
		if(buf[i++] == 0x43)
			if(buf[i++] == 0x4d)
				if(buf[i++] == 0x54)
					if(buf[i++] == 0x49)
					{
						memcpy(&msg_eve, buf, len);
						printf("Received msg id is: %s\n",msg_eve.msg_id);
						strcat(read_sms,"at+cmgr=");
						strcat(read_sms,msg_eve.msg_id);
						appendcrlf(read_sms);	
						printf("final: %s \n", read_sms);
						write(fd, read_sms, strlen(read_sms));
						return &(msg_eve.msg_id);
					}
	}
	return NULL;
}

int serial_port_init(unsigned char *dev)
{
	if(dev == NULL)
		return -1;
	int serial_port = open(dev, O_RDWR);

	// Create new termios struct, we call it 'tty' for convention
	struct termios tty;

	// Read in existing settings, and handle any error
	if(tcgetattr(serial_port, &tty) != 0) {
		printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
		return 1;
	}

	tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
	tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
	tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
	tty.c_cflag |= CS8; // 8 bits per byte (most common)
	tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
	tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO; // Disable echo
	tty.c_lflag &= ~ECHOE; // Disable erasure
	tty.c_lflag &= ~ECHONL; // Disable new-line echo
	tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
	tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

	tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
	tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
	// tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
	// tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

	tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
	tty.c_cc[VMIN] = 0;

	// Set in/out baud rate to be 9600
	cfsetispeed(&tty, B9600);
	cfsetospeed(&tty, B9600);

	// Save tty settings, also checking for error
	if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
		printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
		return 1;
	}

	return serial_port;
}
void main(void)
{
	fd = serial_port_init("/dev/ttyUSB0");
	while(1)
	{
		read(fd, buf, SIZE);
		len = strlen(buf);
		printf("len: %d\n",len);
		printf("%s: \n",buf);
		get_msg_id((void *)buf, len);
		memset(buf, 0x00, SIZE);
		sleep(1);
		unsigned char ph[] = {0x22,0x39,0x31,0x37,0x37,0x39,0x37,0x36,0x32,0x32,0x30,0x22};
		send_sms(buf,ph);
		sleep(5);	
		read(fd, buf, SIZE);
		printf("%s: \n",buf);
		memset(buf, 0x00,SIZE);
		sleep(1);

	}
}

