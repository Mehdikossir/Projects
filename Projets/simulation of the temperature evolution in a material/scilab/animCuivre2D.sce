[fd,err] = mopen("cuivre2d","r")
cuivre2d = read("cuivre2d",10100,101)
mclose(fd)


  
x=[1:1:101]
y=[1:1:101]

  


  for t=0:99
     drawlater();
      clf()
      surf(cuivre2d(x+(t*101),y))  
 
      drawnow();
  end
  
