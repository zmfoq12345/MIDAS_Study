//#include <windows.h>
//
//#include <TCHAR.H>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	WNDCLASS WndClass;
//	HWND hwnd;
//	MSG msg;
//
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	
//	// 아이콘 핸들
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//
//	// 커서 핸들
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//
//	// 배경 브러쉬 핸들 (흰 배경)
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//
//	// 메뉴 이름	
//	WndClass.lpszMenuName = NULL;
//
//	//윈도우 클래스 이름
//	WndClass.lpszClassName = TEXT("MouseClass");
//
//	if (!RegisterClass(&WndClass))
//		return 1;
//
//	// <-- 생성 -->
//
//	hwnd = CreateWindow(
//		TEXT("MouseClass"),		// 등록된 윈도우 클래스 이름
//		TEXT("MouseSDK"),		// 타이틀바에 출력될 문자
//		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
//		CW_USEDEFAULT,			// 윈도우 좌측 상단의 x 좌표
//		CW_USEDEFAULT,			// 윈도우 좌측 상단의 y 좌표
//		CW_USEDEFAULT,			// 윈도우의 너비
//		CW_USEDEFAULT,			// 윈도우의 높이
//		NULL,					// 부모 윈도우의 핸들
//		NULL,					// 메뉴 또는 자식 윈도우의 핸들
//		hInstance,				// 어플리케이션 인스턴스 핸들
//		NULL					// 윈도우 생성 데이터의 주소
//	);
//	ShowWindow(hwnd, nCmdShow);
//	
//	while (GetMessage(&msg, NULL, 0, 0)>0)
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	HDC hdc;
//	PAINTSTRUCT ps;
//	TCHAR str1[200] = TEXT("마우스를 클릭하세요");
//	TCHAR str2[200] = TEXT("오른쪽 마우스 / 왼쪽 마우스를 클릭하시면 메시지 상자가 나타납니다.");
//
//	switch (message)
//	{
//	case WM_CREATE:
//		return 0;
//
//	case WM_LBUTTONDOWN:
//		MessageBox(hwnd, TEXT("왼쪽 마우스를 클릭하셨습니다."), TEXT("왼쪽 마우스 클릭!"), MB_OK);
//		return 0;
//
//	case WM_RBUTTONDOWN:
//		MessageBox(hwnd, TEXT("오른쪽 마우스를 클릭하셨습니다."), TEXT("오른쪽 마우스 클릭!"), MB_OK);
//		return 0;
//
//	case WM_MOUSEWHEEL:
//		MessageBox(hwnd, TEXT("마우스 휠이 움직였습니다."), TEXT("마우스 휠 움직임!"), MB_OK);
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		TextOut(hdc, 100, 100, str1, lstrlen(str1));
//		TextOut(hdc, 100, 200, str2, lstrlen(str2));
//		EndPaint(hwnd, &ps);
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hwnd, message, wParam, lParam);
//}
