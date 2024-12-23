import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

csv_file_path = "CSV_Files/cube.csv"

data = pd.read_csv(csv_file_path)

x = data['x']
y = data['y']
z = data['z']
value = data['value']

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

sc = ax.scatter(x, y, z, c=value, cmap='viridis')

cbar = plt.colorbar(sc, ax=ax, label='Voltage')

ax.set_xlabel('X Coordinate')
ax.set_ylabel('Y Coordinate')
ax.set_zlabel('Z Coordinate')
ax.set_title('3D Voltage Distribution')
plt.show()
