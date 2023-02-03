#ifndef LEARNCPP_PROTO2JSON_H
#define LEARNCPP_PROTO2JSON_H

#include<string>
#include <google/protobuf/message.h>

namespace weiyinfu {
    namespace proto2json {
        struct PrintOptions {
            int indent = -1;
            bool always_print_enums_as_ints = true;
            bool always_print_primitive_fields = true;
            bool preserve_proto_field_names = true;
        };

        std::string pb2jsonString(const google::protobuf::Message &msg, const proto2json::PrintOptions &options);
    }
}
#endif //LEARNCPP_PROTO2JSON_H
