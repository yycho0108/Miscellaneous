import signal
import sys
def handler(signum,frame):
    print("TERMINATE...")
    sys.exit(0)
signal.signal(signal.SIGINT,handler)

while(1):
    print("WAIT...")

