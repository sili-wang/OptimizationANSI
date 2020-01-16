% TomoEK on single node

V=CreateCheckerboard(500,500,10,10,3000,3000,3000,5)
V=imgaussfilt(V,10);
% generate 200 random scatter point
n = 2000

xy = 10 + 2990*gallery('uniformdata',[n 2],0);
x = xy(:,1);
y = xy(:,2);
v = x.*exp(-x.^2-y.^2);
S = 1./V;

%Test function Traveltime
T = Traveltime(S,10,10,x(1),y(1),x(2),y(2),100)

for i=1:n
    T(i) = Traveltime(S,10,10,200,1500,x(i),y(i),100);
end


% Interpolate 2-D
[xq,yq] = meshgrid(1:10:3000, 1:10:3000);
vq = griddata(x,y,T,xq,yq);

% Draw pictures
mesh(xq,yq,vq)
hold on
plot3(x,y,T,'o')
% xlim([-2.7 2.7])
% ylim([-2.7 2.7])
figure
imagesc(vq)
[FX,FY] = gradient(vq,10);
F=sqrt(FX.*FX+FY.*FY);
figure
imagesc(F(50:250,50:250))
figure
imagesc(S)
