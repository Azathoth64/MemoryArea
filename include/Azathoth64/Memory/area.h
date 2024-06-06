#ifndef AZATHOTH64_MEMORY_AREA_H
#define AZATHOTH64_MEMORY_AREA_H

#include <string>
#include <cstdint>
#include <list>

#include <azathoth64/uuid.h>
#include <azathoth64/memory/exception.h>

#define KB(bytes) (std::size_t)(bytes << 10)
#define MB(bytes) (std::size_t)(bytes << 20)
#define GB(bytes) (std::size_t)(bytes << 30)

#define AZ_AREA_SIZE 3E8

namespace Azathoth64::Memory {


    /// @brief memory container who allocates and deallocates RAM.
    /// @example Area area();
    ///          Cat *john = Area.allocate(new Cat("John"));
    ///          Area.free(john);
    /// @exception runtime_error arrives when
    class Area {
    public:
        // Constructors and Destructors:
        explicit Area(const std::uint32_t max_size = AZ_AREA_SIZE);
        explicit Area(std::string &uuid, const std::uint32_t max_size = AZ_AREA_SIZE);
        ~Area();

        void *malloc(void *ptr);
        void free(void *ptr);

        void increaseMaxSize(const std::uint32_t new_max_size);
        void decreaseMaxSize(const std::uint32_t new_max_size);

        std::uint32_t getCurrentSize() const;
        std::string getUUID() const;
        std::uint32_t getMaxSize() const;

        std::string toString() const noexcept;

    private:
        std::string uuid;
        std::uint32_t currentSize;
        std::uint32_t maxSize;
        std::list<void *> storage;
    };
}


#endif
