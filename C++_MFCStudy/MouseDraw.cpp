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

	// 아이콘 핸들
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	// 커서 핸들
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	// 배경 브러쉬 핸들 (흰 배경)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//(HPEN)GetStockObject(WHITE_PEN);

	// 메뉴 이름	
	WndClass.lpszMenuName = NULL;

	//윈도우 클래스 이름
	WndClass.lpszClassName = TEXT("MClass");

	if (!RegisterClass(&WndClass))
		return 1;

	// <-- 생성 -->

	hwnd = CreateWindow(
		TEXT("MClass"),					// 등록된 윈도우 클래스 이름
		TEXT("마우스로 그림그리기"),	// 타이틀바에 출력될 문자
		WS_OVERLAPPEDWINDOW,			// 윈도우 스타일
		CW_USEDEFAULT,					// 윈도우 좌측 상단의 x 좌표
		CW_USEDEFAULT,					// 윈도우 좌측 상단의 y 좌표
		CW_USEDEFAULT,					// 윈도우의 너비
		CW_USEDEFAULT,					// 윈도우의 높이
		NULL,							// 부모 윈도우의 핸들
		NULL,							// 메뉴 또는 자식 윈도우의 핸들
		hInstance,						// 어플리케이션 인스턴스 핸들
		NULL							// 윈도우 생성 데이터의 주소
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
