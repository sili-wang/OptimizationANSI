function T = Traveltime(S,xx,yy,x1,y1,x2,y2,ns)

% ns:the number of segments
% xx: x intervel
% yy: y intervel
% S: slowness
% x1,y1: location of source
% x2,y2: location of receiver
dx = (x2-x1)/ns;
dy = (y2-y1)/ns;
ds = sqrt(dx^2+dy^2);
T=0;
% x1,y1,x2,y2
for i= 1:ns
    x = round((x1 + dx*(ns-0.5))/xx);
    y = round((y1 + dy*(ns-0.5))/yy);
    T = T + S(x,y)*ds; 
end

end