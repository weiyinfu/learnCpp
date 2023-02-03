#include <google/protobuf/message.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/text_format.h>
#include <nlohmann/json.hpp>
#include "google/protobuf/reflection.h"
#include "google/protobuf/descriptor.h"
#include "proto2json.h"

namespace weiyinfu {
    namespace proto2json {
        using namespace std;
        using namespace google::protobuf::util;
        using namespace google::protobuf;
        using namespace nlohmann;

        string hexEncode(string binInput) {
            string hexOutput;
            char hByte, lByte;

            for (size_t i = 0; i < binInput.length(); i++) {
                hByte = binInput[i];
                lByte = hByte & 0x0f;

                hByte += 0x30;
                lByte += 0x30;

                if (hByte > 0x39)
                    hByte += 0x07;
                if (lByte > 0x39)
                    lByte += 0x07;

                hexOutput.push_back(hByte);
                hexOutput.push_back(lByte);
            }

            return hexOutput;
        }

        json pb2json(const Message &msg, const PrintOptions &options);

        json parseRepeated(const Message &msg, const FieldDescriptor &field, const PrintOptions &options);

        json parseRepeated(const Message &msg, const FieldDescriptor &field, const PrintOptions &options) {
            const Reflection *ref = msg.GetReflection();
            json json_array(json::array());
            int size = ref->FieldSize(msg, &field);
            switch (field.cpp_type()) {

#define _GET_REPEAT_VALUE(cpptype, vtype, ctype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:                      \
    {                                                             \
        for (int i = 0; i < size; i++)                            \
        {                                                         \
            vtype get##ctype;                                     \
            get##ctype = ref->GetRepeated##ctype(msg, &field, i); \
            auto value = get##ctype;                         \
            json_array.push_back(value);               \
        }                                                         \
        break;                                                    \
    }

                _GET_REPEAT_VALUE(DOUBLE, double, Double);
                _GET_REPEAT_VALUE(FLOAT, float, Float);
                _GET_REPEAT_VALUE(INT32, int32_t, Int32);
                _GET_REPEAT_VALUE(INT64, int64_t, Int64);
                _GET_REPEAT_VALUE(UINT32, uint32_t, UInt32);
                _GET_REPEAT_VALUE(UINT64, uint64_t, UInt64);

#undef _GET_REPEAT_VALUE

                case FieldDescriptor::CPPTYPE_BOOL: {
                    for (int i = 0; i < size; i++) {
                        bool getBool = ref->GetRepeatedBool(msg, &field, i);
                        json_array.push_back(getBool);
                    }
                    break;
                }
                case FieldDescriptor::CPPTYPE_ENUM: {
                    for (int i = 0; i < size; i++) {
                        const EnumValueDescriptor *getEnum;
                        getEnum = ref->GetRepeatedEnum(msg, &field, i);
                        json_array.push_back(getEnum->number());
                    }
                    break;
                }
                case FieldDescriptor::CPPTYPE_MESSAGE: {
                    //map是特殊类型的list
                    if (field.is_map()) {
                        json json_map(json::object());
                        for (int i = 0; i < size; i++) {
                            const Message *subMsg = &ref->GetRepeatedMessage(msg, &field, i);
                            if (subMsg->ByteSizeLong()) {
                                auto value = pb2json(*subMsg, options);
                                json_map[value["key"]] = value["value"];
                            }
                        }
                        return json_map;
                    }
                    for (int i = 0; i < size; i++) {
                        const Message *subMsg = &ref->GetRepeatedMessage(msg, &field, i);
                        if (subMsg->ByteSizeLong()) {
                            auto value = pb2json(*subMsg, options);
                            json_array.push_back(value);
                        }
                    }
                    break;
                }
                case FieldDescriptor::CPPTYPE_STRING: {
                    for (int i = 0; i < size; i++) {
                        string hexStr;
                        string getString;
                        getString = ref->GetRepeatedString(msg, &field, i);
                        json value;
                        switch (field.type()) {
                            case FieldDescriptor::TYPE_STRING: {
                                value = getString;
                                break;
                            }

                            case FieldDescriptor::TYPE_BYTES: {
                                hexStr = hexEncode(getString);
                                value = hexStr;
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                        json_array.push_back(value);
                    }
                    break;
                }
                default:
                    break;
            }

            return json_array;
        }

        json pb2json(const Message &msg, const PrintOptions &options) {
            const Descriptor *descriptor = msg.GetDescriptor();
            const Reflection *ref = msg.GetReflection();
            json json_obj;

            if (descriptor == nullptr || ref == nullptr) {
                return nullptr;
            }

            for (int i = 0; i < descriptor->field_count(); i++) {
                const FieldDescriptor *field = descriptor->field(i);
                const char *field_name = field->name().c_str();
                if (field->is_repeated()) {//包括list和map两种类型
                    json repeat_field = parseRepeated(msg, *field, options);
                    json_obj[field_name] = repeat_field;
                } else {
                    json value;
                    //基本数据类型
                    switch (field->cpp_type()) {

#define _GETVALUE(cpptype, ctype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:       \
    {                                              \
        value = ref->Get##ctype(msg, field); \
        break;                                     \
    }

                        _GETVALUE(DOUBLE, Double);
                        _GETVALUE(FLOAT, Float);
                        _GETVALUE(INT32, Int32);
                        _GETVALUE(INT64, Int64);
                        _GETVALUE(UINT32, UInt32);
                        _GETVALUE(UINT64, UInt64);
                        _GETVALUE(BOOL, Bool);
#undef _GETVALUE
                        case FieldDescriptor::CPPTYPE_ENUM: {
                            auto getEnum = ref->GetEnum(msg, field);
                            if (options.always_print_enums_as_ints) {
                                value = getEnum->number();
                            } else {
                                value = getEnum->name();
                            }
                            break;
                        }

                        case FieldDescriptor::CPPTYPE_MESSAGE: {
                            if (!ref->HasField(msg, field)) {
                                value = nullptr;
                                break;
                            }
                            auto subMsg = &ref->GetMessage(msg, field);
                            value = pb2json(*subMsg, options);
                            break;
                        }

                        case FieldDescriptor::CPPTYPE_STRING: {
                            auto getString = ref->GetString(msg, field);

                            switch (field->type()) {
                                case FieldDescriptor::TYPE_STRING: {
                                    value = getString;
                                    break;
                                }

                                case FieldDescriptor::TYPE_BYTES: {
                                    auto hexStr = hexEncode(getString);
                                    value = hexStr;
                                    break;
                                }

                                default: {
                                    break;
                                }
                            }
                            break;
                        }

                        default: {
                            break;
                        }
                    }
                    json_obj[field_name] = value;
                }
            }

            return json_obj;
        }

        string pb2jsonString(const Message &msg, const PrintOptions &options) {
            auto x = pb2json(msg, options);
            return x.dump(options.indent);
        }
    }
}
