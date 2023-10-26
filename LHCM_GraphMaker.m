%% TENTATTIVE MATLAB CODE TO IMPORT AND PLOT HEAT TRANSFER DATA 
HeatTransfer_Data =  readmatrix('11-03-28-Brass360-wJuniors.csv');     %LHCM Data 
time = HeatTransfer_Data(:,2); 
ThermA = HeatTransfer_Data(:,3); 
ThermB = HeatTransfer_Data(:,4); 
ThermC = HeatTransfer_Data(:,5); 
ThermD = HeatTransfer_Data(:,6); 
ThermE = HeatTransfer_Data(:,7); 
ThermF = HeatTransfer_Data(:,8); 
ThermG = HeatTransfer_Data(:,9); 
ThermH = HeatTransfer_Data(:,10); 

figure (1) 
scatter(time*(1/1000),ThermA, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermB, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermC, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermD, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermE, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermF, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermG, 4); %so time is converted from miliseconds to seconds 
hold on 
scatter(time*(1/1000),ThermH, 4); %so time is converted from miliseconds to seconds 
hold off 
grid; grid minor 
box on 
legend('T_A','T_B','T_C','T_D', 'T_E', 'T_F', 'T_G', 'T_H','Location','northeastoutside'); 
%legend('T_A','T_B','T_C','T_D', 'T_E', 'T_F', 'T_G', 'T_H')  
xlim([1070 1175]); ylim([12 27]); 
title('LHCM Data') 
xlabel('time, t (s)'); ylabel('Temperature, T ({\circ}C)'); 

