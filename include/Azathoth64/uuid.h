//
// Created by Fallin on 06.06.2024.
//

#ifndef AZATHOTH64_UUID_H
#define AZATHOTH64_UUID_H

#include <string>

namespace Azathoth64
{
    class UUID {
    public:
        static std::string generateUUID();
        static bool validateUUID(const std::string uuid);
    };

}

#endif //AZATHOTH64_UUID_H
