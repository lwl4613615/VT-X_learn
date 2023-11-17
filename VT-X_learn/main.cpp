#include<ntifs.h>


EXTERN_C_START
	NTSTATUS DriverMain(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
EXTERN_C_END

void DriverUnload(PDRIVER_OBJECT pDriverObject)
{
	UNREFERENCED_PARAMETER(pDriverObject);
}
NTSTATUS DriverMain(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pRegistryPath);
	pDriverObject->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}