import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('idle_log.csv')

#Plot data onto graph
#plot(x axis, y axis)
plt.plot(data["TIME"], data["RPM"], label="RPM")
plt.plot(data["TIME"], data["TEMP"], label="TEMP (C)")
plt.plot(data["TIME"], data["OIL"], label="OIL (PSI)")

plt.xlabel("Time")
plt.ylabel("Engine Data")
plt.legend()

plt.savefig("plotoutput.png")


