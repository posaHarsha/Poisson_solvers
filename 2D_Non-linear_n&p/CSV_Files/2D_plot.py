import matplotlib.pyplot as plt
import numpy as np
from pandas import read_csv
from mpl_toolkits.mplot3d import axes3d 
from matplotlib import cm
df = read_csv('CSV_Files/2D_solution.csv')
x,y,v = df['x'],df['y'],df['value']
plt.tricontourf(x,y,v,levels=30,cmap='viridis')
plt.colorbar(label='Potential(v)')
plt.xlabel('X cordinate')
plt.ylabel('Y cordinate')
plt.show()

