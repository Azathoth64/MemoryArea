#include <azathoth64/uuid.h>

#include <random>
#include <sstream>
#include <iomanip>

std::string Azathoth64::UUID::generateUUID()
{
    std::random_device random_device;
    std::mt19937 seed(random_device());
    std::uniform_int_distribution<> generator(0, 15);

    std::stringstream tmp;
    for (int i = 0; i < 32; ++i) {
        const int random_number = generator(seed);
        if (i == 8 || i == 12 || i == 16 || i == 20) {
            tmp << '-';
        }
        tmp << std::hex << random_number;
    }
    return tmp.str();
}

bool Azathoth64::UUID::validateUUID(const std::string uuid)
{
    if (uuid.length() != 36) return false;

    for (int i = 0; i < 36; ++i) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            if (uuid[i] != '-') return false;
        } else {
            if (!std::isxdigit(uuid[i])) return false;
        }
    }

    return true;
}
