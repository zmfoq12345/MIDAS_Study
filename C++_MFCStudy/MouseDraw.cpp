#define _AFXDLL

#include <windows.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS WndClass;
	HWND hwnd;
	MSG msg;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;

	// ������ �ڵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	// Ŀ�� �ڵ�
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	// ��� �귯�� �ڵ� (�� ���)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//(HPEN)GetStockObject(WHITE_PEN);

	// �޴� �̸�	
	WndClass.lpszMenuName = NULL;

	//������ Ŭ���� �̸�
	WndClass.lpszClassName = TEXT("MClass");

	if (!RegisterClass(&WndClass))
		return 1;

	// <-- ���� -->

	hwnd = CreateWindow(
		TEXT("MClass"),					// ��ϵ� ������ Ŭ���� �̸�
		TEXT("���콺�� �׸��׸���"),	// Ÿ��Ʋ�ٿ� ��µ� ����
		WS_OVERLAPPEDWINDOW,			// ������ ��Ÿ��
		CW_USEDEFAULT,					// ������ ���� ����� x ��ǥ
		CW_USEDEFAULT,					// ������ ���� ����� y ��ǥ
		CW_USEDEFAULT,					// �������� �ʺ�
		CW_USEDEFAULT,					// �������� ����
		NULL,							// �θ� �������� �ڵ�
		NULL,							// �޴� �Ǵ� �ڽ� �������� �ڵ�
		hInstance,						// ���ø����̼� �ν��Ͻ� �ڵ�
		NULL							// ������ ���� �������� �ּ�
	);
	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;

	static POINT MousePos;

	static BOOL bDrawing = FALSE;

	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		MousePos.x = LOWORD(lParam);
		MousePos.y = HIWORD(lParam);
		bDrawing = TRUE;
		SetCapture(hWnd);
		return 0;
	
	case WM_LBUTTONUP:
		bDrawing = FALSE;
		ReleaseCapture();
		return 0;

	case WM_MOUSEMOVE:
		if (bDrawing == TRUE) {
			hdc = GetDC(hWnd);
			MoveToEx(hdc, MousePos.x, MousePos.y, NULL);
			MousePos.x = LOWORD(lParam);
			MousePos.y = HIWORD(lParam);
			LineTo(hdc, MousePos.x, MousePos.y);
			ReleaseDC(hWnd, hdc);
		}
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
