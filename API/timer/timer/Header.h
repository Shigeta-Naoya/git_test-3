//�萔�錾
#define DEF_APP_NAME	TEXT("Waveform Test")
#define DEF_MUTEX_NAME	DEF_APP_NAME			//�~���[�e�b�N�X��
#define DEF_DATAPERS 1000	//1�b�Ԃɉ��f�[�^���o�͂��邩

//�֐��錾
BOOL CALLBACK MainDlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );	//���C���_�C�A���O�v���V�[�W��
BOOL WinInitialize( HINSTANCE hInst, HWND hPaWnd, HMENU chID, char *cWinName, HWND PaintArea, WNDPROC WndProc ,HWND *hDC);//�q�E�B���h�E�𐶐�
UINT WINAPI TFunc( LPVOID thParam );												//�f�[�^�ǂݍ��ݗp�X���b�h
