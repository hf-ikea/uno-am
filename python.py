import serial, time
from scipy.io import wavfile

samplerate, data = wavfile.read('audio.wav')
arduino = serial.Serial(port='COM3', baudrate=115200)

smp = 0
period = 0.0001
last = time.time()
while smp < data.shape[0]:
    next = last + period
    time.sleep(max(0, next - time.time()))
    last = next
    arduino.write(data[smp].tobytes())
    smp += 1
