
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern HINSTANCE g_hInst;
extern UINT       g_DllRefCount;

class CClassFactory : public IClassFactory
{
protected:
	DWORD m_ObjRefCount;
public:
	CClassFactory();
	virtual ~CClassFactory();

	//IUnknown methods
	STDMETHODIMP QueryInterface(REFIID, LPVOID*);
	STDMETHODIMP_(DWORD) AddRef();
	STDMETHODIMP_(DWORD) Release();

	//IClassFactory methods
	STDMETHODIMP CreateInstance(LPUNKNOWN, REFIID, LPVOID*);
	STDMETHODIMP LockServer(BOOL) { return E_NOTIMPL; };
};

