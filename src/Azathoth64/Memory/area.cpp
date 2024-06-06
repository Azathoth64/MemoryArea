#include <sstream>
#include <azathoth64/memory/area.h>

using namespace Azathoth64::Memory;

Area::Area(const std::uint32_t max_size) {
    this->uuid = UUID::generateUUID();
    this->maxSize = max_size;
    this->currentSize = 0x00;
}

Area::Area(std::string &uuid, const std::uint32_t max_size) {
    if (!UUID::validateUUID(uuid)) uuid = UUID::generateUUID();

    this->uuid = uuid;
    this->maxSize = max_size;
    this->currentSize = 0x00;
}

Area::~Area() {
    for (void *element: this->storage) {
        free(element);
    }
}

void *Area::malloc(void *ptr) {
    if (maxSize < currentSize + sizeof(ptr)) throw Exceptions::AreaOverflowException();

    this->currentSize += sizeof(ptr);
    this->storage.push_front(ptr);

    return ptr;
}


void Area::free(void *ptr) {
    this->currentSize -= sizeof(ptr);
    this->storage.remove(ptr);
}

std::string Area::getUUID() const {
    return this->uuid;
}

void Area::increaseMaxSize(const std::uint32_t new_max_size) {
    if (this->maxSize < new_max_size)
        throw Exceptions::AreaIncreaseException();
    this->maxSize = new_max_size;
}

void Area::decreaseMaxSize(const std::uint32_t new_max_size) {
    if (this->maxSize > new_max_size)
        throw Exceptions::AreaDecreaseException();

    this->maxSize = new_max_size;
}

std::uint32_t Area::getMaxSize() const {
    return this->maxSize;
}

std::uint32_t Area::getCurrentSize() const {
    return this->currentSize;
}


std::string Area::toString() const noexcept {
    std::ostringstream oss;

    oss << "Azathoth64::Memory::Area UUID: " << this->uuid << ", Size: " << currentSize << "/" << maxSize << " bytes, Location: " <<
            reinterpret_cast<const void *>(this) << "\n";
    std::string tmp = oss.str();

    return tmp;
}
