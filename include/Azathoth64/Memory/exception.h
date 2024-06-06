#ifndef AZATHOTH64_AREA_MEMORY_EXCEPTION_H
#define AZATHOTH64_AREA_MEMORY_EXCEPTION_H

#include <exception>

namespace Azathoth64::Memory::Exceptions
{

    class AreaDecreaseException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area is attempted to decrease its size smaller than the current one";
        }
    };
    class AreaIncreaseException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area is attempted to increase maximum size beyond current limit";
        }
    };
    /// @brief Arises if Area trying to re-allocate within the same pointer
    class AreaReallocationException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area trying to re-allocate within the same pointer";
        }
    };

    /// @brief Arises if the Area trying to beyond its boundaries
    class AreaBeyondBoundariesException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area tried beyond its boundaries";
        }
    };

    /// @brief Arises if label for the memory Area is empty
    class AreaInvalidUUIDException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area has invalid UUID";
        }
    };

    /// @brief Occurs if too much space is attempted to be allocated to the memory Area
    class AreaOverflowException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area are overflowed";
        }
    };

    /// @brief Occurs if the memory in the memory Area is unavailable or blocked
    class AreaInaccessibleException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Memory area are inaccessible";
        }
    };
}



#endif //AZATHOTH64_AREA_MEMORY_EXCEPTION_H
