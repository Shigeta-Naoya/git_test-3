//-------------------------------------------------------------------------
//	main.cpp�t�@�C���̃w�b�_�[�t�@�C��
//	
//	�֐��C�ϐ��錾�p
//-------------------------------------------------------------------------

//�֐��錾
BOOL CALLBACK MainDlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );	//���C���_�C�A���O�v���V�[�W��
BOOL WinInitialize( HINSTANCE hInst, HWND hPaWnd, HMENU chID, char *cWinName, HWND PaintArea, WNDPROC WndProc ,HWND *hDC);//�q�E�B���h�E�𐶐�
HRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );		//�q�E�B���h�E�v���V�[�W��

//�ϐ��錾
//���W�I�{�^���̃n���h��
static HWND hRadioR;		//�E�B���h�E�n���h���i���W�I�{�^���j
static HWND hRadioG;		//�E�B���h�E�n���h���i���W�I�{�^���j
static HWND hRadioB;		//�E�B���h�E�n���h���i���W�I�{�^���j	

static COLORREF	color, colorPen;	//�F