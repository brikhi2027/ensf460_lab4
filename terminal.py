# Terminal.py
# Author: Mark Guerta, John Tumacder, Bhvana Rikhi
# Created: November 3, 2024, 10:32 AM
import serial
import pandas as pd
import matplotlib.pyplot as plt
import plotly.express as px
import time
# Open serial port
rawData = []
ser = serial.Serial(port ="/dev/tty.usbserial-FT0EUFRW", baudrate=4800, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

print("start")
timeSeconds = []
startTime = time.time()
while (time.time() - startTime < 10.25):
    timeSeconds.append(time.time()-startTime)
    s = ser.readline()
    s.decode("ASCII")
    s.strip()
    print(s)

    rawData.append(s) # append to rawData
ser.close() # close port
formattedData = []
for i in rawData:
    formattedData.append(int(i))
print(formattedData)

df = pd.DataFrame()
df['Time (seconds)'] = timeSeconds
df['Voltage (V)'] = formattedData
df.to_csv("RxData.csv", index = False)

plt.plot(timeSeconds, formattedData, marker='o')
plt.title('Voltage vs Time')
plt.xlabel('Time (seconds)')
plt.ylabel('Voltage (V)')
plt.grid(True)
plt.show()