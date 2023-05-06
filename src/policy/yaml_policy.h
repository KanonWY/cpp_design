#ifndef __KANON_YAML_POLICY_H__
#define __KANON_YAML_POLICY_H__

#include "policy.h"

namespace kanon
{

class YamlPolicy : public BasePolicy<YamlPolicy>
{
public:
    struct container_tag1
    {
    };

    struct container_error_tag
    {
    };

    template <typename T>
    struct TagDispatchTrait
    {
        using tag = container_error_tag;
    };

    template <>
    struct TagDispatchTrait<std::map<std::string, std::string>>
    {
        using tag = container_tag1;
    };

    template <typename C1>
    bool dealWithAllPublicConfig_imp_inner(C1 &container, container_tag1)
    {
        return true;
    }

    template <typename C1>
    bool dealWithAllPublicConfig_imp_inner(C1 &container, container_error_tag)
    {
        return false;
    }

    template <typename C1>
    bool dealWithAllPublicConfig_imp(C1 &container)
    {
        return dealWithAllPublicConfig_imp_inner(container, typename TagDispatchTrait<C1>::tag{});
    }
};

} // namespace kanon

#endif