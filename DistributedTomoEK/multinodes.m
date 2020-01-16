% multi nodes
% map = zeros(300,300);
n=2000
for i =1:n
    i
    map(:,:,i) = singlenode(S,10,10,x(i),y(i),x,y);
end
finalmap = sum(map,3)/n;
% map = map/500;
% figure
imagesc(finalmap(50:250,50:250))