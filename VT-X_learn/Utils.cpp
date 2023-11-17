#include "Utils.h"
#include"vmxDefine.h"
#include<intrin.h>
/// <summary>
/// 检测VT-BIOS是否支持
/// </summary>
/// <returns>支持</returns>
inline bool VmxCheckSupportedVTBios()
{
    ULONG64 msr=__readmsr(static_cast<unsigned long>(Msr::kIa32FeatureControl));
    return (msr & 0x5) == 0x5;

}
inline bool VmxCheckSupportedVTCpuId()
{
    int cpuInfo[4] = { -1 };
    __cpuidex(cpuInfo, 1,0);
    return (cpuInfo[2] & (1 << 5)) != 0;

}
inline bool VmxCheckSupportedCr4()
{
	ULONG64 cr4 = __readcr4();
	return (cr4 & (1 << 13)) != 0;
}
bool Utils::VmxIsSupported()
{
    if (!VmxCheckSupportedVTBios())
    {
        DbgPrintEx(77, 0, "VT-BIOS is not supported!\n");
		return false;
	}
    if (!VmxCheckSupportedVTCpuId())
    {
        DbgPrintEx(77,0,"VT-CPUID is not supported!\n");
        return false;
    }
    if (!VmxCheckSupportedCr4())
    {
        DbgPrintEx(77, 0, "VT-Cr4 is not supported!\n");
        return false;
    }

    return false;
}
