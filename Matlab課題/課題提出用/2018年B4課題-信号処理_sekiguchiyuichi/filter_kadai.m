clear
n=4096;         %データ数
dt=0.005;       %サンプリング間隔
t=((1:n)-1)*dt;
f=t/dt/dt/n;    
fs=1/dt;        %サンプリング周波数
fc_high = 10;   %ハイパス用
fc_low = 70;    %ローパス用

%遮断周波数やサンプル数などは上のものを使ってください

%sin波の作成と合成波の作成

%フィルターの作成と適用(グラフも作成).
%フィルタの次数は2でやりました.
  
xaxis = linspace(0,200,n);
 
f1 = 5;
x1 = sin(2*pi*f1*t);
f2 = 50;
x2 = sin(2*pi*f2*t);
f3 = 80;
x3 = sin(2*pi*f3*t);


[b,a]  = butter(2,fc_low * 2 /fs ,'low');%ローパスフィルタ
[b1,a1]  = butter(2,fc_high * 2 /fs ,'high');
[b2,a2]  = butter(2,[fc_high  fc_low] * 2/fs ,'bandpass');

subplot(3,3,1)
x = x1 + x2 + x3;
plot(t,x)
xlim([0,0.3])
xlabel('時間[s]')
title('3周波数の合成波形')

subplot(3,3,2)
y1 = fft(x,n);
y2 = abs(y1);
plot(xaxis,y2)
title('合成波形のFFT')
  
subplot(3,3,4)
y_lowpass = filter(b,a,x);
plot(t,y_lowpass)
xlim([0,0.3])
ylim([-2,2])
title('ローパス通過後の合成波形')

subplot(3,3,5)
y_highpass=filter(b1,a1,x);
plot(t,y_highpass)
xlim([0,0.3])
ylim([-2,2])
title('バンドパス通過後の合成波形')

subplot(3,3,6)
y_bandpass=filter(b2,a2,x);
plot(t,y_bandpass)
xlim([0,0.3])
title('バンドパス通過後の合成波形')

subplot(3,3,7)
y1 = fft(y_lowpass,n);
y2 = abs(y1);
plot(xaxis,y2)
ylim([0,2000])
xlabel('Frequency [Hz]')
title('ローパス後のFFT')

subplot(3,3,8)
y1 = fft(y_highpass,n);
y2 = abs(y1);
plot(xaxis,y2)
ylim([0,2500])
xlabel('Frequency [Hz]')
title('ハイパス後のFFT')

subplot(3,3,9)
y1 = fft(y_bandpass,n);
y2 = abs(y1);
plot(xaxis,y2)
ylim([0,2500])
xlabel('Frequency [Hz]')
title('バンドパス後のFFT')

