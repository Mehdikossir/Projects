[fd,err] = mopen("fer2d","r")
fer2d = read("fer2d",10100,101)
mclose(fd)


  
x=[1:1:101]
y=[1:1:101]

  


  for t=0:99
     drawlater();
      clf()
      surf(fer2d(x+(t*101),y))  
 
      drawnow();
  end
  
