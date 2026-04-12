#include <stdint.h>
#include <log/log.h>

// Usamos void* para não depender de headers do framework
extern "C" {

// =======================
// lock (versão completa - a que está dando erro)
int _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPvPiS9_(
    const void* handle,
    uint32_t usage,
    const void* rect,
    void** vaddr,
    int* bytesPerPixel,
    int* bytesPerStride)
{
    ALOGE("shim: GraphicBufferMapper::lock (full)");
    if (vaddr) *vaddr = nullptr;
    if (bytesPerPixel) *bytesPerPixel = 0;
    if (bytesPerStride) *bytesPerStride = 0;
    return 0;
}

// =======================
// lock (versão antiga)
int _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(
    void* thiz,
    const void* handle,
    uint32_t usage,
    const void* rect,
    void** vaddr)
{
    ALOGE("shim: GraphicBufferMapper::lock (old)");
    if (vaddr) *vaddr = nullptr;
    return 0;
}

// =======================
// lockAsync
int _ZN7android19GraphicBufferMapper9lockAsyncEPK13native_handlemmRKNS_4RectEPPviPiS9_(
    const void* handle,
    uint64_t usage,
    uint64_t /*usage2*/,
    const void* rect,
    void** vaddr,
    int* fence,
    int* bytesPerPixel,
    int* bytesPerStride)
{
    ALOGE("shim: GraphicBufferMapper::lockAsync");
    if (vaddr) *vaddr = nullptr;
    if (fence) *fence = -1;
    if (bytesPerPixel) *bytesPerPixel = 0;
    if (bytesPerStride) *bytesPerStride = 0;
    return 0;
}

// =======================
// unlock
int _ZN7android19GraphicBufferMapper6unlockEPK13native_handle(
    const void* handle)
{
    ALOGE("shim: GraphicBufferMapper::unlock");
    return 0;
}

} // extern "C"