/*-----------------------------------------------------------------------------
	�s�N�`���[�{�b�N�X�ւ̕`��v���O�����i�T���v��2�j

	���X��
	/*******
	(���ɋL�q)
	********
	�Ƃ����ӏ�������̂ł����������߂��Ă���


  �@�uOK�v�{�^�����������ƃs�N�`���[�{�b�N�X���ɃE�B���h�E���쐬���C�~�Ȃǂ�`��D
  �@���W�I�{�^����I�����邱�Ƃŉ~���̐F���ω�����D

-----------------------------------------------------------------------------*/
#include <windows.h>		//Windows��
#include <windowsx.h>		//Windows��

#include "header.h"			//�w�b�_�[�t�@�C��
#include "resource.h"		//���\�[�X�t�@�C��

//�萔�錾
#define DEF_APP_NAME	TEXT("Waveform Test")
#define DEF_MUTEX_NAME	DEF_APP_NAME			//�~���[�e�b�N�X��

//======================================
//��������_�C�A���O�o�[�W����

//���C���֐�(�_�C�A���O�o�[�W����)
//�����͓��ɂ�����Ȃ���OK
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HANDLE hMutex;		

	//���d�N������
	hMutex = CreateMutex(NULL, TRUE, DEF_MUTEX_NAME);		//�~���[�e�b�N�X�I�u�W�F�N�g�̐���
	if(GetLastError() == ERROR_ALREADY_EXISTS){				//2�d�N���̗L�����m�F
		MessageBox(NULL, TEXT("���ɋN������Ă��܂��D"), NULL, MB_OK|MB_ICONERROR);
		return 0;											//�I��
	}

	//�_�C�A���O�N��
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAINDIALOG), NULL, MainDlgProc);

	return FALSE;			//�I��
}

//�ҏW����̂͂�������

//���C���v���V�[�W���i�_�C�A���O�j
/********************************

�V�X�e����ʁi.rc�t�@�C���j�ɔz�u�����{�^�����������ꂽ�Ƃ���C
�������C�I�����ɂǂ̂悤�ȏ������s�����������ɋL�q����D

********************************/
BOOL CALLBACK MainDlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	static HWND hPict;		//�E�B���h�E�n���h���iPictureBox�j
	static HWND hWnd;		//�q�E�B���h�E�n���h��

	switch(uMsg){
	case WM_INITDIALOG:		//�_�C�A���O������(exe���_�u���N���b�N������)
		

		/*******
		�V�X�e����ʁi.rc�t�@�C���j�Ɏ����Œǉ������{�^����Picture Control��
		�͕K��HWND�^��GetDlgItem�֐���p���ăn���h�����擾���܂��D
		
		��FhWnd = GetDlgItem(hDlg, ID);
		hWnd�F�擾�������n���h��
		hDlg�F�_�C�A���O�̃n���h���D�����͊�{�I�ɂ��̂܂�
		ID�F�擾�������n���h���̑ΏۂƂȂ�{�^����Picture Control��
		    ��ID�D.rc�t�@�C������m�F�ł���D�ڍׂ͔z�z�������Q�l



		�����Ńw�b�_�����Ă݂�ƁChRadioR�EhRadioG�EhRadioB�Ƃ����n���h�����錾
		����Ă��܂��D
		��������ꂼ��V�X�e����ʏ�̃��W�I�{�^���ԁE�΁E�ɑΉ�����悤��
		�錾���Ă݂܂��傤�D
	   ********/
		//��������


		hRadioR = GetDlgItem(hDlg, IDC_RADIO1);
		hRadioG = GetDlgItem(hDlg, IDC_RADIO2);
		hRadioB = GetDlgItem(hDlg, IDC_RADIO3);


		//�����܂�
		Button_SetCheck(hRadioR, BST_CHECKED);		//�f�t�H���g�ŐԂ��`�F�b�N
		SendMessage(hDlg,WM_COMMAND,(WPARAM)IDC_RADIO1,0);	//
		return TRUE;

	case WM_COMMAND:		//�{�^���������ꂽ��
		/*******
		case WM_COMMAND:�ł͊e�{�^���������ꂽ�Ƃ��̏������L�ڂ��܂��D
	   ********/
		switch(LOWORD(wParam)){
		case ID_OK:			//OK�{�^��
			/***********************
			OK�{�^���������ꂽ�Ƃ��ɕ`����J�n���܂��D
			�`����J�n���邽�߂ɂ�PictureControl�̃n���h�����擾����K�v������܂�
			�����Q�l�Ƀn���h�� hPict��GetDlgItem�֐���p���Ď擾���܂��傤�D
			***********************/
			//��������
					

			hPict = GetDlgItem(hDlg, ID_OK);


            //�����܂�	
			WinInitialize(NULL,hDlg, (HMENU)110, "TEST", hPict, WndProc, &hWnd); //������
			//WinInitialize�֐��ɂ���Ďq�E�B���h�E�v���V�[�W����hPict��hWnd�Ƃ��ăZ�b�g����܂����D
			return TRUE;

		case ID_END:		//�L�����Z���{�^��
			EndDialog(hDlg, 0);		//�_�C�A���O�I��
			return TRUE;

        /***********************
		�ȉ��Ƀ��W�I�{�^���������ꂽ�Ƃ��̏������L�ڂ��܂��D
		
		color = RGB(255,0,0); �ƋL�q���邱�Ƃ�PictureControl�ɕ`�悷��F��ݒ肵�܂��D
		�ݒ���InvalidateRect(hWnd, NULL, TRUE );�Ƃ��邱�ƂŁC
		�q�E�B���h�E�v���V�[�W���ɕ`�施�߂������܂��D

		���W�I�{�^���i�ԁj���Q�l�Ƀ��W�I�{�^���i�΁C�j���L�ڂ��܂��傤
	    ***********************/

		case IDC_RADIO1:	//���W�I�{�^���i�ԁj
			color = RGB(255,0,0);				//�F�w��
			InvalidateRect(hWnd, NULL, TRUE );	//�ĕ`��
			return TRUE;

		//��������
		

		case IDC_RADIO2:	//���W�I�{�^���i�΁j
			color = RGB(0, 255, 0);				//�F�w��
			InvalidateRect(hWnd, NULL, TRUE);	//�ĕ`��
			return TRUE;

		case IDC_RADIO3:	//���W�I�{�^���j
			color = RGB(0, 0, 255);				//�F�w��
			InvalidateRect(hWnd, NULL, TRUE);	//�ĕ`��
			return TRUE;


        //�����܂�
		}
		break;



	case WM_CTLCOLORDLG:	//�_�C�A���O�w�i�`��
		return ((BOOL)GetStockObject(WHITE_BRUSH));			//�_�C�A���O�w�i�𔒂�
	
    case WM_CLOSE:
        EndDialog(hDlg, 0);			//�_�C�A���O�I��
        return TRUE;
    }

	SendMessage(hWnd,uMsg,wParam,lParam);

	//�I�[�i�[�`���ɍĕ`��
	if (uMsg==WM_PAINT){
		InvalidateRect(hWnd, NULL, TRUE );	//�ĕ`��
	}

  return FALSE;
}

