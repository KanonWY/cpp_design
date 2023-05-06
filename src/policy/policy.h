#ifndef __KANON_POLICY_H__
#define __KANON_POLICY_H__

#include <optional>
#include <string>
#include <map>

namespace kanon
{

/**
 *  @brief CRPT BasePolicy
*/

template <typename D>
class BasePolicy
{
public:
    BasePolicy() = default;

public:
    /**
     *  @brief 处理所有公共配置
    */
    template <typename C1>
    bool dealWithAllPublicConfig(C1 &container)
    {
        return static_cast<D *>(this)->dealWithAllPublicConfig_imp(container);
    }

    /**
     *  @brief 更新所有的配置
    */
    template <typename C1, typename C2>
    void updateAllConfig(C1 &c1, const C2 &c2)
    {
        static_cast<D *>(this)->updateAllConfig_imp(c1, c2);
    }

    /**
     *  @brief 处理item
    */
    template <typename C1, typename ITEM>
    bool dealWithItems(C1 &container, ITEM it)
    {
        static_cast<D *>(this)->dealWithItems_imp(container, it);
    }

    /**
     *  @brief 更新变化的配置
    */
    template <typename C1>
    bool updateChangedConfig(C1 &container, std::map<std::string, int> &changeMap)
    {
        return static_cast<D *>(this)->updateChangedConfig_imp(container, changeMap);
    }

    /**
     *  @brief 判断某一个配置是否存在
    */
    bool existConfig(const std::string &appid,
                     const std::string &ns,
                     const std::string &key)
    {
        return static_cast<D *>(this)->existConfig_imp(appid, ns, key);
    }

    /**
     *  @brief 获取配置
    */
    std::optional<std::string> getConfig(const std::string &appid,
                                         const std::string &ns,
                                         const std::string &key)
    {
        return static_cast<D *>(this)->getConfig_imp(appid, ns, key);
    }

    /**
     *  @brief 修改配置
    */
    template <typename V>
    bool modifyConfig(const std::string &appid,
                      const std::string &ns,
                      const std::string &key,
                      V &value)
    {
        return static_cast<D *>(this)->modifyConfig_imp(appid, ns, key, value);
    }

    /**
     *  @brief 新增配置
    */
    template <typename V>
    bool addConfig(const std::string &appid,
                   const std::string &ns,
                   const std::string &key,
                   V &value)
    {
        return static_cast<D *>(this)->addConfig_imp(appid, ns, key, value);
    }
};

} // namespace kanon

#endif