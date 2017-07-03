// NiGetSerinalNumber.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "NiGetSerinalNumber.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MAX_STR_SIZE 128

using namespace std;
using namespace xn;

// �Ȧ����@�����ε{������

CWinApp theApp;

using namespace std;

void showSerialNumber() {
    Context mContext;
    mContext.Init();

    Device mDevice;
    XnStatus status;
    status = mDevice.Create(mContext);
    if ( XN_STATUS_OK == status ) {
        DeviceIdentificationCapability mDeviceIdentCap = mDevice.GetIdentificationCap();
        XnChar strBuff[MAX_STR_SIZE] = {0};
        XnUInt32 strBuffSize = MAX_STR_SIZE;

        //cout << "GetName : " << mDeviceIdentCap.GetName() << endl;
        status = mDeviceIdentCap.GetSerialNumber( strBuff, strBuffSize );
        if ( XN_STATUS_OK == status ) {
            //cout << "GetSerialNumber : " << strBuff << endl;
            CString cstr(strBuff);
            MessageBox( nullptr, cstr, TEXT( "Serial Number" ), MB_OK );
        }
    } else {
        cout << "mDevice crate not ok" << endl;
    }
    mDevice.Release();
    mContext.Release();
    return;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��l�� MFC �é󥢱ѮɦC�L���~
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: �t�X�z���ݭn�ܧ���~�X
			_tprintf(_T("�Y�����~: MFC ��l�ƥ���\n"));
			nRetCode = 1;
		}
		else
		{
			showSerialNumber();
		}
	}
	else
	{
		// TODO: �t�X�z���ݭn�ܧ���~�X
		_tprintf(_T("�Y�����~: GetModuleHandle ����\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