/********************************

������PictureControl�̕`����s���܂��D

�q�E�B���h�E�v���V�[�W������hWnd��PictureControl�̃n���h���ł��D

********************************/
//�q�E�B���h�E�v���V�[�W��
HRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{

	HDC			hdc;				//�f�o�C�X�R���e�L�X�g�̃n���h��
	PAINTSTRUCT ps;					//(�\����)�N���C�A���g�̈�`�悷�邽�߂̏��	
	HBRUSH		hBrush, hOldBrush ;	//�u���V
	HPEN		hPen, hOldPen;		//�y��

	switch(uMsg){
	case WM_CREATE:	
		colorPen = RGB(0, 0, 0);	//�F�w��
		//colorPen = color;	//�F�w��
		break;

	case WM_PAINT:
		
		/********************************

		PictureControl�ɕ`�悷�邽�߂ɂ́CHDC�^�̃n���h����ʂɎ擾����
		�K�v������܂��D

		��Fhdc = BeginPaint(hWnd, &ps);
		hdc:�f�o�C�X�R���e�L�X�g�̃n���h��
		hWnd:PictureControl�̃n���h��
		ps�F(�\����)�N���C�A���g�̈�`�悷�邽�߂̏��	

		********************************/

		hdc = BeginPaint(hWnd, &ps);//�f�o�C�X�R���e�L�X�g�̃n���h���擾

		/********************************

		PictureControl�ɕ`�悷�邽�߂ɂ́C�������������Ƃ��̓y���C
		�h��Ԃ��ۂɂ̓u���V���K�v�ł��D
		
		********************************/

		//�y���C�u���V����
		hBrush = CreateSolidBrush(color);				//�u���V����
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);	//�u���V�ݒ�
		hPen = CreatePen(PS_SOLID, 2, colorPen);		//�y������
		hOldPen = (HPEN)SelectObject(hdc, hPen);		//�y���ݒ�

		//�`��
		/********************************

		�}�`��`�悷�邽�߂ɂ͈ȉ��̊֐���p���܂��D
		�����`�FRectangle(HDC hdc ,int nLeftRect , int nTopRect ,int nRightRect , int nBottomRect);
		�~�FEllipse(HDC hdc ,int nLeftRect , int nTopRect ,int nRightRect , int nBottomRect);
		 
		 nLiftRect�F�����`�̍���X���W
		  nTopRect�F����Y���W
          nRightRect�F�E��X���W
		  nBottomRect�F�E����Y���W

		���������ɂ͈ȉ��̊֐���p���܂��D

		���̎n�_�ݒ�FMoveToEx(HDC hdc , int X , int Y , NULL);
		  X,Y�F���̎n�_�̍��W
		���GLineTo(HDC hdc , int nXEnd , int nYEnd);
		  nXEnd, nYEnd�F���̏I�_�̐ݒ�


		  �ȏ���Q�l�ɐ}�`��`�悷��֐����ȉ��ɋL�q���܂��傤
		********************************/
		//��������

		
		Rectangle(hdc, 0, 0, wParam, lParam);
		Ellipse(hdc, 0, 0, wParam, lParam);



        //�����܂�

		TextOut(hdc, 10, 10, TEXT("Maru"),4);		//�e�L�X�g�`��

		//�y���C�u���V�p��
		/********************************

		�g���I������y���ƃu���V�͔j������K�v������܂��D
		
		********************************/
		SelectObject(hdc, hOldBrush );
		DeleteObject( hBrush );
		SelectObject(hdc, hOldPen );
		DeleteObject( hPen );

		//�f�o�C�X�R���e�L�X�g�̃n���h���j��
		EndPaint(hWnd, &ps);
		break;
	}

	return TRUE;
}

