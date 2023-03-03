#include <mast1c0re.hpp>

void main()
{
    PS::Debug.connect(IP(192, 168, 1, 155), 9023);

    char version[256];
    uint32_t ps4_sdk_version, sdk_version, upd_version;
    size_t olden;

    olden = sizeof(version);
    PS::Sce::Kernel::Sysctlbyname("kern.version", (char *)&version, &olden, NULL, 0);
    PS::Debug.printf("%s\n", version);

    olden = sizeof(ps4_sdk_version);
    PS::Sce::Kernel::Sysctlbyname("kern.ps4_sdk_version", (char *)&ps4_sdk_version, &olden, NULL, 0);
    PS::Debug.printf("kern.ps4_sdk_version: 0x%lx\n", ps4_sdk_version);

    olden = sizeof(sdk_version);
    PS::Sce::Kernel::Sysctlbyname("kern.sdk_version", (char *)&sdk_version, &olden, NULL, 0);
    PS::Debug.printf("kern.sdk_version; 0x%lx\n", sdk_version);

    olden = sizeof(upd_version);
    PS::Sce::Kernel::Sysctlbyname("machdep.upd_version", (char *)&upd_version, &olden, NULL, 0);
    PS::Debug.printf("machdep.upd_version: 0x%lx\n", upd_version);

    PS::notification("kern.version: %s\nkern.ps4_sdk_version: 0x%lx\nkern.sdk_version: 0x%lx\nmachdep.upd_version: 0x%lx", version, ps4_sdk_version, sdk_version, upd_version);

    PS::Debug.disconnect();
}