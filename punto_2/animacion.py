import numpy as np
import sys
import matplotlib.pyplot as plt
import matplotlib.animation as animation

data= np.genfromtxt(sys.argv[1], delimiter=',')

# The first row represents the x spacing values  
x= data[0,:]
u= data[1:,:] 

#Gif
def animate(nframe):
	plt.cla()
	plt.plot(x, u[nframe,:], 'o-')
	plt.title("frame: "+str(nframe))
	#plt.ylim(u.min(), u.max())
	#plt.xlim(0, N_data+1)

fig= plt.figure(figsize=(6,5))

anim = animation.FuncAnimation (fig, animate, frames=len(u))
anim.save('cuerda.gif', writer='imagemagick', fps= 3)


 