//�����܂�

//-----------------------------------------------------------------------------
//�q�E�B���h�E������������
//�w�肵���E�B���h�E�n���h���̗̈�Ɏq�E�B���h�E�𐶐�����D
//----------------------------------------------------------
// hInst	: �����p�C���X�^���X�n���h��
// hPaWnd	: �e�E�B���h�E�̃n���h��
// chID		: �q�E�B���h�E��ID
// cWinName	: �q�E�B���h�E��
// PaintArea: �q�E�B���h�E�𐶐�����̈�̃f�o�C�X�n���h��
// WndProc	: �E�B���h�E�v���V�[�W��
// *hWnd	: �q�E�B���h�E�̃n���h���i�|�C���^�j
// �߂�l	: ������=true
//-----------------------------------------------------------------------------
BOOL WinInitialize( HINSTANCE hInst, HWND hPaWnd, HMENU chID, char *cWinName, HWND PaintArea, WNDPROC WndProc ,HWND *hWnd)
{
	WNDCLASS wc;			//�E�B���h�E�N���X
	WINDOWPLACEMENT	wplace;	//�q�E�B���h�E�����̈�v�Z�p�i��ʏ�̃E�B���h�E�̔z�u�����i�[����\���́j
	RECT WinRect;			//�q�E�B���h�E�����̈�
	ATOM atom;				//�A�g��

	//�E�B���h�E�N���X������
	wc.style		=CS_HREDRAW ^ WS_MAXIMIZEBOX | CS_VREDRAW;	//�E�C���h�E�X�^�C��
	wc.lpfnWndProc	=WndProc;									//�E�C���h�E�̃��b�Z�[�W����������R�[���o�b�N�֐��ւ̃|�C���^
	wc.cbClsExtra	=0;											//
	wc.cbWndExtra	=0;
	wc.hCursor		=NULL;										//�v���O�����̃n���h��
	wc.hIcon		=NULL;										//�A�C�R���̃n���h��
	wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);		//�E�C���h�E�w�i�F
	wc.hInstance	=hInst;										//�E�C���h�E�v���V�[�W��������C���X�^���X�n���h��
	wc.lpszMenuName	=NULL;										//���j���[��
	wc.lpszClassName=(LPCTSTR)cWinName;									//�E�C���h�E�N���X��

	if(!(atom=RegisterClass(&wc))){
		MessageBox(hPaWnd,TEXT("�E�B���h�E�N���X�̐����Ɏ��s���܂����D"),NULL,MB_OK|MB_ICONERROR);
		return false;
	}

	GetWindowPlacement(PaintArea,&wplace);	//�`��̈�n���h���̏����擾(�E�B���h�E�̕\����Ԃ��擾)
	WinRect=wplace.rcNormalPosition;		//�`��̈�̐ݒ�

	//�E�B���h�E����
	*hWnd=CreateWindow(
		(LPCTSTR)atom,
		(LPCTSTR)cWinName,
		WS_CHILD | WS_VISIBLE,//| WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME |WS_VISIBLE, 
		WinRect.left,WinRect.top,
		WinRect.right-WinRect.left,WinRect.bottom-WinRect.top,
		hPaWnd,chID,hInst,NULL
	);

	if( *hWnd==NULL ){
		MessageBox(hPaWnd,TEXT("�E�B���h�E�̐����Ɏ��s���܂����D"),NULL,MB_OK|MB_ICONERROR);
		return false;
	}

	return true;
}


