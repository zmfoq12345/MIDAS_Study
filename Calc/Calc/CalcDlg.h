
// CalcDlg.h: 헤더 파일
//

#pragma once


// CCalcDlg 대화 상자
class CCalcDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalcDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
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
	int m_nOption;
	CString m_nNum1;
	CString m_nNum2;
	CString m_nResult;
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonDiv();
	afx_msg void OnClickedButtonEqu();
	afx_msg void OnClickedButtonMul();
	afx_msg void OnClickedButtonSub();
	afx_msg void OnClickedButtonQuit();
	afx_msg void OnClickedButtonReset();
};
