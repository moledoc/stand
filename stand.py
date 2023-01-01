import tkinter as tk
import time


window = tk.Tk()
window.geometry("50x50+0+0")
window.attributes('-topmost', True)
window.resizable(False,False)
window.title("stand")

colors = ["#282828","#FF0000"]

# start with 'standing' position, becase it's switched up in the `pos`
color = colors[1]
mins = 10
DURATION=60

def pos():
	global DURATION, color, mins
	color = colors[(colors.index(color)+1)%2]
	mins = (DURATION-mins)
	window.configure(bg=color)
	window.after(mins*60*1000,pos)
pos()	

window.mainloop()
