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

w1=10*pi;       
w2=100*pi;
w3=160*pi;

s1=sin(w1*t);
s2=sin(w2*t);
s3=sin(w3*t);

g=s1+s2+s3; %合成関数

subplot(1,1,1); stem(n,t);                %g(t)の図示
xlabel('time t'); ylabel('g(t)'); grid;




%フィルターの作成と適用(グラフも作成).
%フィルタの次数は2でやりました.
