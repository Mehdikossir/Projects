[fd,err] = mopen("verre2d","r")
verre2d = read("verre2d",10100,101)
mclose(fd)


  
x=[1:1:101]
y=[1:1:101]

  for t=0:99
     drawlater();
      clf()
      surf(verre2d(x+(t*101),y))  
      drawnow();
  end
  
