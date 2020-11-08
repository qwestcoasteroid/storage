#ifndef CLOUD_STORAGE_STORED_DATA_FILE_HPP_
#define CLOUD_STORAGE_STORED_DATA_FILE_HPP_

#include <winbase.h>

#include <string>

#include "serializable.hpp"
#include "protocol.hpp"

namespace cloud_storage::stored_data {
    class File : public service::Serializable {
        using uint64_t = unsigned long long;
    public:
        inline File() noexcept {}
        File(const network::TransmissionUnit &_unit);

        std::pair<std::shared_ptr<char[]>, size_t> Serialize() const override;
        File &Deserialize(const std::shared_ptr<char[]> &_buffer) override;

        std::string name;
        uint64_t size{};
        SYSTEMTIME creation_time{};
        SYSTEMTIME editing_time{};
    };
} // namespace cloud_storage::stored_data

#endif // CLOUD_STORAGE_STORED_DATA_FILE_HPP_