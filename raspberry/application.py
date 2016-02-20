import time
import RPi.GPIO as GPIO

LED          =    3
ERROR_PIN    =    4

ledState = False

def initBoard():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LED, GPIO.OUT)
    GPIO.setup(ERROR_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    ledState = False


def testErrorPin():
    return GPIO.input(ERROR_PIN)

def switchLed():
    global ledState

    if ledState:
        ledState = False
    else:
        ledState = True
    GPIO.output(LED, ledState)
    time.sleep(1)

initBoard()
while True:
    if testErrorPin():
        switchLed()
    else:
        GPIO.output(LED, True)
