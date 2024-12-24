import matplotlib.pyplot as plt
import numpy as np
from pandas import read_csv
from mpl_toolkits.mplot3d import axes3d 
from matplotlib import cm
df = read_csv('CSV_Files/2D_solution.csv')
x,y,v = df['x'],df['y'],df['value']
fig = plt.figure()
ax = plt.axes(projection = '3d')
#ax.grid()
#ax.scatter(x,y,v,c='r',s=20)
#ax.plot_surface(x,y,v)
cset = ax.tricontourf(x, y, v,levels=500,colors='green')
#cset = ax.tricontourf(x, y, v, zdir= 'z', cmap=cm.coolwarm)
#fig.colorbar(cset)
ax.set_zlim(0, 0.5)
#plt.clim([-0.2,0.2])
plt.show()
