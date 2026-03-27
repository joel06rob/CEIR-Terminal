import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('idle_log.csv')

#Create multiple graphs using subplots
fig, axs = plt.subplots(3)

#Plot data onto graph
#plot(x axis, y axis)
axs[0].plot(data["TIME"], data["RPM"], label="RPM", color="blue")
axs[1].plot(data["TIME"], data["TEMP"], label="TEMP (C)", color="orange")
axs[2].plot(data["TIME"], data["OIL"], label="OIL (PSI)", color="black")


axs[0].set_ylabel("Revs Per Minute (RPM)")
axs[0].set_xlabel("Time")
axs[0].legend()
axs[1].set_ylabel("Temperature (C)")
axs[1].set_xlabel("Time")
axs[1].legend()
axs[2].set_ylabel("Oil Level (PSI)")
axs[2].set_xlabel("Time")
axs[2].legend()


plt.savefig("plotoutput.png")