//
////======================================
////��������E�B���h�E�o�[�W����
//
////�X�N���[���T�C�Y(�E�B���h�E�o�[�W�����Ŏg�p)
//#define DEF_SCR_WIDTH	1024
//#define DEF_SCR_HEIGHT	768
//
//BOOL WinInitialize( HINSTANCE hInst, char *cWinName, int Width, int Height, WNDPROC WndProc );
//
////���C���֐�(�E�B���h�E�o�[�W����)
//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
//{
//	HANDLE hMutex;
//
//	hMutex=CreateMutex(NULL,TRUE,DEF_MUTEX_NAME);
//	if( GetLastError()==ERROR_ALREADY_EXISTS){
//		MessageBox(NULL,TEXT("�v���O�����͊��ɋN������Ă��܂��D"),NULL,MB_OK|MB_ICONERROR);
//		return 0;
//	}
//	
//	//�E�B���h�E����
//	WinInitialize(hInstance,DEF_APP_NAME,DEF_SCR_WIDTH,DEF_SCR_HEIGHT,WndProc);
//
//	return 0;
//}
//
////���C���v���V�[�W���i�E�B���h�E�p�j
//HRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	switch(uMsg){
//	case WM_CREATE:
//	//	InvalidateRect(hWnd,NULL,TRUE);
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//
//		return 0;
//	case WM_KEYDOWN:
//		switch(wParam){
//		case VK_ESCAPE:
//			SendMessage(hWnd,WM_CLOSE,0,0);
//		}
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		Ellipse(hdc, 10, 10, 20, 100);
//
//		EndPaint(hWnd, &ps);
//		return 0;
//	}
//	
//	return DefWindowProc(hWnd,uMsg,wParam,lParam);
//}
//
////-----------------------------------------------------------------------------
////�E�B���h�E������������
////hInst: �����p�C���X�^���X�n���h��
////cWinName: �E�B���h�E��
////Width: ��(mm)
////Height: ����(mm)
////WndProc: �E�B���h�E�v���V�[�W��
////�߂�l: ������=true
////-----------------------------------------------------------------------------
//BOOL WinInitialize( HINSTANCE hInst, char *cWinName, int Width, int Height, WNDPROC WndProc )
//{
//	WNDCLASS wc;			//�E�B���h�E�N���X
//	HWND hWnd;				//�E�B���h�E�n���h��
//	ATOM atom;				//�A�g��
//	MSG msg;
//
//	//�E�B���h�E�N���X������
//	wc.style		= CS_HREDRAW ^ WS_MAXIMIZEBOX | CS_VREDRAW;
//	wc.lpfnWndProc	=WndProc;
//	wc.cbClsExtra	=0;
//	wc.cbWndExtra	=0;
//	wc.hCursor		=NULL;
//	wc.hIcon		=NULL;
//	wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
//	wc.hInstance	=hInst;
//	wc.lpszMenuName	=NULL;
//	wc.lpszClassName=cWinName;
//
//	if(!(atom=RegisterClass(&wc))){
//		MessageBox(NULL,TEXT("�E�B���h�E�N���X�̐����Ɏ��s���܂����D"),NULL,MB_OK|MB_ICONERROR);
//		return false;
//	}
//
//	//�E�B���h�E����
//	hWnd=CreateWindow(
//		(LPCTSTR)atom,
//		cWinName,
//		WS_OVERLAPPEDWINDOW|WS_VISIBLE,
//		0,0,Width,Height,
//		NULL,NULL,hInst,NULL
//	);
//
//	if( hWnd==NULL ){
//		MessageBox(NULL,TEXT("�E�B���h�E�̐����Ɏ��s���܂����D"),NULL,MB_OK|MB_ICONERROR);
//		return false;
//	}
//	
//	while(GetMessage(&msg, NULL, 0, 0) > 0){
//		DispatchMessage(&msg);
//	}
//	return true;
//}*/
//