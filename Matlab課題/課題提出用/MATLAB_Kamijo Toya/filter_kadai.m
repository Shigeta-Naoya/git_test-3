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

w1=10*pi;       
w2=100*pi;
w3=160*pi;

s1=sin(w1*t);
s2=sin(w2*t);
s3=sin(w3*t);

g=s1+s2+s3; %�����֐�

subplot(1,1,1); stem(n,t);                %g(t)�̐}��
xlabel('time t'); ylabel('g(t)'); grid;




%�t�B���^�[�̍쐬�ƓK�p(�O���t���쐬).
%�t�B���^�̎�����2�ł��܂���.
