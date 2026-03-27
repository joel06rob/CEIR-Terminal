import pandas as pd
import matplotlib.pyplot as plt
import os

def plot_data(filename):

    data = pd.read_csv(filename + '.csv')

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

    plt.savefig(filename + "_output.png")

#Check if the log files exist - call the plot function
if os.path.isfile("idle_log.csv"):
    print("File Exists")
    plot_data("idle_log")

if os.path.isfile("cruise_log.csv"):
    print("File Exists")
    plot_data("cruise_log")

if os.path.isfile("stress_log.csv"):
    print("File Exists")
    plot_data("stress_log")









