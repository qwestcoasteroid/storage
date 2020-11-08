#ifndef CLOUD_STORAGE_STORED_DATA_MESSAGE_HPP_
#define CLOUD_STORAGE_STORED_DATA_MESSAGE_HPP_

#include "serializable.hpp"
#include "protocol.hpp"

namespace cloud_storage::stored_data {
    class Message : public service::Serializable {
    public:
        inline Message() noexcept {}
        Message(const network::TransmissionUnit &_unit);

        std::pair<std::shared_ptr<char[]>, size_t> Serialize() const override;
        Message &Deserialize(const std::shared_ptr<char[]> &_buffer) override;

        std::string msg;
        std::string sender;
    };
} // cloud_storage::stored_data

#endif // CLOUD_STORAGE_STORED_DATA_MESSAGE_HPP_