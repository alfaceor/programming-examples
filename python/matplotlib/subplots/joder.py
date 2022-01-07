  
  left, bottom, width, height = [0.66, 0.65, 0.26, 0.26]
  axIns = fig.add_axes([left, bottom, width, height])
  axIns.set_xlabel("$t/N^\\delta$")
  axIns.set_ylabel("$T$", rotation=0)
  axIns.set_xscale("log")  
  axIns.set_xlim(1e-5, 1e1)  
  axIns.tick_params(axis='x', labelsize=10)
  axIns.tick_params(axis='y', labelsize=10)  
