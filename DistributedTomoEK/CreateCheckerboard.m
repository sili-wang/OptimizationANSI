function Velocitymap = CreateCheckerboard(dx,dy,ddx,ddy,x,y,v,maxdv)
% ddx,ddy:gridsize of the map
% dx,dy:gridsize of checkerboard
% v:velocity
% maxdv:the different of the velocity (percentage)
% x,y:size of map
m = x/ddx;
n = y/ddy;
V= ones(m,n)*v;
for i=1:m
    for j = 1:n
        mm = rem(floor(i*ddx/dx),2)-0.5;
        nn = rem(floor(j*ddy/dy),2)-0.5;
        V(i,j) = V(i,j)*(1+(mm+nn)*maxdv/100);
    end
end
Velocitymap=V;
end


