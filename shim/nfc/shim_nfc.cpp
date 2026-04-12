#include <string>
#include <fstream>
#include <android/log.h>
#include <stdlib.h>
#include <sys/system_properties.h>

#define LOG_TAG "NFC_SHIM"

namespace android {
namespace base {

// Trim
std::string Trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\n\r");
    auto end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

// GetProperty (versão simplificada)
std::string GetProperty(const std::string& key, const std::string& def) {
    char value[PROP_VALUE_MAX];
    if (__system_property_get(key.c_str(), value) > 0) {
        return std::string(value);
    }
    return def;
}

// WriteStringToFile (fake simples)
bool WriteStringToFile(const std::string& content,
                       const std::string& path,
                       bool) {
    std::ofstream file(path);
    if (!file.is_open()) return false;
    file << content;
    file.close();
    return true;
}

} // namespace base

namespace hardware {
namespace details {

// logAlwaysFatal (evita crash)
void logAlwaysFatal(const char* msg) {
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "FATAL: %s", msg);
    abort(); // ou comenta se quiser evitar crash
}

} // namespace details
} // namespace hardware
}