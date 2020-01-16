function map = singlenode(S,dx,dy,x0,y0,x,y)
% TomoEK on single node

for i=1:length(x)
    T(i) = Traveltime(S,dx,dy,x0,y0,x(i),y(i),100);
end


% Interpolate 2-D
[xq,yq] = meshgrid(1:dx:3000, 1:dy:3000);
vq = griddata(x,y,T,xq,yq,'cubic');

[FX,FY] = gradient(vq,10);
map = sqrt(FX.*FX+FY.*FY);
end
