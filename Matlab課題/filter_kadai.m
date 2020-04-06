clear
n=4096;         %�f�[�^��
dt=0.005;       %�T���v�����O�Ԋu
t=((1:n)-1)*dt;
f=t/dt/dt/n;    
fs=1/dt;        %�T���v�����O���g��
fc_high = 10;   %�n�C�p�X�p
fc_low = 70;    %���[�p�X�p

%�Ւf���g����T���v�����Ȃǂ͏�̂��̂��g���Ă�������

%sin�g�̍쐬�ƍ����g�̍쐬

%x = (0:dt:dt*(n-1));
y1 = sin(2*pi*5*t);
y2 = sin(2*pi*50*t);
y3 = sin(2*pi*80*t);
y = y1 + y2 + y3;

figure(1)
subplot(4,2,1);
plot(t,y)
title('�����g�`')
xlim([0 0.3])

ft = fft(y);
m = abs(ft);
x2 = (0:fs/n:(length(m)-1)*fs/n);
subplot(4,2,2);
plot(x2,m)
title('FFT')

%�t�B���^�[�̍쐬�ƓK�p(�O���t���쐬).
%�t�B���^�̎�����2�ł��܂���.

[b_low,a_low] = butter(2, fc_low/(fs/2), 'low');
[b_high,a_high] = butter(2, fc_high/(fs/2), 'high');
[b_band,a_band] = butter(1, [fc_high/(fs/2) fc_low/(fs/2)], 'bandpass');

y_low = filter(b_low, a_low, y);
y_high = filter(b_high, a_high, y);
y_band = filter(b_band, a_band, y);
subplot(4,2,3);
plot(t,y_low)
title('���[�p�X�t�B���^')
xlim([0 0.3])
subplot(4,2,5);
plot(t,y_high)
title('�n�C�p�X�t�B���^')
xlim([0 0.3])
subplot(4,2,7);
plot(t,y_band)
title('�o���h�p�X�t�B���^')
xlim([0 0.3])

l = fft(y_low);
h = fft(y_high);
b = fft(y_band);
low = abs(l);
high = abs(h);
band = abs(b);
subplot(4,2,4);
plot(x2,low);
title('FFT')
subplot(4,2,6);
plot(x2,high)
title('FFT')
subplot(4,2,8);
plot(x2,band)
title('FFT')

% �_�E���T���v�����O�i�T���v���������炷�j
figure(2)
subplot(3,1,1);
plot(t,y)
title('�����g�`')
xlim([0 0.3])
y_down = downsample(y, 5);
x_down = downsample(t, 5);
subplot(3,1,2)
plot(x_down,y_down)
title('�_�E���T���v�����O')
xlim([0 0.3])

% �A�b�v�T���v�����O�F3���X�v���C����ԁi�T���v�����𑝂₷�j
x_up = (0:dt/5:dt*(n-1));
y_up = spline(t,y,x_up);
subplot(3,1,3)
plot(x_up,y_up)
title('�A�b�v�T���v�����O')
xlim([0 0.3])