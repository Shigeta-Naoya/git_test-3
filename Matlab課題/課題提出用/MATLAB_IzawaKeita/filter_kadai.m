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

%�����g�`
y = sin(2*pi*5*t)+sin(2*pi*50*t)+sin(2*pi*80*t);
%�����g�`�`��
figure
subplot(4,2,1)
plot(t,y)
title('�����֐�')
xlim([0 0.3])

%FFT�ϊ�
y_fft = fft(y);
power_y = abs(y_fft).^2/n;    %�p���[�X�y�N�g��
%FFT�p���[�X�y�N�g���`��
subplot(4,2,2)
plot(f,power_y)
title('FFTpower')


%�o�^���[�X�t�B���^�[
%���[�p�X�t�B���^
[b_low,a_low] = butter(2,fc_low/(fs/2),'low');
y_low = filter(b_low,a_low,y);
%���[�p�X�t�B���^�g�`
subplot(4,2,3)
plot(t,y_low)
title('2�����[�p�X�t�B���^��')
xlim([0 0.3])
%FFT�ϊ�
y_low_fft = fft(y_low);
power_low = abs(y_low_fft).^2/n;    %�p���[�X�y�N�g��
%FFT�p���[�X�y�N�g���`��
subplot(4,2,4)
plot(f,power_low)
title('FFTpower')

%�n�C�p�X�t�B���^
[b_high,a_high] = butter(2,fc_high/(fs/2),'high');
y_high = filter(b_high,a_high,y);
%�n�C�p�X�t�B���^�g�`
subplot(4,2,5)
plot(t,y_high)
title('2���n�C�p�X�t�B���^��')
xlim([0 0.3])
%FFT�ϊ�
y_high_fft = fft(y_high);
power_high = abs(y_high_fft).^2/n;    %�p���[�X�y�N�g��
%FFT�p���[�X�y�N�g���`��
subplot(4,2,6)
plot(f,power_high)
title('FFTpower')

%�o���h�p�X�t�B���^
[b_band,a_band] = butter(2,[fc_high fc_low]/(fs/2),'bandpass');
y_band = filter(b_band,a_band,y);
%�o���h�p�X�t�B���^�g�`
subplot(4,2,7)
plot(t,y_band)
title('2���o���h�p�X�t�B���^��')
xlim([0 0.3])
%FFT�ϊ�
y_band_fft = fft(y_band);
power_band = abs(y_band_fft).^2/n;    %�p���[�X�y�N�g��
%FFT�p���[�X�y�N�g���`��
subplot(4,2,8)
plot(f,power_band)
title('FFTpower')

%png�o��
print -dpng -r300 'filtter_kadai.png'

%�t�B���^�[�̍쐬�ƓK�p(�O���t���쐬).
%�t�B���^�̎�����2�ł��܂���.
