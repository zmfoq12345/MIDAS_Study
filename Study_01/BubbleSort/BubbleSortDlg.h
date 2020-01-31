
// BubbleSortDlg.h: 헤더 파일
//

#pragma once


// CBubbleSortDlg 대화 상자
class CBubbleSortDlg : public CDialogEx
{
// 생성입니다.
public:
	CBubbleSortDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUBBLESORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
#define len 4
	int m_n1;
	int m_n2;
	int m_n3;
	int m_n4;
	int m_n5;
	int m_n6;
	int m_n7;
	int m_n8;
	afx_msg void OnClickedButtonSort();
	afx_msg void OnClickedButtonExit();
	int* Bubble(int* nSource);
};
