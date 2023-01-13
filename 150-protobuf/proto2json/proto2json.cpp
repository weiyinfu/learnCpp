#include <google/protobuf/message.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/text_format.h>
#include <nlohmann/json.hpp>
#include "google/protobuf/reflection.h"
#include "google/protobuf/descriptor.h"
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

json pb2json(const Message &msg);

json parseFromRepeatField(const Message &msg,
                          const FieldDescriptor &field) {
    const Reflection *ref = msg.GetReflection();
    json json_array;
    json value;
    int size = ref->FieldSize(msg, &field);

    if (ref == nullptr || json_array == nullptr)
        return NULL;

    switch (field.cpp_type()) {

#define _GET_REPEAT_VALUE(cpptype, vtype, ctype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:                      \
    {                                                             \
        for (int i = 0; i < size; i++)                            \
        {                                                         \
            vtype get##ctype;                                     \
            get##ctype = ref->GetRepeated##ctype(msg, &field, i); \
            value = get##ctype;                         \
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

        case FieldDescriptor::CPPTYPE_BOOL:
            for (int i = 0; i < size; i++) {
                bool getBool;
                getBool = ref->GetRepeatedBool(msg, &field, i);
                if (getBool)
                    value = true;
                else
                    value = false;
                json_array.push_back(value);
            }
            break;

        case FieldDescriptor::CPPTYPE_ENUM:
            for (int i = 0; i < size; i++) {
                const EnumValueDescriptor *getEnum;
                getEnum = ref->GetRepeatedEnum(msg, &field, i);
                json_array.push_back(getEnum->number());
            }
            break;

        case FieldDescriptor::CPPTYPE_MESSAGE:
            for (int i = 0; i < size; i++) {
                const Message *subMsg = &ref->GetRepeatedMessage(msg, &field, i);
                if (subMsg->ByteSizeLong()) {
                    value = pb2json(*subMsg);
                    json_array.push_back(value);
                }
            }
            break;

        case FieldDescriptor::CPPTYPE_STRING: {
            for (int i = 0; i < size; i++) {
                string hexStr;
                string getString;
                getString = ref->GetRepeatedString(msg, &field, i);
                switch (field.type()) {
                    case FieldDescriptor::TYPE_STRING:
                        value = getString;
                        break;

                    case FieldDescriptor::TYPE_BYTES:
                        hexStr = hexEncode(getString);
                        value = hexStr;
                        break;

                    default:
                        break;
                }
                json_array.push_back(value);
            }
        }

            break;

        default:
            break;
    }

    return json_array;
}

json pb2json(const Message &msg) {
    const Descriptor *descriptor = msg.GetDescriptor();
    const Reflection *ref = msg.GetReflection();
    json json_obj;

    if (descriptor == nullptr || ref == nullptr)
        return NULL;

    for (int i = 0; i < descriptor->field_count(); i++) {
        const FieldDescriptor *field = descriptor->field(i);
        json value;

        if ((!field->is_repeated() && ref->HasField(msg, field)) ||
            (field->is_repeated() && ref->FieldSize(msg, field))) {

            const char *field_name = field->name().c_str();
            //TODO:json_name？
            double getDouble;
            float getFloat;
            int32_t getInt32;
            int64_t getInt64;
            uint32_t getUInt32;
            uint64_t getUInt64;
            bool getBool;
            const EnumValueDescriptor *getEnum;
            const Message *subMsg;
            string getString, hexStr;

            if (field->is_repeated()) {
                json repeat_field = parseFromRepeatField(msg, *field);
                json_obj[field_name] = repeat_field;
            } else {
                switch (field->cpp_type()) {

#define _GETVALUE(cpptype, ctype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:       \
    {                                              \
        get##ctype = ref->Get##ctype(msg, field); \
        value = get##ctype;              \
        break;                                     \
    }

                    _GETVALUE(DOUBLE, Double);
                    _GETVALUE(FLOAT, Float);
                    _GETVALUE(INT32, Int32);
                    _GETVALUE(INT64, Int64);
                    _GETVALUE(UINT32, UInt32);
                    _GETVALUE(UINT64, UInt64);

#undef _GETVALUE
                    case FieldDescriptor::CPPTYPE_BOOL:
                        getBool = ref->GetBool(msg, field);
                        if (getBool)
                            value = true;
                        else
                            value = false;
                        break;

                    case FieldDescriptor::CPPTYPE_ENUM:
                        getEnum = ref->GetEnum(msg, field);
                        //value = json_integer(getEnum->number());
                        value = getEnum->name();
                        break;

                    case FieldDescriptor::CPPTYPE_MESSAGE:
                        subMsg = &ref->GetMessage(msg, field);
                        value = pb2json(*subMsg);
                        break;

                    case FieldDescriptor::CPPTYPE_STRING: {
                        getString = ref->GetString(msg, field);

                        switch (field->type()) {
                            case FieldDescriptor::TYPE_STRING:
                                value = getString;
                                break;

                            case FieldDescriptor::TYPE_BYTES:
                                hexStr = hexEncode(getString);
                                value = hexStr;
                                break;

                            default:
                                break;
                        }
                        break;
                    }

                    default:
                        break;
                }
                json_obj[field_name] = value;
            }
        }
    }

    return json_obj;
}
