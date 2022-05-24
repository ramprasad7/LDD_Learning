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


void append(unsigned char* );



void call(unsigned char *buf, unsigned char *ph){
	strcat(buf,"atd");
	strcat(buf,ph);
	strcat(buf,";");
	append(buf);
	printf("Call command: %s \n", buf);
	write(fd, buf, strlen(buf));
}
void send_sms(unsigned char *buf,unsigned char ph[]){
	//frame at+cmgs   write(atcmgs="9492709581")
	char ch = '\"';
	strcat(buf,"at+cmgs=");
	strcat(buf,"\"");
	strcat(buf,ph);
	strcat(buf,"\"");
	append(buf);
	printf("send sms command: %s \n", buf);
	write(fd, buf, strlen(buf));


	unsigned char msg[25];
	printf("enter message\n");
	scanf("%s",msg);
	int len = strlen(msg);
	msg[len++] = 0x1a;
	write(fd,msg,sizeof(msg));
	sleep(10);

}

void append( unsigned char *buf)
{
	int len;
	len = strlen(buf);
	buf[len++] = 0xd;
	buf[len] = 0xa;
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
	int op;
	printf("Enter '1' - call\n\t'2' - sms\n");
	scanf("%d",&op);
	while(1){
		switch (op){
			case 1:
				{
					unsigned char ph1[20];
					printf("enter phone num\n");
					scanf("%s",ph1);
					call(buf,ph1);
					sleep(1);	
					read(fd, buf, SIZE);
					printf("%s: \n",buf);
					memset(buf, 0x00,SIZE);
					sleep(1);
					break;
				}
			case 2:
				{
					unsigned char ph2[20];
					printf("enter phone number\n");
					scanf("%s",ph2);
					send_sms(buf,ph2);
					read(fd,buf,SIZE);
					memset(buf,0x00,SIZE);
					sleep(1);
					break;
				}
			default:{
					printf("wrong input\n");
					break;
				}
		}
	}
}
