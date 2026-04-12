#include <stdint.h>
#include <log/log.h>

// Declaração mínima sem depender de headers do framework
typedef struct ALooper ALooper;

extern "C" {

// =============================================
// ALooper for Camera (Android 14+ changes)
// =============================================

ALooper* ALooper_forCamera(void) {
    ALOGE("shim: ALooper_forCamera");
    return (ALooper*)0x1;        // ponteiro fake não-nulo
}

int ALooper_pollOnce_camera(ALooper* looper, int timeoutMillis,
                            int* outFd, int* outEvents, void** outData) {
    ALOGE("shim: ALooper_pollOnce_camera (timeout)");

    if (outFd) *outFd = -1;
    if (outEvents) *outEvents = 0;
    if (outData) *outData = nullptr;

    return -1;   // retorna TIMEOUT (comportamento mais seguro)
}

void ALooper_release_forCamera(ALooper* looper) {
    ALOGE("shim: ALooper_release_forCamera");
    // Não faz nada (é fake)
}

} // extern "C"