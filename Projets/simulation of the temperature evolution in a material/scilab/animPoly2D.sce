[fd,err] = mopen("polystyrene2d","r")
polystyrene2d = read("polystyrene2d",10100,101)
mclose(fd)


  
x=[1:1:101]
y=[1:1:101]

  


  for t=0:99
     drawlater();
      clf()
      surf(polystyrene2d(x+(t*101),y))  
      drawnow();
  end
  
