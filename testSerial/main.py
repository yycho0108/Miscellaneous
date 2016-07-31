import serial

def main():
    with serial.Serial(port='/dev/ttyACM0', baudrate=9600) as ser:
        if(ser.isOpen() == False):
            ser.open()
        while ser.isOpen():
            print ser.readline()

if __name__ == '__main__':
    main()
