if ~isempty(instrfind) fclose(instrfind); delete(instrfind); end
theta = 0:(pi/180):pi;
comport = input('port: [i.e. /dev/cu.usbmodem1421]: ','s');
arduino = serial(comport,'BaudRate',9600); 
fopen(arduino);
i = 0;

inc = 1;

while i<180
   A = fgets(arduino);
   num(i+1) = str2num(A);
   i = i+1;
end
fclose(arduino)

j = 1

while j<181
    tab(j,1) = (j-1)*inc;
    tab(j,2) = num(j);
    tab(j,3) = num(j)*cosd((j-1)*inc);
    tab(j,4) = num(j)*sind((j-1)*inc);
    j = j+1;
end
%figure
%polar(theta,num)
figure
plot(tab(:,3),tab(:,4)), hold on
title('XY Coordinate Scanning Result')
xlabel('X-axis')
ylabel('Y-axis')


